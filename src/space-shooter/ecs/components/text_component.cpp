#include <space-shooter/ecs/components/text_component.hpp>

namespace space_shooter::ecs {
    
    TextComponent::TextComponent(const std::string& text, const std::filesystem::path &font_path, int characterSize, const sf::Vector2f& pos,
            const sf::Color& color, bool repeated) : text{text}, font_path{font_path}, characterSize{characterSize}, pos{pos}, color{color}, repeated{repeated} {}
}