#pragma once
#include "game_objects/game.h"

#define get_game_obj ((T_GAME *(*)())0x401870)
// #define get_list_item (T_INVENTORY_ITEM **__thiscall (*)(void *, int))0x421870)

int get_list_size(void * list);
T_INVENTORY_ITEM** get_list_item(void *list, int item);