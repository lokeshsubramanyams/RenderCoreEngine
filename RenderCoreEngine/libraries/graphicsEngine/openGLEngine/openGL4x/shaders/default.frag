#version 330 core

out vec4 fragmentColor;

uniform vec4 uniformFragmentColor;

void main()
{
  fragmentColor = vec4(1.0,1.0,1.0,0.0);
}