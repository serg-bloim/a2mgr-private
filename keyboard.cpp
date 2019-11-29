#pragma optimize("g", off)
#include "logging.h"
#include "game_utils.h"
#include "extended_hotkeys_config.h"
#include <cstdio>
#include <iostream>
#include <string>
#include "game_objects/inv.h"
#include "game_objects/game.h"
#include <sstream>
#include <iomanip>
#include "hotkey_config/GeneralConfig.h"

using namespace std;
int __declspec(noinline) keyboard_handle_extra_keys(int key)
{
    if(key ==75){
        gConf.reload();
    }
    char buffer[100];
    sprintf(buffer, "key code is %d", key);
    log(buffer);
    T_GAME *game = get_game_obj();
    if(key == 74){
        bytearr potionSignature = gConf.potionHealthSmall();
//        log
        int ind = game->inventory->find_item(potionSignature);
        log(ind);
    }
    if (game)
    {
        sprintf(buffer, "game addr is 0x%08X", game);
//        log(buffer);
        if (game->inventory)
        {
            sprintf(buffer, "game->inventory addr is 0x%08X", game->inventory);
//            log(buffer);
            if (game->inventory->item_list)
            {
                sprintf(buffer, "game->inventory->item_list addr is 0x%08X", game->inventory->item_list);
//                log(buffer);

                int size = get_list_size(game->inventory->item_list);
                for (int i = 0; i < size; i++)
                {
                    __asm{
                        nop
                        nop
                        nop
                    }
                    T_INVENTORY_ITEM **itemNode = get_list_item((void *)game->inventory->item_list, i);
                    T_INVENTORY_ITEM *item = *itemNode;
                    bytearr data;
                    for (int j = 0; j < item->data_size; j++)
                    {
                        data.push_back(item->data[j]);
                    }

                    if (is_hotkey_present(key, data))
                    {
                        stringstream ss;
                        ss << "hotkey " << key << " matches item '" << toHex(data) << " ; " << toHex2(data);
                        log(ss.str());
                        int gear_type = item->getTypeWrapper();
                        sprintf(buffer, "gearType = %d", gear_type);
                        log(buffer);
                        item = put_on_inventory_item(game->inventory, i, 1);
                        if ( item )
                        {
//                            log("debug");
                            game->pdwordE0->method7C(gear_type-1);
                        }
                    }else if(key == 75){
                        stringstream ss;
                        int gear_type = item->getTypeWrapper();
                        ss << "item type (" << gear_type << ") " << toHex(data) << " ; " << toHex2(data);
                        log(ss.str());
                    }
                }
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
    __asm {
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
