#include "lib/Transform/Affine/AffineFullUnroll2.h"
#include "lib/Transform/Affine/AffineFullUnrollPattern.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"

namespace mlir {
namespace my_opt {

void AffineFullUnrollPass2::runOnOperation() {
    mlir::RewritePatternSet patterns(&getContext());
    patterns.add<AffineFullUnrollPattern>(&getContext());

    (void)applyPatternsGreedily(getOperation(), std::move(patterns));
}

}
}