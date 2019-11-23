#pragma optimize( "g", off )
#include "logging.h"
#include "game_utils.h"
#include <cstdio>
#include <iostream>
#include <string>

// typedef int* (*funptr)();

int __declspec(noinline) keyboard_handle_extra_keys(int key)
{
    
    char buffer[100];
    T_GAME* game = get_game_obj();
    if(game){
        sprintf(buffer, "game addr is %08X", game);
        log(buffer);
        if(game->inventory){
            sprintf(buffer, "game->inventory addr is %08X", game->inventory);
            log(buffer);
            if(game->inventory->item_list){
                sprintf(buffer, "game->inventory->item_list addr is %08X", game->inventory->item_list);
                log(buffer);
                int size = 0;
                size = get_list_size(game->inventory->item_list);

                sprintf(buffer, "inventory size is %d", size);
                log(buffer);
            }
        }
    }
    
    return (int)game;
}

void __stdcall keyboard_handle_extra_keys_wrapper_inner()
{
  int key;
  int b;
  __asm{
      mov       ecx, [ebp+8h]
      mov       ecx, [ecx + 8]
      mov       key, ecx
      mov       key, ecx
  }
  keyboard_handle_extra_keys(key);
}
void __declspec(naked) keyboard_handle_extra_keys_wrapper()
{
    __asm
    {
        push    ebp
        mov     ebp, esp
    }
    keyboard_handle_extra_keys_wrapper_inner();
	__asm
	{
        pop     ebp
        mov     ecx, [ebp+8h]
        mov     [ebp-18h], ecx
        ret
	}
}

