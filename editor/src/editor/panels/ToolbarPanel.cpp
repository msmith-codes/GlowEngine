#include <editor/panels/ToolbarPanel.hpp>

#include <imgui.h>

void ToolbarPanel::render()
{
    ImGui::Begin("Tool Bar");
        if(ImGui::Button("Play")) {
            // TODO: Open the game in a new window.
        }
    ImGui::End();
}