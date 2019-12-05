//
// Created by a2fan on 11/28/2019.
//

#include "autoheal.h"
#include "../logging.h"
#include <sstream>
#include "../game_utils.h"
#include "../hotkey_config/GeneralConfig.h"

int autoheal_potion_queue = 0;

void handle_autoheal_event() {
    if(autoheal_potion_queue > 0) {
        T_GAME *game = get_game_obj();
        std::stringstream ss;
        ss << "Sending a small potion request. Queue is " << autoheal_potion_queue;
        log(ss.str());
        autoheal_potion_queue--;
        bytearr potionSignature = gConf.getAutoHealPotionType() == 1 ? gConf.potionHealthBig() : gConf.potionHealthSmall();
        int ind = game->inventory->find_item(potionSignature);
        game->dwordD0->applyInventoryItem(2, ind, 1, 0xE, 1);
    }
}

void __declspec(naked) handle_autoheal_event_wrapper() {
    __asm{
    mov      [ebp-11BF4h], edx
    }
    handle_autoheal_event();
    __asm{
    ret
    }
}

void update_unit(T_GAME *game, T_UNIT_VIEW *unit_view, T_MSG *msg) {

    if (unit_view && unit_view->isMainUnit()) {
        char buffer[100];
        if (msg) {
            char buffer[100];

            if (msg->msgType == 112 + 3) {
                int lowBoundary = min(gConf.getAutoHealLowBoundary(), unit_view->maxHealth);
                int highBoundary = min(gConf.getAutoHealHighBoundary(), unit_view->maxHealth);
                log("dmg hit message");
                log(unit_view->health);
                highBoundary = max(highBoundary, lowBoundary);
                if (unit_view->health < lowBoundary) {
                    int diff = highBoundary - unit_view->health;
                    int potionSize = gConf.getAutoHealPotionType() == 1 ? 100 : 30;
                    int num = ceilingDiv(diff, potionSize);
                    std::stringstream ss;
                    ss << "unit(" << std::hex << unit_view << std::dec << ") is low on health " << unit_view->health
                       << " out of " << unit_view->maxHealth
                       << ". Crossed low boundary " << lowBoundary << " increasing to " << highBoundary
                       << " with " << num << " potions(" << gConf.getAutoHealPotionType() << ")";
                    log(ss.str());
                    autoheal_potion_queue = num;
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
    update_unit((T_GAME *) 0, unit_view, message);
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
