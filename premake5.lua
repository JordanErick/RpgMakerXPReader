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

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"