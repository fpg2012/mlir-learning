#pragma once

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace my_opt {

class AffineFullUnrollPass : public PassWrapper<AffineFullUnrollPass, OperationPass<mlir::func::FuncOp>> {
    void runOnOperation() override;

    StringRef getArgument() const final {
        return "affine-full-unroll";
    }

    StringRef getDescription() const final {
        return "Fully unroll all affine loops";
    }
};

}
}