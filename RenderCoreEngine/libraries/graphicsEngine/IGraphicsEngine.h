#pragma once 

namespace RCEngine
{
	namespace GraphicsEngine
	{
		class IGraphicsEngine
		{
		public:
			virtual void InitilizeEngine() const = 0;
			virtual void  Render() = 0;
			virtual void Update(double delta) = 0;
		};

	}
}