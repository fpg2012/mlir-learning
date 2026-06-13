#pragma once

#include "mlir/Pass/Pass.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"

namespace mlir {
namespace my_opt {

using affine::AffineForOp;

struct AffineFullUnrollPattern : public OpRewritePattern<affine::AffineForOp> {
    AffineFullUnrollPattern(mlir::MLIRContext *context) : OpRewritePattern<affine::AffineForOp>(context, 1) {

    }

    llvm::LogicalResult matchAndRewrite(AffineForOp op, PatternRewriter &writer) const override;
};

}
}