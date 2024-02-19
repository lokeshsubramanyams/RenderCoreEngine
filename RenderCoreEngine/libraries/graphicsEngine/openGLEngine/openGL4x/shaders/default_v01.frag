#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 FragColor;

uniform vec3 LIGHT_DIRECTION;
uniform vec3 LIGHT_COLOR;
uniform vec3 OBJECT_COLOR;

//uniform sampler2D texture_diffuse;

void main()
{

    vec3 norm = normalize(Normal);

    float diff = max(dot(norm, -LIGHT_DIRECTION), 0.0);
    vec3 diffuse = diff * LIGHT_COLOR;

    // Combine the lighting component with the object color
    vec3 result = diffuse * OBJECT_COLOR;
    FragColor = vec4(result, 1.0);

    
    //FragColor = vec4(texture(texture_diffuse, TexCoords).rgb * result, 1.0);
}
