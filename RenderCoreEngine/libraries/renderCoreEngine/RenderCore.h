#pragma once

#include <string>
#include "MathLib.h"
#include<algorithm>

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
			LightComp,
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
			MathLib::Vector4 backgroundColor;
			CameraType cameraType;
			float fieldOfView;
			float nearZ;
			float farZ;
		};

		enum GraphicsTag
		{
			Scene = 0,
			Editor = 1
		};
		enum VariableType
		{
			float1, int1, vector2, vector3, vector4, color3, color4, mat3, mat4
		};

	
		namespace CONST
		{
			namespace SHADERFILE
			{
				constexpr char DEFAULT_VERTEX[] = "DEFAULT_VERTEX";
				constexpr char DEFAULT_FRAGMENT[] = "DEFAULT_FRAGMENT";
				constexpr char DEFAULT_VERTEX_V01[] = "DEFAULT_VERTEX_V01";
				constexpr char DEFAULT_FRAGMENT_V01[] = "DEFAULT_FRAGMENT_V01";
			}
			namespace SHADERUNIFORM
			{
				
				constexpr char VIEW_PROJECTION_MATRIX_KEY[] = "viewProjectionMatrix";

				constexpr char DEFAULT_VERTEX_UNIFORM_TRANSFORM_MATRIX[] =  "transformationMatrix";
				constexpr char DEFAULT_VERTEX_UNIFORM_FRAGMENT_COLOR[] = "uniformFragmentColor";

				constexpr char DEFAULT_VERTEX_UNIFORM_MODEL_MATRIX[] = "MODEL_MATRIX";
				constexpr char DEFAULT_VERTEX_UNIFORM_VIEW_MATRIX[] = "VIEW_MATRIX";
				constexpr char DEFAULT_VERTEX_UNIFORM_PROJECTION_MATRIX[] = "PROJECTION_MATRIX";

				constexpr char DEFAULT_FRAGMENT_UNIFORM_LIGHTDIR[] = "LIGHT_DIRECTION";
				constexpr char DEFAULT_FRAGMENT_UNIFORM_LIGHTCOLOR[] = "LIGHT_COLOR";
				constexpr char DEFAULT_FRAGMENT_UNIFORM_OBJECTCOLOR[] = "OBJECT_COLOR";
				

			}
			namespace SHADERKEY
			{
				constexpr char DEFAULT_VERTEX_FRAGMENT[] = "DEFAULT_VERTEX_FRAGMENT";
				constexpr char DEFAULT_VERTEX_FRAGMENT_V01[] = "DEFAULT_VERTEX_FRAGMENT_V01";
			}
			namespace DEFAULTVALUE
			{
				const MathLib::Color4 defaultColor = MathLib::Color4(1.0f, 1.0f, 1.0f, 1.0f);
			}
		};

		class EngineSetting
		{
		private:
			inline static MathLib::Rect *surface = nullptr;
		public:
			EngineSetting(MathLib::Rect _surface)
			{
				surface = new MathLib::Rect(_surface);
			}
			static void SetWindowSurfaceRect(MathLib::Rect _surface)
			{
				surface->x = _surface.x;surface->y = _surface.y;
				surface->width = _surface.width;surface->height = _surface.height;
			}
			static MathLib::Rect GetWindowSurfaceRect() { return { surface->x,surface->y,surface->width,surface->height }; }
		};


		class ViewPort
		{
		private:
			MathLib::Rectf viewportRectf = {0.0f,0.0f,1.0f,1.0f};
			inline float clamp01(float value) {	return std::clamp(value, float(0), float(1));	}
			inline MathLib::Rectf RectfClamp01(MathLib::Rectf rectf) { return { clamp01(rectf.x) ,clamp01(rectf.y) ,clamp01(rectf.width) ,clamp01(rectf.height) };}
		public:
			inline MathLib::Rectf GetViewportRectf() { return RectfClamp01(viewportRectf); }
			inline void SetViewPortRectfX(float x) { viewportRectf.x = x; }
			inline void SetViewPortRectfY(float y) { viewportRectf.y = y; }
			inline void SetViewPortRectfWidth(float width) { viewportRectf.width = width; }
			inline void SetViewPortRectfHeight(float height) { viewportRectf.height = height; }
			inline void SetViewPortRectf(MathLib::Rectf rectf) { viewportRectf = RectfClamp01(rectf); }
			ViewPort(MathLib::Rectf rectf) { viewportRectf = rectf; }
			MathLib::Rect GetViewport()
			{
				viewportRectf = RectfClamp01(viewportRectf);
				MathLib::Rect surface = EngineSetting::GetWindowSurfaceRect();

				MathLib::Rect viewport = {
					static_cast<int>(std::round(surface.width * viewportRectf.x)),
					static_cast<int>(std::round(surface.height * viewportRectf.y)),
					static_cast<int>(std::round(surface.width * viewportRectf.width)),
					static_cast<int>(std::round(surface.height * viewportRectf.height))
				};
				return viewport;
			}

		};
	
}
