#include <editor/panels/OpenProjectPopup.hpp>
#include <editor/panels/ViewportPanel.hpp>
#include <editor/panels/HierarchyPanel.hpp>

#include <GlowEngine/render/Window.hpp>
#include <GlowEngine/utils/MapLoader.hpp>

#include <ImGuiFileDialog.h>

#include <string>
#include <iostream>

#include <toml.hpp>


void OpenProjectPopup::render()
{
    if(ImGuiFileDialog::Instance()->Display("ChooseProjDlgKey")) {
        if(ImGuiFileDialog::Instance()->IsOk()) {
            std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
            std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();    

            auto data = toml::parse(filePathName);

            std::string projectName = toml::find<std::string>(data, "name");
            std::string projectVersion = toml::find<std::string>(data, "version");
            std::string projectMain = toml::find<std::string>(data, "main");

            Glow::Window::setTitle("GlowEditor - " + projectName + " (" + projectVersion + ")"); 

            unsigned int pos = projectMain.find("res://");
            if (pos != std::string::npos) {
                std::string mainPath = projectMain.substr(pos + 6);
                std::string path = filePath + "/" + mainPath;

                Glow::MapLoader loader(path);

                ViewportPanel::setMapData(loader.getBrushes());
                HierarchyPanel::setMapData(loader.getBrushes());    

            } else {
                
            }
        }

        ImGuiFileDialog::Instance()->Close();
    }
}