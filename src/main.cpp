#include "drivers/vga/vga-text.hpp"
#include "multiboot2/multiboot2_header.hpp"

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

extern "C" void kernel_main(void *bootInformation)
{
    MultibootTwoInfo::Parse(bootInformation);

    auto meminfo = static_cast<multiboot_tag_basic_meminfo *>(MultibootTwoInfo::GetTag(MULTIBOOT_TAG::BASIC_MEMINFO));

    /**
     * TODO: (In order of priority)
     * 1. We have a frame buffer we can draw to. -> TODO: Glyph drawing, so we can display text.
     * 2. We have the SMBIOS to access what hardware devices are present -> TODO: Implement keyboard input
     * 3. We now know the physical memory boundaries -> TODO: a proper memory manager.
     */

    vga_test();

    return;
}