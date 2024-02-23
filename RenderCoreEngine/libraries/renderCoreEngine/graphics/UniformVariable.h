#pragma once
#include<variant>
#include<type_traits>
#include<string>
#include"MathLib.h"
#include "RenderCore.h"
#include "Debug.h"


namespace RCEngine
{
	using namespace MathLib;
	using uniformVarient = std::variant<int, float, Vector2, Vector3, Vector4,Matrix33, Matrix44>;
	
	struct VariantComparator {
		template<typename T>
		bool operator()(const T& lhs, const T& rhs) const {
			return lhs == rhs;
		}
		template<typename T, typename U>
		bool operator()(const T&, const U&) const {
			return false;
		}
	};
	
	class UniformVariable
	{
	public:
		uniformVarient variable;
		std::string nameKey;
		VariableType vType;
		bool updated = false;
		UniformVariable() :variable(0), vType(VariableType::int1), nameKey("") {}
		UniformVariable(const char* str, VariableType type) :vType(type), nameKey(str) 
		{
			switch (type)
			{
			case RCEngine::float1:	variable = 0.0f; break;
			case RCEngine::int1:		variable =  0; break;
			case RCEngine::vector2: variable = Vector2(0.0f, 0.0f); break;
			case RCEngine::vector3:	variable = Vector3(0.0f, 0.0f, 0.0f); break;
			case RCEngine::vector4:	variable = Vector4(0.0f, 0.0f, 0.0f, 0.0f); break;
			case RCEngine::color3:	variable = Color3(0.0f, 0.0f, 0.0f); break;
			case RCEngine::color4:	variable = Color4(0.0f, 0.0f, 0.0f, 0.0f); break;
			case RCEngine::mat3:		variable = Matrix33(1.0f); break;
			case RCEngine::mat4:		variable = Matrix44(1.0f); break;
			default:variable = 0; break;
			}
		}
					
		void Set(uniformVarient& value)
		{
			if (!areVariantsEqual(variable,value))
			{
				 variable = value;
				 updated = true;
			}
		}
	
		float GetFloat() { return std::get<float>(variable); }
		int GetInt() { return std::get<int>(variable); }
		Vector2 GetVec2() { return std::get<Vector2>(variable); }
		Vector3 GetVec3() { return std::get<Vector3>(variable); }
		Vector4 GetVec4() { return std::get<Vector4>(variable); }
		Color3 GetColor3() { return std::get<Color3>(variable); }
		Color4 GetColor4() { return std::get<Color4>(variable); }
		Matrix33 GetMat3() { return std::get<Matrix33>(variable); }
		Matrix44 GetMat4() { return std::get<Matrix44>(variable); }


		bool areVariantsEqual(const uniformVarient& v1, const uniformVarient& v2) {
			return std::visit(VariantComparator{}, v1, v2);
		}

	};

}