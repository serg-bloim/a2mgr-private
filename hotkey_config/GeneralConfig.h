//
// Created by a2fan on 11/29/2019.
//

#ifndef A2MGR_GENERALCONFIG_H
#define A2MGR_GENERALCONFIG_H

#include "SimpleIni.h"
#include "HotKeyConfig.h"
#include <string>


class GeneralConfig {
public:
    GeneralConfig(std::string file);

    HotKeyConfig *getHotKeyConfig();

    int getAutoHealLowBoundary();

    int getAutoHealHighBoundary();

    bytearr potionHealthBig();

    bytearr potionHealthSmall();

    bytearr potionManaBig();

    bytearr potionManaSmall();

    bytearr potionHealthRegen();

    bytearr potionManaRegen();

    bytearr autoHealLowBoundary();

    void reload();

private:
    std::string filename;
    HotKeyConfig _hotkeyConfig;
    int _autoHealLowBoundary;
    int _autoHealHighBoundary;

    bytearr _potionHealthBig;
    bytearr _potionHealthSmall;
    bytearr _potionManaBig;
    bytearr _potionManaSmall;
    bytearr _potionHealthRegen;
    bytearr _potionManaRegen;
};

extern GeneralConfig gConf;

#endif //A2MGR_GENERALCONFIG_H
