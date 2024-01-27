#pragma once 
#include <unordered_map>
#include <string>
#include<vector>
#include "Mesh.h"
#include "ShaderMetaData.h"
#include "Shader.h"

namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RenderCore::Graphics;
		class IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine() const = 0;

			virtual std::vector<ShaderMetaData> GetShaderMetaData() = 0;

			virtual std::vector<Shader> CompileShaders(std::vector<ShaderMetaData> shadersMeta) const = 0;
			virtual void RegisterCustomShader(ShaderMetaData customShader)const = 0;

			virtual void RenderLoop() = 0;
			virtual void UpdateLoop(double delta) = 0;

			virtual void Renderable(Mesh* mesh)=0;
			virtual void Renderable(Mesh* mesh,Shader vertex,Shader fragment) = 0;

		};

	}
}