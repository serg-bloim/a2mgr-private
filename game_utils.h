#pragma once
#include "game_objects/game.h"

#define get_game_obj ((T_GAME *(*)())0x401870)

int get_list_size(void * list);