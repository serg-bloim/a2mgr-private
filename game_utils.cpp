#include "game_utils.h";

// (void __cdecl (*)()) get_game_obj=(void __cdecl (*)()) 0x00401870;
// void __cdecl (*get_game_obj)() =(void __cdecl (*)()) 0x00401870;
// int* (* get_game_obj)() = (int *(*)())0x401870;

int get_list_size(void * list){
    int res;
    __asm
    {
        mov     ecx, list
        mov     edx, 0x4217E0
        call    edx
        mov     res, eax
    }
    return res;
}

T_INVENTORY_ITEM** get_list_item(void * list, int item){
    void * res;
    __asm
    {
        mov     ecx, list
        mov     edx, item
        push    edx
        mov     edx, 0x421870
        call    edx
        mov     res, eax
    }
    return (T_INVENTORY_ITEM **)res;
}