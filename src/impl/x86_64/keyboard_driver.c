#include "../../intf/keyboard_driver.h"
#include "../../intf/stdio.h"
#include "../../intf/PIC_driver.h"
#include "../../intf/stddef.h"

void keyboard_handler() {
    PIC_sendEOI(1);

    printf("Hello from keyboard", 7);
    
}