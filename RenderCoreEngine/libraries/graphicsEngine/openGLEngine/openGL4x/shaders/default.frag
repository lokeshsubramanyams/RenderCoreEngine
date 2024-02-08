#version 330 core
out vec4 fragmentColor;
uniform vec4 uniformFragmentColor;
void main(){
fragmentColor = uniformFragmentColor;
}