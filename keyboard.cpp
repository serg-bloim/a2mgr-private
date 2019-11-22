#include "logging.h"
#include <cstdio>
#include <iostream>
#include <string>

int __declspec(noinline) keyboard_handle_extra_keys(int key)
{
    char buffer[100];
    sprintf(buffer, "user pressed key# %d", key);
	log(buffer);
    return key;
}
void __declspec(naked) keyboard_handle_extra_keys_wrapper()
{
    int key;
    __asm
    {
        mov     ecx, [ebp+8h]
        mov     key, ecx
    }
    keyboard_handle_extra_keys(key);
	log("test comment");
	__asm
	{ // 44CB2D
        mov     ecx, [ebp+8h]
        mov     [ebp-18h], ecx
        ret
	}
}
