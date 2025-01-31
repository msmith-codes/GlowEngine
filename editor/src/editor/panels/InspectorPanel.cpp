#include <editor/panels/InspectorPanel.hpp>
#include <editor/panels/ViewportPanel.hpp>

#include <imgui.h>

void InspectorPanel::render()
{
    ImGui::Begin("Inspector");
        if(ViewportPanel::getSelectedBrush()) {
            auto brush = ViewportPanel::getSelectedBrush();

            char nameBuffer[256];
            strncpy(nameBuffer, brush->name.c_str(), sizeof(nameBuffer));
            nameBuffer[sizeof(nameBuffer) - 1] = '\0';
            ImGui::InputText("Name", nameBuffer, sizeof(nameBuffer));
            brush->name = nameBuffer;

            char materialBuffer[256];
            strncpy(materialBuffer, brush->material.c_str(), sizeof(materialBuffer));
            materialBuffer[sizeof(materialBuffer) - 1] = '\0';
            ImGui::InputText("Material", materialBuffer, sizeof(materialBuffer));
            brush->material = materialBuffer;

            ImGui::DragFloat3("Position", &brush->position.x);
            brush->position.x = roundf(brush->position.x);
            brush->position.y = roundf(brush->position.y);
            brush->position.z = roundf(brush->position.z);

            ImGui::DragFloat3("Size", &brush->size.x);
            brush->size.x = roundf(brush->size.x);
            brush->size.y = roundf(brush->size.y);
            brush->size.z = roundf(brush->size.z);

            ImGui::DragFloat3("Rotation", &brush->rotation.x);
            brush->rotation.x = roundf(brush->rotation.x);
            brush->rotation.y = roundf(brush->rotation.y);
            brush->rotation.z = roundf(brush->rotation.z);
        }
    ImGui::End();
}