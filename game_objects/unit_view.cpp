#include "unit_view.h"

bool T_UNIT_VIEW::isMainUnit() {
    return (attrs & 35) == 35;
}