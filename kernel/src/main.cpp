#include "drivers/vga/vga-text.hpp"
#include "multiboot2/info/multiboot2_header.hpp"

#include <string.h>

void vga_test()
{
    VGAText::SetColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    VGAText::WriteLine("Hello world!");
    VGAText::WriteLine("This kernel is not yet implemented, so your CPU will halt for now :)");

    VGAText::NextLine();
    VGAText::WriteLine("This VGA text will be replaced with a framebuffer in the future.\nBelow is just a blink test.");
    VGAText::NextLine();

    VGAText::PutChar('>');

    // Doesn't work on QEMU...
    VGAText::SetBlink(true);
    VGAText::PutChar('_');
    VGAText::SetBlink(false);
}

extern "C" void kernel_main(void *boot_information)
{
    MultibootTwoInfo::Parse(boot_information);

    auto meminfo = static_cast<multiboot_tag_basic_meminfo *>(MultibootTwoInfo::GetTag(MULTIBOOT_TAG::BASIC_MEMINFO));

    vga_test();

    char buffer[33];

    VGAText::WriteLine(itoa(912648875, buffer, 10));

    return;
}