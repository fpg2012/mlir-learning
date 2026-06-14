set(LLVM_TARGET_DEFINITIONS MulToAddTG.td)
mlir_tablegen(MulToAddTG.h.inc -gen-pass-decls)
add_public_tablegen_target(MulToAddTGIncGen)

add_mlir_library(MulToAdd
    MulToAdd.cpp

    ADDITIONAL_HEADER_DIRS
    ${CMAKE_CURRENT_BINARY_DIR}/..
    
    DEPENDS
    MulToAddTGIncGen

    LINK_LIBS PUBLIC
)