#ifndef LIB_DIALECT_POLY_POLYOPS_TD_
#define LIB_DIALECT_POLY_POLYOPS_TD_
include "PolyDialect.td"
include "PolyTypes.td"
include "mlir/IR/OpBase.td"
include "mlir/IR/CommonTypeConstraints.td"

class Poly_BinOp<string mnemonic> : Op<Poly_Dialect, mnemonic> {
    let summary = "Op between 2 polynomials";
    let arguments = (ins Polynomial:$lhs, Polynomial:$rhs);
    let results = (outs Polynomial:$output);
    let assemblyFormat = "$lhs `,` $rhs attr-dict `:` `(` type($lhs) `,` type($rhs) `)` `->` type($output)";
}

def Poly_AddOp : Poly_BinOp<"add"> {
    let summary = "Add op between 2 polynomials";
}

def Poly_MulOp : Poly_BinOp<"mul"> {
    let summary = "Mul between 2 polynomials";
}

def Poly_FromTensorOp : Op<Poly_Dialect, "from_tensor"> {
    let summary = "Create a polynomial from integer coeffs in a tensor";
    let arguments = (ins TensorOf<[AnyInteger]>:$input);
    let results = (outs Polynomial:$result);
    let assemblyFormat = "$input attr-dict `:` type($input) `->` type($result)";
}

def Poly_EvalOp : Op<Poly_Dialect, "eval"> {
    let summary = "Eval the polynomial at give point";
    let arguments = (ins Polynomial:$input, AnyInteger:$point);
    let results = (outs AnyInteger:$output);
    let assemblyFormat = "$input `,` $point attr-dict `:` `(` type($input) `,` type($point) `)` `->` type($output)";
}

#endif // LIB_DIALECT_POLY_POLYOPS_TD_