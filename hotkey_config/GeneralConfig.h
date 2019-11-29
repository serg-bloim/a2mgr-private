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
    HotKeyConfig* getHotKeyConfig();
    int getAutoHealLowBoundary();
    int getAutoHealHighBoundary();
    void reload();

private:
    std::string filename;
    int autoHealLowBoundary;
    int autoHealHighBoundary;
};

GeneralConfig gConf("config.ini");

#endif //A2MGR_GENERALCONFIG_H
