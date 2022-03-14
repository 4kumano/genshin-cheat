#include "pch-il2cpp.h"
#include "PlayerModule.h"

#include <imgui.h>

#include <common/Config.h>
#include <gui/gui-util.h>

void PlayerModule::Draw()
{
    ConfigWidget(Config::cfgGodModEnable, "Enables god mode. (No income damage); May not work with some types of damage.");

    BeginGroupPanel("No cooldown", ImVec2(-1.0f, 0.0f));
    {
        ConfigWidget(Config::cfgInstantBowEnable, "Disable cooldown of bow charge.");
        ConfigWidget(Config::cfgNoSkillCDEnable, "Disable skills cooldown.");
        ConfigWidget(Config::cfgNoSprintCDEnable, "Disable speed cooldown.");
    }
    EndGroupPanel();

    BeginGroupPanel("Infinite stamina", ImVec2(-1.0f, 0.0f));
    {
        ConfigWidget("Enable", Config::cfgInfiniteStaminaEnable, "Enables infinite stamina option.");
        ConfigWidget(Config::cfgISMovePacketMode, 
            "This mode prevent send to server packets with stamina cost actions,\nlike (swim, climb, sprint and so on).\nNOTE. This is can be more safe than standart method. But it is not tested.");
    }
    EndGroupPanel();
}

std::string PlayerModule::GetName()
{
    return "Player";
}