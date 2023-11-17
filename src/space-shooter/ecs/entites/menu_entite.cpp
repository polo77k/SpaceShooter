#include <space-shooter/ecs/entities/menu_entite.hpp>

#include <space-shooter/ecs/components/input_component.hpp>

#include <filesystem>

namespace space_shooter::ecs {

MenuEntity::MenuEntity() {
  add<InputComponent>();
}

} // namespace space_shooter::ecs
