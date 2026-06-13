#include "lib/Transform/Affine/AffineFullUnrollPattern.h"

namespace mlir {
namespace my_opt {

llvm::LogicalResult AffineFullUnrollPattern::matchAndRewrite(AffineForOp op, PatternRewriter &rewriter) const {
    return affine::loopUnrollFull(op);
}

}
}