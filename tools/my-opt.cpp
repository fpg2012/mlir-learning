#include "lib/Transform/Affine/AffineFullUnroll.h"
#include "lib/Transform/Affine/AffineFullUnroll2.h"
#include "mlir/include/mlir/InitAllDialects.h"
#include "mlir/include/mlir/Pass/PassRegistry.h"
#include "mlir/include/mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
    mlir::DialectRegistry registry;
    mlir::registerAllDialects(registry);

    mlir::PassRegistration<mlir::my_opt::AffineFullUnrollPass>();
    mlir::PassRegistration<mlir::my_opt::AffineFullUnrollPass2>();

    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "Tutorial Pass Driver", registry)
    );
}