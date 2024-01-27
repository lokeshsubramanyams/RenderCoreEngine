#pragma once 
#include <unordered_map>
#include <string>
#include<vector>
#include<unordered_map>
#include "Mesh.h"
#include "ShaderMetaData.h"
#include "ShaderProgram.h"

namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RenderCore::Graphics;
		class IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine(Rect viewport) const = 0;

			virtual std::unordered_map<std::string, ShaderMetaData> GetShaderMetaData() = 0;

			virtual ShaderProgram CompileShader(ShaderMetaData vertex, ShaderMetaData fragment) const = 0;

			virtual void RegisterCustomShader(ShaderMetaData customShader)const = 0;

			virtual void RenderLoop() = 0;
			virtual void UpdateLoop(double delta) = 0;

			virtual void Renderable(Mesh* mesh)=0;
			virtual void Renderable(Mesh* mesh, ShaderProgram program) = 0;

		};

	}
}