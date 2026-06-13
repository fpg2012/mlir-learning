add_mlir_library(MulToAdd
    MulToAdd.cpp

    # ${PROJECT_SOURCE_DIR}/lib/Transform/Affine
    ADDITIONAL_HEADER_DIRS

    LINK_LIBS PUBLIC
)
