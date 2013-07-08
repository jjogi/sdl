#include "vec3.h"

vec3::vec3()
{
	v[0] = 0.0;
	v[1] = 0.0;
	v[2] = 0.0;
}

vec3::vec3( double x, double y, double z )
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

vec3::vec3( const vec3 &o )
{
	v[0] = o[0];
	v[1] = o[1];
	v[2] = o[2];
}

vec3::~vec3()
{
}

