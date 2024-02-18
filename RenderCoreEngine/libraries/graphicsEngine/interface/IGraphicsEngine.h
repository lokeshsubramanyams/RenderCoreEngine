#pragma once 
#include <string>
#include<vector>
#include<unordered_map>

#include "ShaderMetaData.h"
#include "ShaderProgram.h"
#include "IShader.h"
#include "MathLib.h"
#include "IComponentFactory.h"
#include "IRenderer.h"
#include "ICamera.h"

namespace RCEngine
{
	namespace GraphicsEngine
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::MathLib;
		class IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine( Rect viewport) = 0;
			virtual void LoadShaderBatch(std::vector<ShaderProgram> programs) = 0;
			virtual IShader* GetLoadedShader(std::string shader) = 0;
			virtual IComponentFactory* GetFactory() = 0;
			virtual void RenderLoop() = 0;
			virtual void OnWindowResize(Rect viewport) = 0;
			
			virtual void PreRender() = 0;
			virtual void PreRender(ICamera* camera) = 0;
			virtual void PostRender() = 0;
			virtual void PostRender(ICamera* camera) = 0;
		protected:
			virtual std::unordered_map<std::string, ShaderMetaData> GetShaderMetaData() = 0;
			

		};

	}
}