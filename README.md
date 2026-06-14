# Simple Toy MLIR Project

## Build

1. Create a soft-link to [llvm-project](https://github.com/llvm/llvm-project)

    ```
    mkdir externals && cd externals
    ln -s ${PATH_TO_LLVM} llvm-project
    ```

2. Build

    ```
    mkdir build && cd build

    cmake .. \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DMLIR_DIR=${PATH_TO_LLVM}/build/lib/cmake/mlir \
    -DLLVM_DIR=${PATH_TO_LLVM}/build/lib/cmake/llvm

    make
    ```

3. If you use vscode with clangd, create a soft-link to `compile_commands.json` inside `build` directory

    ```
    ln -s build/compile_commmands.json .
    ```