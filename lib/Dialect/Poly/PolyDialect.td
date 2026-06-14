include "mlir/IR/DialectBase.td"

// 定义 poly 方言
def Poly_Dialect : Dialect {
    let name = "poly";
    let summary = "A dialect for polynomial math";
    let description = [{
        Just a simple dialect for polynomial math.
    }];
    let cppNamespace = "::mlir::my_opt::poly";

    let useDefaultTypePrinterParser = 1;
}