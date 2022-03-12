#include "pch-il2cpp.h"
#include "StatusModule.h"

#include <imgui.h>
#include <common/Config.h>
#include <gui/gui-util.h>

void StatusModule::Draw()
{

    static ImGuiTableFlags tabFlags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

    if (ImGui::BeginTable("activesTable", 1, tabFlags)) {

        ImGui::TableSetupColumn("Active features");
        ImGui::TableHeadersRow();

        int row = 0;

#define DrawLine(field) 

        for (auto& field : Config::GetToggleFields()) 
        {
            if (field->GetValue()) 
            {
                    ImGui::TableNextRow(); 
                    ImGui::TableSetColumnIndex(0);
                    ImGui::TextUnformatted(field->GetFriendlyName().c_str());
                    ImU32 row_bg_color = ImGui::GetColorU32(ImVec4(0.2f + row * 0.1f, 0.1f + row * 0.05f, 0.1f + row * 0.03f, 0.85f));
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_RowBg0, row_bg_color);
                    row++;
            }
        }
#undef DrawLine

        ImGui::EndTable();
    }
}

std::string StatusModule::GetName()
{
    return "Active features";
}