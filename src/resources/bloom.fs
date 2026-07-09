#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

void main()
{
    vec4 texColor = texture(texture0, fragTexCoord);
    vec4 bloom = vec4(0.0);
    
    float dx = 2.0 / 720.0;
    float dy = 2.0 / 720.0;

    // 7x7 box blur extracting bright pixels
    for(int x = -3; x <= 3; x++) 
    {
        for(int y = -3; y <= 3; y++) 
        {
            vec4 c = texture(texture0, fragTexCoord + vec2(float(x) * dx, float(y) * dy));
            // Calculate brightness
            float brightness = dot(c.rgb, vec3(0.2126, 0.7152, 0.0722));
            if(brightness > 0.75) 
            {
                // Only add to bloom if pixel is bright enough
                bloom += c * 0.004;
            }
        }
    }
    
    finalColor = texColor + bloom * 0.4;
}
