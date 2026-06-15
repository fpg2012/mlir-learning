#pragma once

#include "lib/Dialect/Poly/PolyDialect.h"
#include "lib/Dialect/Poly/PolyTypes.h"
#include "mlir/include/mlir/IR/BuiltinOps.h"
#include "mlir/include/mlir/IR/BuiltinTypes.h"
#include "mlir/include/mlir/IR/Dialect.h"

#define GET_OP_CLASSES
#include "lib/Dialect/Poly/PolyOps.h.inc"