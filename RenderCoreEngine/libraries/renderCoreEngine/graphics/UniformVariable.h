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

	template<typename T>
	concept Variable = std::disjunction_v<
		std::is_same<T, float>,
		std::is_same<T, int>,
		std::is_same<T, Vector2>,
		std::is_same<T, Vector3>,
		std::is_same<T, Vector4>,
		std::is_same<T, Color3>,
		std::is_same<T, Color4>,
		std::is_same<T, Matrix44>,
		std::is_same<T, Matrix33>
	>;
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
		std::string nameKey;// = nullptr;
		VariableType vType;// = VariableType::int1;
		bool updated = false;
		UniformVariable() :variable(0), vType(VariableType::int1), nameKey("") {}
		UniformVariable(const char* str, VariableType type) :vType(type), nameKey(str) {

			switch (type)
			{
			case RCEngine::float1:	variable =  0.0f;
			case RCEngine::int1:		variable =  0;
			case RCEngine::vector2: variable = RCEngine::MathLib::Vector2(0.0f, 0.0f);
			case RCEngine::vector3:	variable = RCEngine::MathLib::Vector3(0.0f, 0.0f, 0.0f);
			case RCEngine::vector4:	variable = RCEngine::MathLib::Vector4(0.0f, 0.0f, 0.0f, 0.0f);
			case RCEngine::color3:	variable = RCEngine::MathLib::Color3(0.0f, 0.0f, 0.0f);
			case RCEngine::color4:	variable = RCEngine::MathLib::Color4(0.0f, 0.0f, 0.0f, 0.0f);
			case RCEngine::mat3:		variable = RCEngine::MathLib::Matrix33(1.0f);
			case RCEngine::mat4:		variable = RCEngine::MathLib::Matrix44(1.0f);
			default:variable = 0;
			}

		}

		template<typename T>
		void DefaultSet(T newValue){variable = newValue;}

		
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
		RCEngine::MathLib::Vector2 GetVec2() { return std::get <RCEngine::MathLib::Vector2>(variable); }
		RCEngine::MathLib::Vector3 GetVec3() { return std::get <RCEngine::MathLib::Vector3>(variable); }
		RCEngine::MathLib::Vector4 GetVec4() { return std::get <RCEngine::MathLib::Vector4>(variable); }
		RCEngine::MathLib::Color3 GetColor3() { return std::get <RCEngine::MathLib::Color3>(variable); }
		RCEngine::MathLib::Color4 GetColor4() { return std::get <RCEngine::MathLib::Color4>(variable); }
		RCEngine::MathLib::Matrix33 GetMat3() { return std::get <RCEngine::MathLib::Matrix33>(variable); }
		RCEngine::MathLib::Matrix44 GetMat4() { return std::get <RCEngine::MathLib::Matrix44>(variable); }


		bool areVariantsEqual(const uniformVarient& v1, const uniformVarient& v2) {
			return std::visit(VariantComparator{}, v1, v2);
		}


		
	};

}