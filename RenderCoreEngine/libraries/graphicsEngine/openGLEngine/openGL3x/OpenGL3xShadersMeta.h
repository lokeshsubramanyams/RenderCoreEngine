#ifndef SHADERS_H
#define SHADERS_H

#include "graphics/ShaderMetaData.h"


#include "default_vert.h"
#include "default_frag.h"
#include "default_v01_vert.h"
#include "default_v01_frag.h"


RCEngine::ShaderMetaData defaultVertShader = {
	  
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_vert),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_vert_len),
		RCEngine::ShaderType::VERTEX,
		RCEngine::CONST::SHADERFILE::DEFAULT_VERTEX,
		"transformationMatrix"
};


RCEngine::ShaderMetaData defaultFragShader = {
		
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_frag),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_frag_len),
		RCEngine::ShaderType::FRAGMENT,
		RCEngine::CONST::SHADERFILE::DEFAULT_FRAGMENT
};

RCEngine::ShaderMetaData defaultVertShader_v01 = {
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_v01_vert),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_v01_vert_len),
		RCEngine::ShaderType::VERTEX,
		RCEngine::CONST::SHADERFILE::DEFAULT_VERTEX_V01,
};
RCEngine::ShaderMetaData defaultFragShader_v01 = {
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_v01_frag),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_v01_frag_len),
		RCEngine::ShaderType::FRAGMENT,
		RCEngine::CONST::SHADERFILE::DEFAULT_FRAGMENT_V01
};


#endif
