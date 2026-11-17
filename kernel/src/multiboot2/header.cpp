#include <stdint.h>

// TODO: Move
#define MULTIBOOT2_HEADER_MAGIC 0xE85250D6

typedef enum multiboot2_architecture
{
    PROTECTED_I386,
    MIPS = 4,
};

typedef struct multiboot2_header
{
    uint32_t magic;
    uint32_t architecture;
    uint32_t header_length;
    uint32_t checksum;

    // TODO: Move
    uint16_t type;
    uint16_t flag;
    uint32_t size;
} multiboot2_header_t;

__attribute__((section(".multiboot"), used))
const multiboot2_header header = {
    .magic = MULTIBOOT2_HEADER_MAGIC,
    .architecture = multiboot2_architecture::PROTECTED_I386,
    .header_length = sizeof(header),
    .checksum = -(MULTIBOOT2_HEADER_MAGIC + multiboot2_architecture::PROTECTED_I386 + sizeof(header)),

    .type = 0,
    .flag = 0,
    .size = 8,
};