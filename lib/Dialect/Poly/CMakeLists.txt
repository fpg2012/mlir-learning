set(LLVM_TARGET_DEFINITIONS PolyDialect.td)
mlir_tablegen(PolyDialect.h.inc -gen-dialect-decls)
mlir_tablegen(PolyDialect.cpp.inc -gen-dialect-defs)
add_public_tablegen_target(PolyDialectTableGen)

set(LLVM_TARGET_DEFINITIONS PolyTypes.td)
mlir_tablegen(PolyTypes.h.inc -gen-typedef-decls)
mlir_tablegen(PolyTypes.cpp.inc -gen-typedef-defs)
add_public_tablegen_target(PolyTypesTableGen)

add_mlir_library(PolyDialect
    PolyDialect.cpp

    ADDITIONAL_HEADER_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}/..
    
    DEPENDS
    PolyDialectTableGen
    PolyTypesTableGen

    LINK_LIBS PUBLIC
)