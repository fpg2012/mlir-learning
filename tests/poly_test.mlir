// RUN: my-opt %s

module {
    func.func @main(%arg0: !poly.poly<4>) -> !poly.poly<4> {
        return %arg0 : !poly.poly<4>
    }

    // CHECK-LABEL: test_add_syntax
    func.func @test_add_syntax(%arg0: !poly.poly<10>, %arg1: !poly.poly<10>) -> !poly.poly<10> {
        // CHECK: poly.add
        %0 = poly.add %arg0, %arg1 : (!poly.poly<10>, !poly.poly<10>) -> !poly.poly<10>
        return %0 : !poly.poly<10>
    }
}