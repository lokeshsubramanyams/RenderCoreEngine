#version 300 es
precision mediump float;
out vec4 fragmentColor;
uniform vec4 uniformFragmentColor;
void main()
{
    fragmentColor = uniformFragmentColor;
}
