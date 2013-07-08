#include "quat.h"

quat::quat( double r, const vec3 &v )
{
	q[0] = r;
	q[1] = v[0];
	q[2] = v[1];
	q[3] = v[2];
}

quat::~quat()
{
}

