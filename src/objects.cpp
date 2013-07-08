#include "game.h"

#include <string>
#include <iostream>
#include <fstream>

void
game::load_obj( const char *filename, std::vector<float> &vertices, std::vector<float> &normals, std::vector<int> &elements )
{
	std::ifstream in( filename );

	std::string c;
	float vx, vy, vz;
	int f1, f2, f3;

	while ( in >> c )
	{
		if ( c == "v" )
		{
			in >> vx >> vy >> vz;
//			vec4 v( vx, vy, vz );
			vertices.push_back( vx );
			vertices.push_back( vy );
			vertices.push_back( vz );
		}
		if (c == "f")
		{
			in >> f1 >> f2 >> f3;
			elements.push_back( f1 - 1 );
			elements.push_back( f2 - 1 );
			elements.push_back( f3 - 1 );
		}
	}

	printf( "read %s\nvertices: %ld\nfaces: %ld\n", filename, vertices.size() / 3, elements.size() / 3 );

	in.close();
}

