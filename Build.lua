-- premake5.lua
workspace "EigenElite"
   architecture "x64"
   configurations { "Debug", "Release" }
   startproject "Test"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      if _ACTION == "vs2022" then
         buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
      else
         buildoptions "-fsized-deallocation"
      end
   filter "system:linux"
      buildoptions "-fsized-deallocation"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

folder = ""

if os.host() == "windows" then
   folder = "Win64"
   print(folder)
end

if os.host() == "linux" then
   folder = "Linux"
   print(folder)
end

group "Core"
	include "Core/Build-Core.lua"
group ""

include "Test/Build-App.lua"