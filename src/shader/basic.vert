#version 130

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 Color;

void
main()
{
	Color = VertexColor;
	gl_Position = vec4( VertexPosition, 1.0 );
//	gl_Position = mat4( 10, 0, 0, 0, 0, 10, 0, 0, 0, 0, 10, 0, -10, -10, -10, 1 ) * vec4( VertexPosition, 1.0 );
}

