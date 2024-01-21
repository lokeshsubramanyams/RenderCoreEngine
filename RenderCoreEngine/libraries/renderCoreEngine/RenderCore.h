#pragma once
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

		enum VertexShaderType
		{
			default_vert
		};

		enum FragmentShaderType
		{
			default_frag
		};
	
}
