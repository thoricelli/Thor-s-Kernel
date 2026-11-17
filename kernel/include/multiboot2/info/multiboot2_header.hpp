// https://www.gnu.org/software/grub/manual/multiboot2/multiboot.html#Boot-information-format

#pragma once

#include "multiboot2/info/multiboot2.h"
#include <stdint.h>

struct multiboot_start
{
    int32_t total_size;
    int32_t reserved;
};

enum MULTIBOOT_TAG
{
    END,
    CMDLINE,
    BOOT_LOADER_NAME,
    MODULES,
    BASIC_MEMINFO,
    BOOTDEV,
    MMAP,
    VBE,
    FRAMEBUFFER,
    ELF_SECTIONS,
    APM,
    EFI32,
    EFI64,
    SMBIOS,
    ACPI_OLD,
    ACPI_NEW,
    NETWORK,
    EFI_MMAP,
    EFI_BS,
    EFI32_IH,
    EFI64_IH,
    LOAD_BASE_ADDR,
};

class MultibootTwoInfo
{
private:
    inline static intptr_t tagLocations[LOAD_BASE_ADDR + 1] = {0};

public:
    static void Parse(void *boot_information);

    /**
     * @return If the tag exists in the header.
     */
    static bool HasTag(MULTIBOOT_TAG tag);

    static void *GetTag(MULTIBOOT_TAG tag);
};