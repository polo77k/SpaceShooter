#pragma once

#include <string_view>

namespace space_shooter {

using namespace std::literals::string_view_literals;

// clang-format off
  inline constexpr unsigned int     SPS_VERSION_MAJOR  = 0;
  inline constexpr unsigned int     SPS_VERSION_MINOR  = 1;
  inline constexpr unsigned int     SPS_VERSION_PATCH  = 0;
  inline constexpr unsigned int     SPS_VERSION_TWEAK  = 0;
  inline constexpr std::string_view SPS_VERSION        = "0.1.0.0"sv;
  inline constexpr std::string_view SPS_AUTHORS        = ""sv;
  inline constexpr std::string_view SPS_PATH_TO_ASSETS = "C:/Users/polo7/Documents/ESIEE/E4/Cours E4/Programation C++/Projet/squeleton/squeleton/assets"sv;
// clang-format on

} // namespace space_shooter
