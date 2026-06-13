get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)

set(LIBS
    AffineFullUnroll
    MulToAdd
    MLIRRegisterAllDialects
    MLIRMlirOptMain
    ${dialect_libs}
    ${conversion_libs}
)

add_llvm_executable(my-opt my-opt.cpp)

llvm_update_compile_flags(my-opt)
target_link_libraries(my-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(my-opt)