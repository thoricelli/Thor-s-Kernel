project(kernel LANGUAGES C CXX ASM_NASM)

set(ISO_DIR ${CMAKE_BINARY_DIR}/isodir)
set(GRUB_CFG ${PROJECT_SOURCE_DIR}/grub.cfg)

set(
    SOURCES
    src/multiboot2/header.cpp
    src/multiboot2/boot.asm
    src/multiboot2/boot32.asm
    src/multiboot2/boot64.asm
    src/multiboot2/info/multiboot2_info.cpp
    
    src/drivers/vga/vga-text.cpp
    
    src/main.cpp
)

add_executable(kernel ${SOURCES})

target_include_directories(
    kernel PRIVATE ${PROJECT_SOURCE_DIR}/include
)

set_target_properties(kernel PROPERTIES 
    LINKER_LANGUAGE CXX
    LINK_DEPENDS ${PROJECT_SOURCE_DIR}/linker.ld
)

target_compile_options(kernel PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:-ffreestanding -fno-exceptions -fno-rtti -Wall -Wextra -g>
    $<$<COMPILE_LANGUAGE:C>:-ffreestanding -Wall -Wextra -g>
    $<$<COMPILE_LANGUAGE:ASM_NASM>:-g -F dwarf>
)

target_link_options(kernel PRIVATE
    -ffreestanding
    -nostdlib
    -T ${PROJECT_SOURCE_DIR}/linker.ld
)

target_link_libraries(kernel PRIVATE k)

if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
    set(GRUB_MKRESCUE_CMD wsl grub-mkrescue)
else()
    set(GRUB_MKRESCUE_CMD grub-mkrescue)
endif()

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/os.iso
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ISO_DIR}/boot/grub
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:kernel> ${ISO_DIR}/boot/kernel
    COMMAND ${CMAKE_COMMAND} -E copy ${GRUB_CFG} ${ISO_DIR}/boot/grub/grub.cfg
    COMMAND ${GRUB_MKRESCUE_CMD} -o os.iso isodir

    DEPENDS kernel ${GRUB_CFG}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(iso ALL DEPENDS ${CMAKE_BINARY_DIR}/os.iso)