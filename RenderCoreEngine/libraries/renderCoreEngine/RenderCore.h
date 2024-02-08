#pragma once

#include <string>
#include "MathLib.h"

namespace RCEngine
{

		enum PlatformType
		{
			WINDOWS,
			BROWSER
		};

		enum GraphicsEngineType
		{
			OPENGL_3x_ENGINE,
			OPENGL_4x_ENGINE,
			VULKAN_ENGINE,
			WEBGPU_ENGINE
		};

		enum ShaderType
		{
			VERTEX,
			FRAGMENT
		};

		enum GeometryShapes
		{
			Cube,
			Sphere,
			Cylinder,
			Cone,
			Torus
		};

		enum ComponentType
		{
			TransformComp,
			CameraComp,
			MeshFilterComp,
			MaterialComp,
			MeshRendererComp,
			LineRendererComp,
			BehaviourComp
		};

		enum CameraType
		{
			Perspective,
			Orthographic
		};

		struct CameraSetting
		{
			CameraType cameraType;
			float fieldOfView;
			float nearZ;
			float farZ;
		};
		struct Settings
		{
			MathLib::Rect screen;
			CameraSetting cameraSettings;
		};

	
		namespace CONST
		{
			namespace SHADERFILE
			{
				constexpr char DEFAULT_VERTEX[] = "DEFAULT_VERTEX";
				constexpr char DEFAULT_FRAGMENT[] = "DEFAULT_FRAGMENT";
			}
			namespace SHADERUNIFORM
			{
				
				constexpr char VIEW_PROJECTION_MATRIX_KEY[] = "viewProjectionMatrix";

				constexpr char DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX[] =  "transformationMatrix";
				constexpr char DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR[] = "uniformFragmentColor";
			}
			namespace SHADERKEY
			{
				constexpr char DEFAULT_VERTEX_FRAGMENT[] = "DEFAULT_VERTEX_FRAGMENT";
			}
			namespace DEFAULTVALUE
			{
				const MathLib::Color defaultColor = MathLib::Color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		};

		

	
}
