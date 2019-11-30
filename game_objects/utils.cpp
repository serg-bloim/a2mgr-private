//
// Created by a2fan on 11/24/2019.
//
#include "utils.h"
#include <stack>
#include <sstream>
#include "../logging.h"

__declspec(naked) int ths_wrapper(const void *fptr) {
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
//__cdecl int ths_wrapper2(const void *fptr, const void *ths, ...) {
//    __asm{
//    push    ebp
//    mov     ebp, esp
//    mov     edx, fptr
//    pop     ebp
//    add     esp, 8 // removing ths_wrapper's return address and fptr parameter from stack
//    jmp     edx
//    }
//}
//__declspec(naked) int ths_wrapper3(const void *fptr, void *first_param_ptr) {
//    __asm{
//    mov     esp, first_param_ptr
//    mov     edx, fptr
//    jmp     edx
//    }
//}
bool compare(bytearr &barr, _BYTE *arr, int arrsize) {
    if (barr.size() != arrsize || arrsize == 0)
        return false;
    std::stringstream s1, s2;
    bool res = true;
    log("barrsize:");
    log(barr.size());
    log("arrsize:");
    log(arrsize);
    for (int i = 0; i < arrsize; i++) {
        s1 << (int)barr[i] << ",";
        s2 << (int)(char)arr[i] << ",";
        if (barr[i] != (char)arr[i]) {
            res = false;
            break;
        }
    }
    log(res ? "match" : "no match");
    log(s1.str());
    log(s2.str());
    log("-----------");
    return res;
}

int ceilingDiv(int a, int b) {
    return (a + b - 1) / b;
}

char transform(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 100;
}

bytearr stoba(std::string &str) {
    bytearr res;
    std::stringstream ss(str);
    for (int i = 0; i + 2 <= str.size(); i += 2) {
        unsigned char v, h, l;
        ss >> h >> l;
        h = transform(h);
        l = transform(l);
        v = (h << 4) + l;
        res.push_back(v);
    }
    return res;
}

bytearr stoba(const char *str) {
    return stoba(std::string(str));
}

std::string nospaces(const char *c_str) {
    std::string s;
    char c;
    int i = 0;
    while ((c = c_str[i++]) != '\0') {
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
            s.push_back(c);
        }
    }
    return s;
}