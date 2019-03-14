workspace "rmxp"
  configurations {"Debug", "Release"}

project "reader"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/reader/%{cfg.buildcfg}"

  files {"**.hpp", "**.h", "**.cpp"}
  removefiles "include/game/**"
  removefiles "src/game/**"

  includedirs "include"

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"

project "engine"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/engine/%{cfg.buildcfg}"

  files {"**.hpp", "**.h", "**.cpp"}
  removefiles "src/reader/main.cpp"

  includedirs "include"
  includedirs "C:/SFML/install/include"
  libdirs "C:/SFML/install/lib"

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"
    links {"sfml-audio-d", "sfml-graphics-d", "sfml-network-d", "sfml-system-d", "sfml-window-d"}

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"
    links {"sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window"}