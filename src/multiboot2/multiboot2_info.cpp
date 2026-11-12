#include "multiboot2/multiboot2_header.hpp"
#include "stddef.h"

void MultibootTwoInfo::Parse(void *bootInformation)
{
    auto bootptr = static_cast<uint8_t *>(bootInformation);

    // Skip header
    bootptr += sizeof(multiboot_start);

    // Individual tags
    // Find and push addresses to list by its tag.
    multiboot_header_tag *header = static_cast<multiboot_header_tag *>((void *)bootptr);

    while (header->type != MULTIBOOT_TAG::END)
    {
        MultibootTwoInfo::tagLocations[header->type] = (intptr_t)header;

        // Multiboot headers are 8-byte aligned.
        bootptr = (uint8_t *)((uintptr_t)(bootptr + header->size + 7) & (~0x7));

        header = static_cast<multiboot_header_tag *>((void *)bootptr);
    }
}

bool MultibootTwoInfo::HasTag(MULTIBOOT_TAG tag)
{
    return MultibootTwoInfo::tagLocations[tag] != (intptr_t)NULL;
}

void *MultibootTwoInfo::GetTag(MULTIBOOT_TAG tag)
{
    return (void *)MultibootTwoInfo::tagLocations[tag];
}