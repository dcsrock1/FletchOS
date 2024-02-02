#include "../../intf/stdio.h"
#include "../../intf/stddef.h"

void printf(const char* string, int colour) {
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}

void clear() {
    volatile char *video = (volatile char*)0xB8000;
    for (int i = 0; i < 80 * 25; i++) {
        video[i * 2] = ' ';  
        video[i * 2 + 1] = 0x07;  
    }
}

void outb(unsigned short port, unsigned char data) {
    asm volatile ("outb %0, %1" : : "a"(data), "Nd"(port));
}

uint8_t inb(unsigned short port) {
    uint8_t result;
    asm volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

void io_wait() {
    asm volatile ("outb %%al, $0x80" : : "a"(0));
}