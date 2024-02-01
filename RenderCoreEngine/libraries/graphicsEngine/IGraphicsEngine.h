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
			virtual void InitilizeEngine(Rect viewport) = 0;


			virtual void LoadShaderBatch(std::vector<ShaderProgram> programs) = 0;

			virtual void RegisterCustomShader(ShaderMetaData customShader)const = 0;

			virtual void RenderLoop() = 0;
			virtual void UpdateLoop(double delta) = 0;

		protected:
			virtual std::unordered_map<std::string, ShaderMetaData> GetShaderMetaData() = 0;

		};

	}
}