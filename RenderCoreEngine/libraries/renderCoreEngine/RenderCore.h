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


		namespace CONST
		{
			namespace SHADERFILE
			{
				constexpr char DEFAULT_VERTEX[] = "DEFAULT_VERTEX";
				constexpr char DEFAULT_FRAGMENT[] = "DEFAULT_FRAGMENT";
			}
			namespace SHADERUNIFORM
			{
				constexpr char DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX[] =  "transformationMatrix";
				constexpr char DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLORVEC4[] = "uniformFragmentColor";
			}
			namespace SHADERKEY
			{
				constexpr char DEFAULT_VERTEX_FRAGMENT[] = "DEFAULT_VERTEX_FRAGMENT";
			}
		};

		enum GeometryShapes
		{
			Cube,
			Sphere,
			Cylinder,
			Cone,
			Torus
		};

		enum ComponentType
		{
			MeshRendererComp,
			LineRendererComp
		};

	
}
