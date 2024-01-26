#include "IOpenGLEngine.h"
#include "Debug.h"

namespace RCEngine
{
	namespace OpenGLEngine
	{
		using namespace RCEngine::Debugger;
		void IOpenGLEngine::InitilizeEngine() const
		{
			if (glewInit() != GLEW_OK)
			{
				Debug::Log("Glew not initilized-some error!");
			}
		}
		void IOpenGLEngine::Update(double delta)
		{
			//Debug::Log("deltaTime: ",delta);

		//	testVariable += 0.01*testVariable1 * delta;

			//if (testVariable > 1 || testVariable < 0) {
	//			testVariable1 = testVariable1 * -1.0f;
		//	}
		}
    void IOpenGLEngine::Renderable(Mesh* mesh)
    {
			glGenBuffers(1, &vb[0]);
		//	glBindBuffer(GL_ARRAY_BUFFER, vb[0]);
			
			Vector3 vertices[3];
			vertices[0] = Vector3(-1.0, -1.0, 0.0);
			vertices[1] = Vector3(1.0, -1.0, 0.0);
			vertices[2] = Vector3(0.0, 1.0, 0.0);

			Debug::Log("size of mesh vertices:", std::to_string(sizeof(vertices)));

			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    }
	}
}

