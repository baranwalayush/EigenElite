project "App"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.h", "Source/**.cpp" }


   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   if os.host() == "windows" then
      links
      {
         "Core",
         "../Vendor/Lib/Raylib/" .. folder .. "/msvc/**.lib",
         "winmm"
      }
   else
      links
      {
         "Core",
         "../Vendor/Lib/Raylib/" .. folder .. "/:libraylib.a"
      }
   end

   if os.host() == "windows" then 
      includedirs
      {
         "Source",
   
        -- Include Core
        "../Core/Source",
        "../Vendor/Include/Raylib/" .. folder .. "/msvc"
      }
   end

   if os.host() == "linux" then 
      includedirs
      {
         "Source",
   
        -- Include Core
        "../Core/Source",
        "../Vendor/Include/Raylib/" .. folder
      }
   end

   filter "system:windows"
      systemversion "latest"
      defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
