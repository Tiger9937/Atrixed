workspace "Atrixed"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Atrixed Project
project "Atrixed"
    location "Atrixed"
    kind "SharedLib" -- Shared library (.dll)
    language "C++"

    -- Output directories for binaries and intermediate files
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    -- Specify the source files to include
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- Include directories
    includedirs {
        "C:/Projects/GameEngin/ExternalLibrary/spdlog/include"
    }

    -- Windows-specific settings
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "AX_PLATFORM_WINDOWS",
            "AX_BUILD_DLL"
        }

        -- Post-build command to copy output executable/library       
        postbuildcommands {
            "{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/SandBox/\""
        }


    filter "configurations:Debug"
        defines "AX_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AX_DIST"
        optimize "On"

-- SandBox Project
project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    -- Output directories for binaries and intermediate files
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    -- Specify the source files to include
    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    -- Include directories
    includedirs {
        "C:/Projects/GameEngin/ExternalLibrary/spdlog/include",
        "C:/Projects/GameEngin/Atrixed/src"
    }

    -- Link to the Atrixed library
    links {
        "Atrixed"
    }

    -- Windows-specific settings
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "AX_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AX_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AX_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "AX_DIST"
        optimize "On"
