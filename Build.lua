-- premake5.lua
workspace "EigenElite"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Test"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Core/Build-Core.lua"
group ""

include "Test/Build-App.lua"