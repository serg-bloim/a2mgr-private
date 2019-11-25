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

T_INVENTORY_ITEM* put_on_inventory_item(T_INVENTORY *inv, int ind, signed int a2){
    T_INVENTORY_ITEM * res;
    __asm
    {
    mov     ecx, inv
    push    edx
    mov     edx, a2
    push    edx
    mov     edx, ind
    push    edx
    mov     edx, 0x4A9ADD
    call    edx
    mov     res, eax
    pop     edx
    }
    return res;
}
