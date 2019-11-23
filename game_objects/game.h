#pragma once
#include "types.h"
#include "inv.h"
#include "inv_hotkey.h"

struct __declspec(align(4)) T_GAME
{
  _BYTE gap0[192];
  _DWORD dwordC0;
  _BYTE gap1[8];
  _DWORD dwordCC;
  _DWORD dwordD0;
  _DWORD pdwordD4;
  _BYTE gap2[8];
  _DWORD pdwordE0;
  _BYTE gap3[4];
  T_INVENTORY *inventory;
  _DWORD pdwordEC;
  _BYTE gap4[72];
  _DWORD pdword138;
  _BYTE gap5[640];
  _DWORD dword3BC;
  _BYTE gap6[8];
  _DWORD dword3C8;
  _BYTE gap7[40];
  _DWORD dword3F4;
  _BYTE gap8[20];
  _DWORD dword40C;
  _DWORD last_used_inv_item_ind;
  _DWORD dword414;
  _BYTE gap9[4];
  _DWORD dword41C;
  _BYTE gap10[212];
  struct_inv_hotkey inventoryHotKeys[9];
  _BYTE gap11[220];
  _DWORD dword63C;
};
