varying vec4 oColor;
varying vec3 oEyeNormal;
varying vec4 oEyePosition;
 
uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float roughness;
uniform vec4 specularColor;
uniform vec4 lightPos;

// ADS lighting model function (adapted from Graphics Shaders)
vec4 ADSLightModel( in vec3 myNormal, in vec4 myPosition, in vec4 myColor )
{
       // gl_LightSource components
       vec4 myLightDiffuse  = vec4(0.5, 0.5, 0.5, 1.0);
       vec4 myLightAmbient  = vec4(0.5, 0.5, 0.5, 1.0);
       vec4 myLightSpecular = vec4(0.5, 0.5, 0.5, 1.0);
       // vec4 myLightPosition = vec4( 0.0, 0.0, 1.0, 1.0 );
       // Light position is now input from CPP.
       vec4 myLightPosition = lightPos;
 
       // gl_Material components
       vec4 myMaterialDiffuse    = myColor * Kd;
       vec4 myMaterialAmbient    = myColor * Ka;
       vec4 myMaterialSpecular   = vec4(1.0, 1.0, 1.0, 1.0) * Ks;
       float myMaterialShininess = roughness;
 
       // normal, light, view, light reflection vectors
       vec3 norm   = normalize( myNormal );
       vec3 lightv = normalize( myLightPosition.xyz - myPosition.xyz );
       vec3 viewv  = -normalize( myPosition.xyz );
       vec3 refl   = reflect( -lightv, norm );
 
       // diffuse light
       vec4 diffuse = max( 0.0, dot(lightv, norm) ) * myMaterialDiffuse * myLightDiffuse;
 
       // ambient light
       vec4 ambient = myMaterialAmbient * myLightAmbient;
 
       // specular light
       vec4 specular = specularColor;
       if( dot(lightv, viewv) > 0.0 )
       {
		float temp = pow( max( 0.0, dot(viewv, refl) ), myMaterialShininess );
              specular *= temp; 
              specular *= myMaterialSpecular;
              specular *= myLightSpecular;
       }
 
       return clamp( vec4( ambient + diffuse + specular ), 0.0, 1.0 );
}
 
void main()
{
       // Compute color from ADS lighting model
       gl_FragColor   = ADSLightModel( oEyeNormal, oEyePosition, oColor );
 
       // Alpha value
       gl_FragColor.a = 1.0;

}
