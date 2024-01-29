#ifndef SHADERS_H
#define SHADERS_H

#include "graphics/ShaderMetaData.h"


#include "default_vert.h"
#include "default_frag.h"

const char* vertexShaderSource = R"glsl(#version 300 es
    in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos, 1.0);
    }
)glsl";

const char* fragmentShaderSource = R"glsl( #version 300 es
    precision mediump float;
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
)glsl";

RCEngine::ShaderMetaData defaultVertShader = {
	  //vertexShaderSource,
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_vert),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_vert_len),
		RCEngine::ShaderType::VERTEX,
		RCEngine::SHADERCONST::DEFAULT_VERTEX
};


RCEngine::ShaderMetaData defaultFragShader = {
		//fragmentShaderSource,
		reinterpret_cast<const char*>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_frag),
		static_cast<int>(D__2024_Git_Repos_RenderCoreEngine_RenderCoreEngine_libraries_graphicsEngine_openGLEngine_openGL3x_shaders_default_frag_len),
		RCEngine::ShaderType::FRAGMENT,
		RCEngine::SHADERCONST::DEFAULT_FRAGMENT
};



#endif
