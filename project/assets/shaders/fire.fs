[OPENGL VERSION]

in vec3 fragmentNormal;
in vec2 fragmentUV;
in vec3 fragmentWorldPos;

uniform sampler2D albedoMap;
uniform sampler2D specularMap;
uniform sampler2D roughnessMap;
uniform sampler2D metallicMap;
uniform sampler2D directionalShadowMap;

uniform sampler2D albedoFireMap;

uniform bool useAlbedoMap;
uniform bool useSpecularMap;
uniform bool useRoughnessMap;
uniform bool useMetallicMap;
uniform bool useDirectionalLight;
uniform bool useDirectionalShadow;

uniform vec4 albedoValue;
uniform float specularValue;
uniform float roughnessValue;
uniform float metallicValue;

uniform vec3 cameraPosition;
uniform vec3 ambientLightColor;
uniform float ambientLightIntensity;

uniform vec3 directionalLightDirection;
uniform vec3 directionalLightColor;
uniform float directionalLightIntensity;
uniform mat4 directionalLightSpaceMatrix;

const int MAX_POINT_LIGHTS = 8;
uniform int pointLightCount;
uniform vec3 pointLightPositions[MAX_POINT_LIGHTS];
uniform vec3 pointLightColors[MAX_POINT_LIGHTS];
uniform float pointLightIntensities[MAX_POINT_LIGHTS];
uniform float pointLightRanges[MAX_POINT_LIGHTS];

out vec4 color;

vec3 SRGBToLinear(vec3 value)
{
    return pow(max(value, vec3(0.0)), vec3(2.2));
}

// Deleted a bunch of stuff that's not relevant to fire because as a light source it doesn't have a shadow

void main()
{
    vec3 n = normalize(fragmentNormal);
    vec3 viewDir = normalize(cameraPosition - fragmentWorldPos);

    vec4 albedoTex = useAlbedoMap ? texture(albedoFireMap, fragmentUV) : vec4(1.0);
    vec4 albedo = albedoValue * albedoTex;
    vec3 albedoLinear = SRGBToLinear(albedo.rgb);

    if (albedo.a < 0.001)
        discard;

    float specularTex = useSpecularMap ? texture(specularMap, fragmentUV).r : 1.0;
    float roughnessTex = useRoughnessMap ? texture(roughnessMap, fragmentUV).r : 1.0;
    float metallicTex = useMetallicMap ? texture(metallicMap, fragmentUV).r : 1.0;

    float specular = clamp(specularValue * specularTex, 0.0, 1.0);
    float roughness = clamp(roughnessValue * roughnessTex, 0.0, 1.0);
    float metallic = clamp(metallicValue * metallicTex, 0.0, 1.0);

    vec3 ambientLinear = clamp(ambientLightColor, vec3(0.0), vec3(1.0)) * max(ambientLightIntensity, 0.0);
    vec3 litColor = albedoLinear * ambientLinear;

    // To make the fire always full brightness just use albedo directly
    color = albedo;
}
