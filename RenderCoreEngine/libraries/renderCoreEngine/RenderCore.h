#pragma once

#include <string>
namespace RCEngine
{

		enum PlatformType
		{
			WINDOWS,
			BROWSER
		};

		enum GraphicsEngineType
		{
			OPENGL_3x_ENGINE,
			OPENGL_4x_ENGINE,
			VULKAN_ENGINE,
			WEBGPU_ENGINE
		};

		enum ShaderType
		{
			VERTEX,
			FRAGMENT
		};


		namespace SHADERCONST
		{
			 constexpr char DEFAULT_VERTEX[] = "DEFAULT_VERTEX";
			 constexpr char DEFAULT_FRAGMENT[] = "DEFAULT_FRAGMENT";

		};

		enum GeometryShapes
		{
			Cube,
			Sphere,
			Cylinder,
			Cone,
			Torus
		};

	
}
