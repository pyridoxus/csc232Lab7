varying vec4 oColor;
varying vec3 oEyeNormal;
varying vec4 oEyePosition;

void main()
{
       // Transform normal and position to eye space (for fragment shader)
       oEyeNormal    = normalize( vec3( gl_NormalMatrix * gl_Normal ) );
       oEyePosition  = gl_ModelViewMatrix * gl_Vertex;       
 
       // Assign color (for fragment shader)
       oColor        = gl_Color;
 
       // Transform vertex to clip space for fragment shader
       gl_Position   = gl_ModelViewProjectionMatrix * gl_Vertex;
}
