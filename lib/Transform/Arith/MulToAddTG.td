include "mlir/Pass/PassBase.td"

def MulToAddTG : Pass<"mul-to-add-tg", "mlir::func::FuncOp"> {
  let summary = "Mul to add defined by table gen";
  let description = [{
    Mul to add defined by table gen
  }];
  let dependentDialects = ["mlir::arith::ArithDialect"];
}