#include <editor/panels/MenuBar.hpp>

#include <imgui.h>
#include <ImGuiFileDialog.h>

void MenuBar::render()
{
    if(ImGui::BeginMainMenuBar()) {
        if(ImGui::BeginMenu("File")) {
            if(ImGui::MenuItem("Open")) {
                IGFD::FileDialogConfig config;
                config.path = ".";
                ImGuiFileDialog::Instance()->OpenDialog("ChooseProjDlgKey", "Choose Project", ".glowproject", config);
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}