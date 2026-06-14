include "mlir/IR/DialectBase.td"

def Poly_Dialect : Dialect {
    let name = "poly";
    let summary = "A dialect for polynomial math";
    let description = [{
        Just a simple dialect for polynomial math.
    }];
    let cppNamespace = "::mlir::my_opt::poly";
}