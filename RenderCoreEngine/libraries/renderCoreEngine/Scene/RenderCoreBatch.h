#pragma once
#include "Scene.h"

namespace RCEngine
{
	namespace RenderCore
	{
		class RenderCoreBatch
		{
		public:
			RenderCoreBatch();
			void CreateBatch(Scene* scene);
		
		};
	}
}