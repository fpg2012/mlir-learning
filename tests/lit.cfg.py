# lit.cfg.py — lit 测试套件的配置
# 这个文件被 lit.site.cfg.py（CMake 生成）加载，
# 它定义：测什么文件、用哪个测试格式、去哪里找可执行文件

import os
import lit.formats
from lit.llvm import llvm_config

# ---- 测试套件基本信息 ----
config.name = "MY_OPT"
# ShTest 格式：测试文件里 "// RUN: <command>" 会被逐行当成 shell 命令执行
config.test_format = lit.formats.ShTest(not llvm_config.use_lit_shell)
# 只把 .mlir 后缀的文件当成测试
config.suffixes = [".mlir"]

# ---- 路径设定 ----
# 测试源码目录（你写的 .mlir 文件在这里）
config.test_source_root = os.path.dirname(__file__)
# 测试执行根目录（CMake 生成的文件在这里）
config.test_exec_root = os.path.join(config.project_binary_dir, "tests")

# ---- 告诉 lit 去哪里找可执行文件 ----
# my-opt 是我们的编译产物，在 build/tools 下
build_tools_dir = os.path.join(config.project_binary_dir, "tools")
# FileCheck, mlir-opt 等是 LLVM 自带工具，在 llvm_tools_dir 下
llvm_tools_dir = config.llvm_tools_dir

llvm_config.add_tool_substitutions(
    ["my-opt"],
    [build_tools_dir]
)
llvm_config.add_tool_substitutions(
    ["mlir-opt", "mlir-runner", "FileCheck", "count", "not"],
    [llvm_tools_dir]
)

# ---- 排除不需要的目录 ----
config.excludes = ["Inputs", "CMakeLists.txt"]
