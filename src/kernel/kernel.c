#include <stdint.h>
#include <stdbool.h>
#include "gdt/gdt.h"
#include "kernel/kernel-entrypoint.h"
#include "framebuffer/portio.h"
#include "framebuffer/framebuffer.h"
#include "interrupt/idt.h"
#include "interrupt/interrupt.h"
// #include "keyboard/keyboard.h"


void kernel_setup(void) {
    /*
    uint32_t a;
    uint32_t volatile b = 0x0000BABE;
    __asm__("mov $0xCAFE0000, %0" : "=r"(a));
    while (TRUE) b += 1;
    */
   
    // load_gdt(&_gdt_gdtr);
    // while (true);
    
    // framebuffer_clear();
    // framebuffer_write(3, 8,  'H', 0, 0xF);
    // framebuffer_write(3, 9,  'a', 0, 0xF);
    // framebuffer_write(3, 10, 'i', 0, 0xF);
    // framebuffer_write(3, 11, '!', 0, 0xF);
    // framebuffer_set_cursor(3, 10);
    // while (true);
    

    load_gdt(&_gdt_gdtr);
    pic_remap();
    initialize_idt();
    framebuffer_clear();
    framebuffer_write(0, 0, 'x', 0, 0xF);
    framebuffer_set_cursor(0, 0);
    __asm__("int $0x4");
    while (true);
        
    // int col = 0;
    // keyboard_state_activate();
    // while (true) {
    //      char c;
    //      get_keyboard_buffer(&c);
    //      framebuffer_write(0, col++, c, 0xF, 0);
    // }


}