//
// Created by a2fan on 11/24/2019.
//

#include <stack>

__declspec(naked) int ths_wrapper(const void * fptr){
    __asm{
    push    ebp
    mov     ebp, esp
    mov     edx, fptr
    pop     ebp
    add     esp, 8 // removing ths_wrapper's return address and fptr parameter from stack
    pop     ecx
    pop     ebp
//    mov     esp, ebp
    jmp     edx
    }
}