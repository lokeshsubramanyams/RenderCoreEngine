#pragma once
namespace RCEngine
{
	enum PlatformType
	{
		WINDOWS,
		BROWSER
	};

	enum GraphicsEngine
	{
		OPENGL_3x_ENGINE,
		OPENGL_4x_ENGINE,
		VULKAN_ENGINE,
		WEBGPU_ENGINE
	};

	enum VertexShaderType
	{
		default_vert_fallBack
	};

	enum FragmentShaderType
	{
		default_frag_fallBack
	};

}