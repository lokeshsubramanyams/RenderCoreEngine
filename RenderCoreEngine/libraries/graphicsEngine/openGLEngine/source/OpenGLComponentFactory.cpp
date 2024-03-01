#include "OpenGLComponentFactory.h"
#include "OpenGLMaterial.h"
#include "MeshFilter.h"
#include "Debug.h"
#include<vector>
namespace RCEngine
{
	namespace OpenGLEngine
	{
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateMeshRendererComp(Mesh& mesh, IShader& shader)
		{
			RCEngine::RenderCore::MeshFilter* filter = new RCEngine::RenderCore::MeshFilter(&mesh);
			RCEngine::RenderCore::IMaterial* material = new OpenGLMaterial(&shader);

			/*
			VertexNormal* verticesTriangle = new VertexNormal[3];

			verticesTriangle[0] = { Vector3(2.5f,0.0f,0.0f),Vector3(0.0f,1.0f,0.0f) };
			verticesTriangle[1] = { Vector3(3.5f,0.0f,0.0f),Vector3(0.0f,1.0f,0.0f) };
			verticesTriangle[2] = { Vector3(4.5f,0.0f,0.0f),Vector3(0.0f,1.0f,0.0f) };

			IMeshAbstract *triangleIMesh	= new IMesh<VertexNormal, PrimitiveTopology::TRIANGLES,3,3>(verticesTriangle, 3);

			IMeshFilter * gFilter = new RCEngine::RenderCore::IMeshFilter(triangleIMesh);

			void* data =  std::get<0>(gFilter->GetVertices());
			int arrayLength = std::get<1>(gFilter->GetVertices());
			std::vector<int> sequenceDS = gFilter->GetDataStructureSequenceSize();
			*/

			return new RCEngine::RenderCore::OpenGLMeshRenderer(filter,material);
		}
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateLineRendererComp(Line& line, IShader& shader)
		{
			RCEngine::RenderCore::IMaterial* material = new OpenGLMaterial(&shader);
			return new RCEngine::RenderCore::OpenGLLineRenderer(&line, material);
		}
		RCEngine::RenderCore::IComponent* OpenGLComponentFactory::CreateMeshRendererComp(IMeshAbstract& mesh, IShader& shader)
		{
			RCEngine::RenderCore::IMeshFilter* filter = new RCEngine::RenderCore::IMeshFilter(&mesh);
			RCEngine::RenderCore::IMaterial* material = new OpenGLMaterial(&shader);
			
			return new RCEngine::RenderCore::OpenGLMeshRenderer(filter, material);
		}
	}
}