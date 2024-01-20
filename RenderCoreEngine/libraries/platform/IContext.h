#pragma once
#include "MathLib.h"

namespace RCEngine
{
	namespace Platform
	{
		using namespace MathLib;
		class IContext
		{
		protected:
			const MathLib::Rect viewport;
		public:
			 IContext(MathLib::Rect viewport);
			 virtual Rect GetViewport() const  = 0;
			 virtual ~IContext();
		};
	}
}