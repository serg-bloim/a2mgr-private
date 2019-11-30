//
// Created by a2fan on 11/29/2019.
//

#include "inv.h"
#include "../game_utils.h"

int T_INVENTORY::find_item(bytearr& signature) {
    int res = -1;
    int size = get_list_size(item_list);
    for (int i = 0; i < size; i++) {
        T_INVENTORY_ITEM **itemNode = get_list_item(item_list, i);
        T_INVENTORY_ITEM *item = *itemNode;
        if(compare(signature, item->data, item->data_size)){
            res = i;
            break;
        }
    }
    return res;
}