#include "Context.hpp"

namespace RCEngine
{
	namespace Platform
	{
		Context::Context()
		{

		}
		Context::~Context()
		{

		}

		Context* Context::CreateContext(MathLib::Rect _viewport)
		{
			Context* context = new Context();
			context->viewport = _viewport;
			return context;
		}
		MathLib::Rect Context::GetViewport() { return this->viewport; }
	}
}


