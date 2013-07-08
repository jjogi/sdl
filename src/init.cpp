#include "game.h"

#include <fstream>
#include <sstream>

const
char *
read_file( const char *filename )
{
	std::ifstream in( filename );
	if ( !in )
	{
		return NULL;
	}

	std::ostringstream code;

	while ( in.good() )
	{
		int c = in.get();
		if ( !in.eof() )
			code << (char) c;
	}

	in.close();

	return (char *) code.str().c_str();
}

bool
game::OnInit()
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		return false;
	}

	// TODO necessary?!?
	atexit( SDL_Quit );

	if ( ( surface = SDL_SetVideoMode( width, height, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL ) ) = NULL )
	{
		return false;
	}

	glClearColor( 0, 0, 0, 0 );
	glClearDepth( 1.0f );

	glViewport( 0, 0, width, height );

	// initialize glew
	GLenum err = glewInit();

	if ( err != GLEW_OK )
	{
		fprintf( stderr, "Error initializing GLEW: %s\n", glewGetErrorString(err) );
	}

	// load vertex shader
	GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

	const GLchar *vertexSource = read_file( "src/shader/basic.vert" );
	if ( vertexSource == NULL )
	{
		fprintf( stderr, "Error reading vertex shader\n" );
		return false;
	}
	const GLchar *vertexCodeArray[] = { vertexSource };
	glShaderSource( vertexShader, 1, vertexCodeArray, NULL );

//	free( (void *) vertexSource );

	// compile vertex shader
	glCompileShader( vertexShader );

	// load fragment shader
	GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );

	const GLchar *fragmentSource = read_file( "src/shader/basic.frag" );
	if ( fragmentSource == NULL )
	{
		fprintf( stderr, "Error reading fragment shader\n" );
		return false;
	}
	const GLchar *fragmentCodeArray[] = { fragmentSource };
	glShaderSource( fragmentShader, 1, fragmentCodeArray, NULL );

//	free( (void *) fragmentSource );

	// compile fragment shader
	glCompileShader( fragmentShader );

	// create shader program
	GLuint programHandle = glCreateProgram();

	glAttachShader( programHandle, vertexShader );
	glAttachShader( programHandle, fragmentShader );

	// bind attributes
	glBindAttribLocation( programHandle, 0, "VertexPosition" );
	glBindAttribLocation( programHandle, 1, "VertexNormal" );

	// generate vertex array object
	GLuint vaoHandle;

	glGenVertexArrays( 1, &vaoHandle );
	glBindVertexArray( vaoHandle );

	// generate vertex buffer objects
	GLuint vboHandles[3];
	glGenBuffers( 3, vboHandles );

	GLuint positionBufferHandle = vboHandles[0];
	GLuint normalBufferHandle = vboHandles[1];
	GLuint indexBufferHandle = vboHandles[2];

	glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle );
	glBufferData( GL_ARRAY_BUFFER, vertices.size() * sizeof( float ), &vertices[0], GL_STATIC_DRAW );

	glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle );
	glBufferData( GL_ARRAY_BUFFER, normals.size() * sizeof( float ), &normals[0], GL_STATIC_DRAW );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, vertices.size() * sizeof( int ), &elements[0], GL_STATIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glEnableVertexAttribArray( 1 );
	glEnableVertexAttribArray( 2 );

	glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL );

	glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *) NULL );

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle );
	glVertexAttribPointer( 2, 3, GL_UNSIGNED_INT, GL_FALSE, 0, (GLubyte *) NULL );

	// link shader program
	glLinkProgram( programHandle );

	glUseProgram( programHandle );
/*
	// old stuff
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glOrtho( 0, width, height, 0, 1, -1 );

	glMatrixMode( GL_MODELVIEW );

	glEnable( GL_TEXTURE_2D );

	glLoadIdentity();
*/
	load_obj( "data/objects/suzanne.obj", vertices, normals, elements );

	return true;
}

