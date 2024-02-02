global long_mode_start
global load_idt
global keyboard_isr
global idt_descripter
extern DATA_SEG
extern kernel_main
extern idt
extern keyboard_handler
bits 64
section .text
error_hang:
    hlt
    jmp error_hang
%macro PUSHALL 0
    push rax
    push rcx
    push rdx
    push r8
    push r9
    push r10
    push r11
%endmacro
%macro POPALL 0
    pop rax
    pop rcx
    pop rdx
    pop r8
    pop r9
    pop r10
    pop r11
%endmacro
    
idt_descripter:
    dw 4095
    dq idt

load_idt:      
    lidt    [idt_descripter]    
    sti      
    ret

keyboard_isr:
    PUSHALL
    cld
    call keyboard_handler
    POPALL
    iret


long_mode_start:
    mov    ax, DATA_SEG
    mov    ss, ax
    mov    ds, ax
    mov    es, ax
    mov    fs, ax
    mov    gs, ax
    call kernel_main
    INT 0x21
    hlt