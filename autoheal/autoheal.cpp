//
// Created by a2fan on 11/28/2019.
//

#include "autoheal.h"
#include "../logging.h"

void update_unit(T_UNIT_VIEW *unit_view, T_MSG *msg) {
    if(unit_view){

        log("unit update");
        if(msg){

            if(msg->data_types & 1 != 0){
                log("update health");
            }
        }
    }
}

void  __declspec(noinline) __stdcall update_unit_wrapper_inner() {
    T_UNIT_VIEW *unit_view;
    T_MSG *message;
    __asm{
    mov     ecx,[ebp+8]
    //ecx points to a previous EBP

    mov     edx,[ecx- 148h]
    mov     unit_view, edx

    mov     edx,[ecx - 144h]
    mov     message, edx
    }
    update_unit(unit_view, message);
}
void  __declspec(noinline) __stdcall update_unit_wrapper_inner2() {
    T_UNIT_VIEW *unit_view;
    T_MSG *message;
    __asm{
    mov     ecx,[ebp+8]
    //ecx points to a previous EBP

    mov     edx,[ecx - 420h]
    mov     unit_view, edx

    mov     edx,[ecx - 41Ch]
    mov     message, edx
    }
    update_unit(unit_view, message);
}

void __declspec(naked) update_unit_wrapper() {
    // 00411048
    __asm
    {
    push    ebp
    }
//    update_unit_wrapper_inner();
    __asm
    {
    // restore ebp
    pop     ebp
    // execute rewritten opcodes
    mov     ecx,[ebp-148h]
    ret
    }
}

void __declspec(naked) update_unit_health_wrapper() {
    // 0040FD1F
    __asm
    {
    push    ebp
    }
//    update_unit_wrapper_inner();
    __asm
    {
    // restore ebp
    pop     ebp
    // execute rewritten opcodes
    mov     eax,[ebp-148h]
    ret
    }
}
void __declspec(naked) update_unit_health2_wrapper() {
    // 004130D5
    __asm
    {
    push    ebp
    }
    update_unit_wrapper_inner2();
    __asm
    {
    // restore ebp
    pop     ebp
    // execute rewritten opcodes
    mov     eax, [ebp-11BF0h]
    ret
    }
}
