//
// Created by a2fan on 11/29/2019.
//

#include "GeneralConfig.h"
#include "../logging.h"
#include "../game_objects/utils.h"
#include <sstream>


GeneralConfig gConf("config.ini");

GeneralConfig::GeneralConfig(std::string file) {
    this->filename = file;
//    reload();
}

void GeneralConfig::reload() {
    log("Start reading config from file");
    try {
        log("Reading config from file '" + filename + "'");
        CSimpleIniA ini;
        log("1");
        SI_Error rc = ini.LoadFile(this->filename.c_str());
        log("2");
        if (rc < 0) {
            log("failed reading config from file '" + filename + "'");
            return;
        }
        log("3");
        std::stringstream ss;
        _potionHealthBig = stoba(nospaces(ini.GetValue("inventory", "potionHealthBig", "")));
        ss << "_potionHealthBig: " << toHex(_potionHealthBig) <<";";
        log(ss.str());
        _potionHealthSmall = stoba(nospaces(ini.GetValue("inventory", "potionHealthSmall", "")));
        ss << "_potionHealthSmall: " << toHex(_potionHealthSmall) <<";";
        log(ss.str());
        _potionManaBig = stoba(nospaces(ini.GetValue("inventory", "potionManaBig", "")));
        _potionManaSmall = stoba(nospaces(ini.GetValue("inventory", "potionManaSmall", "")));
        _potionHealthRegen = stoba(nospaces(ini.GetValue("inventory", "potionHealthRegen", "")));
        _potionManaRegen = stoba(nospaces(ini.GetValue("inventory", "potionManaRegen", "")));
        log("4");
        _autoHealLowBoundary = (int) ini.GetLongValue("autoheal", "low", 100000);
        ss.clear();
        ss << "_autoHealLowBoundary: " << ini.GetValue("autoheal", "low", "------") <<";";
        log(ss.str());
        ss.clear();
        ss << "_autoHealLowBoundary: " << _autoHealLowBoundary <<";";
        log(ss.str());
        ss.clear();
        _autoHealHighBoundary = (int) ini.GetLongValue("autoheal", "high", 100000);
        _hotkeyConfig.load("hotkeys.txt");
        log("Successfully read config from file '" + filename + "'");
    }
    catch (int e) {
        log("failed reading config from ");
        log("failed reading config from " + filename);
    }
}

HotKeyConfig* GeneralConfig::getHotKeyConfig(){
    return &this->_hotkeyConfig;
}
int GeneralConfig::getAutoHealLowBoundary() {
    return _autoHealLowBoundary;
}

int GeneralConfig::getAutoHealHighBoundary() {
    return _autoHealHighBoundary;
}

bytearr GeneralConfig::potionHealthBig() {
    return _potionHealthBig;
}

bytearr GeneralConfig::potionHealthSmall() {
    return _potionHealthSmall;
}

bytearr GeneralConfig::potionManaBig() {
    return _potionManaBig;
}

bytearr GeneralConfig::potionManaSmall() {
    return _potionManaSmall;
}

bytearr GeneralConfig::potionHealthRegen() {
    return _potionHealthRegen;
}

bytearr GeneralConfig::potionManaRegen() {
    return _potionManaRegen;
}

