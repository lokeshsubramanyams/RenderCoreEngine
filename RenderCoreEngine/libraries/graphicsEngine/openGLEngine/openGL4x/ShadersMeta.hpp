#ifndef SHADERS_H
#define SHADERS_H

#include "common/ShaderMetaData.hpp"

#include "default_vert.h"
#include "default_frag.h"

ShaderMetaData defaultVertShader = {
		reinterpret_cast<const GLchar*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_vert),
		static_cast<GLint>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_vert_len)
};


ShaderMetaData defaultFragShader = {
		reinterpret_cast<const GLchar*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_frag),
		static_cast<GLint>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL4x_shaders_default_frag_len)
};

#endif
