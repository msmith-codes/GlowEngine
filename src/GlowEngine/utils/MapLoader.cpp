#include <GlowEngine/utils/MapLoader.hpp>

#include <iostream>

namespace Glow
{
    MapLoader::MapLoader(const std::string& path)
    {
        try {
            auto data = toml::parse(path);

            this->name = toml::find<std::string>(data, "name");
            this->author = toml::find<std::string>(data, "author");
            this->version = toml::find<std::string>(data, "version");

            auto dim = toml::find<std::vector<float>>(data, "dimensions");
            this->dimesions = Vector3{ dim[0], dim[1], dim[2] };

            auto brushList = toml::find<std::vector<toml::table>>(data, "brushes");

            for(const auto& brush : brushList) {
                Brush* b = new Brush;
                b->name = brush.at("name").as_string();
                
                b->material = brush.at("material").as_string();
                
                auto pos = brush.at("position").as_array();
                b->position = Vector3{ 
                    static_cast<float>(pos.at(0).as_floating()), 
                    static_cast<float>(pos.at(1).as_floating()), 
                    static_cast<float>(pos.at(2).as_floating()) 
                };

                auto size = brush.at("size").as_array();
                b->size = Vector3{ 
                    static_cast<float>(size.at(0).as_floating()), 
                    static_cast<float>(size.at(1).as_floating()), 
                    static_cast<float>(size.at(2).as_floating()) 
                };

                auto rot = brush.at("rotation").as_array();
                b->rotation = Vector3{ 
                    static_cast<float>(rot.at(0).as_floating()), 
                    static_cast<float>(rot.at(1).as_floating()), 
                    static_cast<float>(rot.at(2).as_floating()) 
                };

                this->brushes.push_back(b);
            }
        } catch(const toml::file_io_error& e) {
            std::cerr << e.what() << std::endl;
        }   
    }

    std::vector<Brush*> MapLoader::getBrushes() const
    {
        return this->brushes;
    }
}
