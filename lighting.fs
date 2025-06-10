#version 330

in vec3 fragNormal;

uniform vec3 lightDirection;
uniform vec4 colDiffuse;

out vec4 finalColor;

void main() {
    vec3 n = normalize(fragNormal);
    float diff = max(dot(n, -lightDirection), 0.0);
    finalColor = vec4(colDiffuse.rgb * diff, colDiffuse.a);
}
