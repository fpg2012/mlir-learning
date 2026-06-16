#ifndef LIB_DIALECT_POLY_POLYTYPES_TD_
#define LIB_DIALECT_POLY_POLYTYPES_TD_
include "PolyDialect.td"
include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/BuiltinTypeInterfaces.td"

// class用于定义抽象类（不产生C++代码）
class Poly_Type<string name, string typeMnemonic> : TypeDef<Poly_Dialect, name> {
    let mnemonic = typeMnemonic; // 在IR中的名称
}

// def用于定义具体的类（会产生具体的C++代码）
// 定义 poly.poly 这个操作
def Polynomial : Poly_Type</* name */"Polynomial", /* typeMnemonic */"poly"> {
    let summary = "A polynomial with u32 coefficients";
    let description = [{
        A type for polynomial with integer coeffs in a single-var polynomial ring.
    }];

    //  多项式次数上界
    let parameters = (ins "int":$degreeBound);
    let assemblyFormat = "`<` $degreeBound `>`";
}

#endif // LIB_DIALECT_POLY_POLYTYPES_TD_