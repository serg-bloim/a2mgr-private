#pragma once
#include "game_objects/game.h"
#include <stack>

#define get_game_obj ((T_GAME *(*)())0x401870)
// #define get_list_item (T_INVENTORY_ITEM **__thiscall (*)(void *, int))0x421870)

int get_list_size(void * list);
T_INVENTORY_ITEM** get_list_item(void *list, int item);
T_INVENTORY_ITEM* put_on_inventory_item(T_INVENTORY *inv, int ind, signed int a2);


//std::stack<_DWORD> returns;
//void __stdcall push_return(_DWORD addr){
//    returns.push(addr);
//}
//_DWORD __stdcall pop_return(){
//    return returns.pop();
//}
