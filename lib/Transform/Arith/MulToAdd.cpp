#include "lib/Transform/Arith/MulToAdd.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

namespace mlir {
namespace my_opt {

void MulToAddPass::runOnOperation() {
    mlir::RewritePatternSet patterns(&getContext());
    patterns.add<PeelFromMulPattern>(&getContext());
    patterns.add<PowerOfTwoExpandPattern>(&getContext());

    (void)applyPatternsGreedily(getOperation(), std::move(patterns));
}

llvm::LogicalResult PowerOfTwoExpandPattern::matchAndRewrite(arith::MulIOp op, PatternRewriter &rewriter) const {
    // 假设标准化之后，会确保const放在后
    Value lhs = op->getOperand(0);
    Value rhs = op->getOperand(1);

    // 看是不是const
    auto rhsDefOp = rhs.getDefiningOp<arith::ConstantIntOp>();
    if (!rhsDefOp) {
        return llvm::failure();
    }

    int64_t rhs_value = rhsDefOp.value();
    bool is_power_of_two = (rhs_value & (rhs_value - 1)) == 0;
    if (!is_power_of_two) {
        return llvm::failure();
    }

    auto new_constant = arith::ConstantOp::create(
        rewriter,
        rhsDefOp->getLoc(),
        rewriter.getIntegerAttr(rhs.getType(), rhs_value / 2)
    );
    auto new_mul = arith::MulIOp::create(
        rewriter,
        op.getLoc(),
        lhs,
        new_constant
    );
    auto new_add = arith::AddIOp::create(
        rewriter,
        op.getLoc(),
        new_mul,
        new_mul
    );

    rewriter.replaceOp(op, new_add);

    return llvm::success();
}

llvm::LogicalResult PeelFromMulPattern::matchAndRewrite(arith::MulIOp op, PatternRewriter &rewriter) const {
    Value lhs = op.getOperand(0), rhs = op->getOperand(1);
    auto rhsDefOp = rhs.getDefiningOp<arith::ConstantIntOp>();
    if (!rhsDefOp) {
        return llvm::failure();
    }

    // 假设标准化之后，rhs是正数
    int64_t rhs_value = rhsDefOp.value();
    
    auto new_const = arith::ConstantOp::create(
        rewriter,
        rhsDefOp.getLoc(),
        rewriter.getIntegerAttr(rhs.getType(), rhs_value - 1)
    );
    auto new_mul = arith::MulIOp::create(
        rewriter,
        op->getLoc(),
        lhs,
        new_const
    );
    auto new_add = arith::AddIOp::create(
        rewriter,
        op.getLoc(),
        new_mul,
        lhs
    );

    rewriter.replaceOp(op, new_add);

    return llvm::success();
}

#define GEN_PASS_DEF_MULTOADDTG
#include "lib/Transform/Arith/MulToAddTG.h.inc"

class MulToAddTGPass : public impl::MulToAddTGBase<MulToAddTGPass> {
public:
    void runOnOperation() override;
};

void MulToAddTGPass::runOnOperation() {
    mlir::RewritePatternSet patterns(&getContext());
    patterns.add<PeelFromMulPattern>(&getContext());
    patterns.add<PowerOfTwoExpandPattern>(&getContext());

    (void)applyPatternsGreedily(getOperation(), std::move(patterns));
}

}
}