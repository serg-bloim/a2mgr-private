//
// Created by a2fan on 11/29/2019.
//

#include "GeneralConfig.h"
#include "../logging.h"
GeneralConfig::GeneralConfig(std::string file) {
    this->filename = file;
    reload();
}
void GeneralConfig::reload() {
    CSimpleIniA ini;
    SI_Error rc = ini.LoadData(this->filename);
    if(rc < 0){
        log("failed reading config from file '" + filename + "'");
        return;
    }
    autoHealLowBoundary = (int)ini.GetLongValue("autoheal", "low");
    autoHealLowBoundary = (int)ini.GetLongValue("autoheal", "hight");
}

int GeneralConfig::getAutoHealLowBoundary(){
    return autoHealLowBoundary;
}
int GeneralConfig::getAutoHealHighBoundary() {}(){
    return autoHealHighBoundary;
}