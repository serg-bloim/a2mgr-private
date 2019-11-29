//
// Created by a2fan on 11/28/2019.
//

#include "autoheal.h"
#include "../logging.h"
#include <sstream>
#include "../game_utils.h"

void update_unit(T_GAME *game, T_UNIT_VIEW *unit_view, T_MSG *msg) {

    if (unit_view) {
        char buffer[100];
        sprintf(buffer, "unit_view addr is 0x%08X", unit_view);
//        log(buffer);
        if (msg) {
            char buffer[100];
            sprintf(buffer, "msg addr is 0x%08X", msg);
//            log(buffer);

            if (msg->msgType == 112 + 3) {
                log("update health");
                if (unit_view->health < 50) {
                    log("low health");
                    __int16 inv_item_ind = 1;
                    for (int i = 0; i < 5; i++) {
                        game->dwordD0->applyInventoryItem(2, inv_item_ind, 1, 0xE, 1);
                    }
                }
            }
        }
    }
}

void __declspec(noinline) __stdcall update_unit_wrapper_inner() {
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
    update_unit((T_GAME *)0, unit_view, message);
}

void __declspec(noinline) __stdcall update_unit_wrapper_inner2() {
    T_UNIT_VIEW *unit_view;
    T_MSG *message;
    T_GAME *game;
    __asm{
    mov     ecx,[ebp+8]
    //ecx points to a previous EBP

    mov     edx,[ecx - 420h]
    mov     unit_view, edx

    mov     edx,[ecx - 41Ch]
    mov     message, edx

    mov     edx,[ecx - 14h]
    mov     game, edx
    }
    update_unit(game, unit_view, message);
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
    mov     eax,[ebp-11BF0h]
    ret
    }
}
