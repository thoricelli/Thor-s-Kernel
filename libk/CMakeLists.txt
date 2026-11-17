project(k LANGUAGES C CXX)

set(
    SOURCES
    src/memory.c
    src/string.c
)

add_library(k STATIC ${SOURCES})

target_include_directories(
    k PUBLIC ${PROJECT_SOURCE_DIR}/include
    k PRIVATE ${PROJECT_SOURCE_DIR}/src
)

target_compile_options(k PRIVATE -ffreestanding -nostdlib -g)