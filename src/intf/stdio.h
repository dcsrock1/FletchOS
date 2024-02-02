#ifndef __PRINT_H__
#define __PRINT_H__
#include "stddef.h"

uint8_t inb(unsigned short port);
void outb(unsigned short port, unsigned char data);
void io_wait();
void printf(const char *string, int colour);
void clear();

#endif