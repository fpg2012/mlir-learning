#include "lib/Transform/Affine/AffineFullUnroll2.h"
#include "lib/Transform/Affine/AffineFullUnrollPattern.h"
#include "lib/Transform/Affine/AffineFullUnrollPattern.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

namespace mlir {
namespace my_opt {

void AffineFullUnrollPass2::runOnOperation() {
    mlir::RewritePatternSet patterns(&getContext());
    patterns.add<AffineFullUnrollPattern>(&getContext());

    (void)applyPatternsGreedily(getOperation(), std::move(patterns));
}

}
}