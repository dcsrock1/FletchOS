#include "../../intf/IDT.h"
#include "../../intf/keyboard_driver.h"

extern void load_idt();
extern void keyboard_isr();

struct ID64 idt[256];

void init_IDT() {
    idt[0x21].offset_1 = (uint16_t)((uint64_t)&keyboard_isr & 0x000000000000FFFF);
    idt[0x21].selector = 0x08;  
    idt[0x21].ist = 0;
    idt[0x21].type_attributes = 0x8E;
    idt[0x21].offset_2 = (uint16_t)(((uint64_t)&keyboard_isr & 0x00000000FFFF0000) >> 16);
    idt[0x21].offset_3 = (uint32_t)(((uint64_t)&keyboard_isr & 0xFFFFFFFF00000000) >> 32);
    idt[0x21].zero = 0;
    load_idt();
}