#include <editor/panels/HierarchyPanel.hpp>
#include <editor/panels/ViewportPanel.hpp>

#include <GlowEngine/utils/MapLoader.hpp>

#include <imgui.h>

std::vector<Glow::Brush*> HierarchyPanel::mapData = {};

void HierarchyPanel::render()
{
    ImGui::Begin("Hierarchy");
        for(const auto& brush : HierarchyPanel::mapData) {
            if(ImGui::Selectable(brush->name.c_str())) {
                ViewportPanel::setSelectedBrush(brush);
            }
        }
    ImGui::End();
}

void HierarchyPanel::setMapData(const std::vector<Glow::Brush*>& brushes)
{
    HierarchyPanel::mapData = brushes;
}
