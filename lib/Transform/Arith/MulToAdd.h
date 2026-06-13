#pragma once

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace my_opt {

struct PowerOfTwoExpandPattern : public OpRewritePattern<arith::MulIOp> {
    PowerOfTwoExpandPattern(mlir::MLIRContext *context) : OpRewritePattern<arith::MulIOp>(context, 2) {

    }

    llvm::LogicalResult matchAndRewrite(arith::MulIOp op, PatternRewriter &rewriter) const override;
};

struct PeelFromMulPattern : public OpRewritePattern<arith::MulIOp> {
    PeelFromMulPattern(mlir::MLIRContext *context) : OpRewritePattern<arith::MulIOp>(context, 1) {

    }

    llvm::LogicalResult matchAndRewrite(arith::MulIOp op, PatternRewriter &rewriter) const override;
};

class MulToAddPass : public PassWrapper<MulToAddPass, OperationPass<mlir::func::FuncOp>> {
    void runOnOperation() override;

    StringRef getArgument() const final {
        return "mul-to-add";
    }

    StringRef getDescription() const final {
        return "mul to add";
    }
};

}
}