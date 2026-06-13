#pragma once

#include "lib/Transform/Affine/AffineFullUnrollPattern.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

namespace mlir {
namespace my_opt {

class AffineFullUnrollPass2 : public PassWrapper<AffineFullUnrollPass2, OperationPass<mlir::func::FuncOp>> {
    void runOnOperation() override;

    StringRef getArgument() const final {
        return "affine-full-unroll-rewrite";
    }

    StringRef getDescription() const final {
        return "Fully unroll all affine loops";
    }
};

}
}