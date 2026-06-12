# 用 CMake 变量替换 lit.site.cfg.py.in 里的 @VAR@，生成 lit.site.cfg.py
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
    ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
    @ONLY
)

# 定义 lit 测试目标：make check-my-opt 即可运行所有测试
add_lit_testsuite(check-my-opt "Running the my-opt regression tests"
    ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        FileCheck count not
        my-opt
        mlir-opt
)