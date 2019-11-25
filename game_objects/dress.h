#include "types.h"
struct __declspec(align(4)) CLASS_DRESS
{
    _BYTE gap0[124];
    _DWORD *method7C;
};

struct __declspec(align(4)) T_DRESS
{
    CLASS_DRESS *clazz;
    __declspec(noinline) void method7C(int gear_type){
        ths_wrapper((void *)clazz->method7C);
    }
};
