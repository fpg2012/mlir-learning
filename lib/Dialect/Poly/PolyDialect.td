#ifndef LIB_DIALECT_POLY_POLYDIALECT_TD_
#define LIB_DIALECT_POLY_POLYDIALECT_TD_
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

#endif // LIB_DIALECT_POLY_POLYDIALECT_TD_