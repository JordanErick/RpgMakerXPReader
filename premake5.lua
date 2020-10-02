workspace "rmxp"
  configurations {"Debug", "Release"}
  cppdialect "C++17"

project "rmxp"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/%{cfg.buildcfg}"

  files {"**.h", "**.hpp", "**.c", "**.cpp"}
  
  includedirs "include"
  includedirs "include/zlib"

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"