#include <editor/panels/OpenProjectPopup.hpp>

#include <ImGuiFileDialog.h>

#include <string>

void OpenProjectPopup::render()
{
    if(ImGuiFileDialog::Instance()->Display("ChooseProjDlgKey")) {
        if(ImGuiFileDialog::Instance()->IsOk()) {
            std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
            std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

            // TODO: Open Project
        }

        ImGuiFileDialog::Instance()->Close();
    }
}