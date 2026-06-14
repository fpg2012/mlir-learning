// RUN: my-opt %s --mul-to-add-tg > %t
// Run: FileCheck %s < %t
func.func @power_of_two_plus_one(%arg: i32) -> i32 {
  %0 = arith.constant 31 : i32
  // CHECK-NOT: arith.muli
  %1 = arith.muli %arg, %0 : i32
  %2 = arith.addi %1, %0 : i32
  func.return %2 : i32
}