#pragma once
#include "RenderCoreBatch.h"
#include<vector>
#include<unordered_map>

namespace RCEngine
{
	using namespace std;
	namespace RenderCore
	{
		RenderCoreBatch::RenderCoreBatch(){

		}
		void RenderCoreBatch::CreateBatch(Scene* scene)
		{
			std::vector<IRenderer*> sceneRenderers = scene->GetRenderers();
			
			std::unordered_map<string, std::vector<float>>meshMerger;


			for (int i = 0; i < sceneRenderers.size(); i++)
			{
				if (sceneRenderers[i]->type == ComponentType::MeshRendererComp)
				{
					string hash = sceneRenderers[i]->GetMeshFilter()->GetSequenceHash();
					
					std::tuple<void*, int> current = sceneRenderers[i]->GetMeshFilter()->mesh->GetVertices();

					int count = std::get<1>(current);

					float* vertices =  static_cast<float*>(std::get<0>(current));
				
					if (meshMerger.count(sceneRenderers[i]->GetMeshFilter()->GetSequenceHash()) <=0)
					{
						meshMerger.insert({ hash,std::vector<float>() });
					}

					int sqCount = sceneRenderers[i]->GetMeshFilter()->GetSequenceTotalElementsCount();
					int totalCount = count * sqCount;

					Debugger::Debug::Log("count:", count);
					Debugger::Debug::Log("TotalCount:", totalCount);

					for (int i = 0; i < totalCount; i++)
					{
						meshMerger[hash].push_back(vertices[i]);
					}

					/*for (int i = 0; i < count; i++)
					{
						for (int j = 0; j < sqCount; j++)
						{
							std::cout << vertices[i* sqCount+j] << ", ";
						}
						std::cout << " " << std::endl;
					}*/
				}
			}

			for (const auto& element : meshMerger) 
			{
				std::cout<<"MergedMesh with sequence:"<<element.first << "-->" << element.second.size() << std::endl;
			}
		}
	}
}