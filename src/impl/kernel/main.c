#include "../../intf/stdio.h"
#include "../../intf/PIC_driver.h"
#include "../../intf/IDT.h"


void kernel_main() {
    clear();
    printf("System booted into 64 bit mode", 7);
    init_PIC(0x20, 0x28);
    init_IDT();
    outb(PIC1_DATA, 0xFD);
    outb(PIC2_DATA, 0xFF);
    printf("ROOT", 7);
    while(1);
}