workspace "MarshalToCpp"
  configurations {"Debug", "Release"}

project "MarshalToCpp"
  kind "ConsoleApp"
  language "C++"
  targetdir "bin/%{cfg.buildcfg}"

  files {"**.hpp", "**.h", "**.cpp"}

  includedirs "include"

  filter "configurations:Debug"
    defines "DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "NDEBUG"
    optimize "On"
