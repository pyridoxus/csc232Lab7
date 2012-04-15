varying vec4 oColor;
varying vec3 oEyeNormal;
varying vec4 oEyePosition;

uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float roughness;
uniform vec4 specularColor;

// ADS lighting model function (adapted from Ch. 5, Graphics Shaders)
vec4 ADSLightModel( in vec3 myNormal, in vec4 myPosition, in vec4 Cs )
{
	// gl_LightSource position
	vec4 myLightPosition = gl_LightSource[0].position;

	// normal, light, view, light reflection vectors
	vec3 norm   = normalize( myNormal );
	vec3 lightv = normalize( myLightPosition.xyz - myPosition.xyz );
	vec3 viewv  = -normalize( myPosition.xyz );
	vec3 refl   = reflect( -lightv, norm );

	// ambient and diffuse light
	vec4 ambient_diffuse = Cs * (Ka + Kd*max( 0.0, dot(lightv, norm) ) );

	// specular light
	vec4 specular = vec4( 0.0, 0.0, 0.0, 1.0 );
	if( dot(lightv, viewv) > 0.0 )
	{
		specular = Ks * specularColor * pow( max( 0.0, dot(viewv, refl) ), roughness );
	}

	return clamp( vec4( ambient_diffuse + specular ), 0.0, 1.0 );
}

void main()
{
	// Compute color from ADS lighting model
	gl_FragColor   = ADSLightModel( oEyeNormal, oEyePosition, oColor );

	// Alpha value
	gl_FragColor.a = 1.0;
}
