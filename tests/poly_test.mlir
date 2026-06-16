// RUN: my-opt %s

module {
    func.func @main(%arg0: !poly.poly<4>) -> !poly.poly<4> {
        return %arg0 : !poly.poly<4>
    }

    // CHECK-LABEL: test_add_syntax
    func.func @test_poly_syntax(%arg0: !poly.poly<10>, %arg1: !poly.poly<10>) -> i32 {
        // CHECK: poly.add
        %0 = poly.add %arg0, %arg1 : (!poly.poly<10>, !poly.poly<10>) -> !poly.poly<10>
        %1 = poly.mul %0, %0 : (!poly.poly<10>, !poly.poly<10>) -> !poly.poly<20>
        
        %3 = arith.constant dense<[1, 2, 3]> : tensor<3xi32>
        %4 = poly.from_tensor %3 : tensor<3xi32> -> !poly.poly<10>
        %5 = arith.constant 7 : i32
        // CHECK: poly.eval
        %6 = poly.eval %4, %5 : (!poly.poly<10>, i32) -> i32

        return %6 : i32
    }
}