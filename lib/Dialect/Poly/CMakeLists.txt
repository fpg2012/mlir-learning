set(LLVM_TARGET_DEFINITIONS PolyDialect.td)
mlir_tablegen(PolyDialect.h.inc -gen-dialect-decls)
mlir_tablegen(PolyDialect.cpp.inc -gen-dialect-defs)
add_public_tablegen_target(PolyDialectTableGen)

add_mlir_library(PolyDialect
    PolyDialect.cpp

    ADDITIONAL_HEADER_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}/..
    
    DEPENDS
    PolyDialectTableGen

    LINK_LIBS PUBLIC
)