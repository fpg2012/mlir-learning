#include "lib/Transform/Affine/AffineFullUnroll.h"
#include "lib/Transform/Affine/AffineFullUnroll2.h"
#include "lib/Transform/Arith/MulToAdd.h"
#include "lib/Dialect/Poly/PolyDialect.h"
#include "mlir/include/mlir/InitAllDialects.h"
#include "mlir/include/mlir/Pass/PassRegistry.h"
#include "mlir/include/mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
    mlir::DialectRegistry registry;
    registry.insert<mlir::my_opt::poly::PolyDialect>();
    mlir::registerAllDialects(registry);

    mlir::PassRegistration<mlir::my_opt::AffineFullUnrollPass>();
    mlir::PassRegistration<mlir::my_opt::AffineFullUnrollPass2>();
    mlir::PassRegistration<mlir::my_opt::MulToAddPass>();
    mlir::my_opt::registerMulToAddTGPass();

    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "Tutorial Pass Driver", registry)
    );
}