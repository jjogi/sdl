#include "vec4.h"

vec4::vec4()
{
	v[0] = 0.0;
	v[1] = 0.0;
	v[2] = 0.0;
	v[3] = 1.0;
}

vec4::vec4( double x, double y, double z )
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = 1.0;
}

vec4::vec4( double x, double y, double z, double w )
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;
}

vec4::vec4( vec3 o )
{
	v[0] = o[0];
	v[1] = o[1];
	v[2] = o[2];
	v[3] = 1.0;
}

vec4::vec4( vec3 o, double w )
{
	v[0] = o[0];
	v[1] = o[1];
	v[2] = o[2];
	v[3] = w;
}

vec4::~vec4()
{
}

