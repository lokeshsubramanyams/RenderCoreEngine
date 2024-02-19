#version 300 es
layout (location=0) in vec3 position;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 texCoord;

uniform mat4 MODEL_MATRIX;
uniform mat4 VIEW_MATRIX;
uniform mat4 PROJECTION_MATRIX;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoords;

void main()
{
    Normal = mat3(transpose(inverse(MODEL_MATRIX))) *normal;
    TexCoords = texCoord;
    gl_Position = PROJECTION_MATRIX * VIEW_MATRIX * MODEL_MATRIX * vec4(position,1.0);
}