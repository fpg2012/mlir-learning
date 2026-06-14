// RUN: my-opt %s

module {
    func.func @main(%arg0: !poly.poly<4>) -> !poly.poly<4> {
        return %arg0 : !poly.poly<4>
    }
}