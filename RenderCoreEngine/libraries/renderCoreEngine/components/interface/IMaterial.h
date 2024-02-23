#pragma once 
#include "IComponent.h"
#include "IShader.h"
#include "UniformVariable.h"
#include<vector>
#include<unordered_map>
#include"Debug.h"

namespace RCEngine
{
	namespace RenderCore
	{
		using namespace RCEngine::RenderCore;
		using namespace RCEngine::MathLib;
		class IMaterial:public IComponent
		{
		protected:
			IShader* shader;
		public:
			std::unordered_map<std::string,UniformVariable>uniforms;

			explicit IMaterial(IShader *_shader) :shader(_shader),IComponent(ComponentType::MaterialComp) {};
			virtual void ApplyDefaultColor() = 0;
			virtual void ApplyColor(Color4 color) = 0;
			virtual void UseProgram() = 0;
			

			virtual void Apply(std::string uniformKey, uniformVarient value)
			{
				if (uniforms.count(uniformKey) > 0)
				{
					uniforms[uniformKey].Set(value);
					if (uniforms[uniformKey].updated)
					{
						Apply(uniforms[uniformKey]);
						uniforms[uniformKey].updated = false;
					}
				}
			}
			virtual void Apply(UniformVariable variable)
			{
				switch (variable.vType)
				{
				case RCEngine::float1: shader->ApplyProperty(variable.nameKey.c_str(), variable.GetFloat());
					break;
				case RCEngine::int1:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetInt());
					break;
				case RCEngine::vector2:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetVec2());
					break;
				case RCEngine::vector3:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetVec3());
					break;
				case RCEngine::vector4:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetVec4());
					break;
				case RCEngine::color3:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetColor3());
					break;
				case RCEngine::color4:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetColor4());
					break;
				case RCEngine::mat3:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetMat3());
					break;
				case RCEngine::mat4:shader->ApplyProperty(variable.nameKey.c_str(), variable.GetMat4());
					break;
				default:
					Debugger::Debug::Log("variable type not applicable!", variable.nameKey);
					break;
				}
			}

			void SetTransformationMatrix(Matrix44 mvp)
			{
				//depricated no longer support to make system unique
				shader->ApplyProperty("transformationMatrix", mvp);
			}
			void SetTransformationMatrix(Matrix44 model, Matrix44 view, Matrix44 projection)
			{
				shader->ApplyProperty(UniformVertexConst::modelMatrix, model);
				shader->ApplyProperty(UniformVertexConst::viewMatrix, view);
				shader->ApplyProperty(UniformVertexConst::projectionMatrix, projection);
			}
			
		};
	}
}