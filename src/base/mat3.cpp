#include "mat3.h"

mat3::mat3()
{
	m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] = m[7] = m[8] = 0.0;
}

mat3::mat3( double a00, double a01, double a02,
	double a10, double a11, double a12,
	double a20, double a21, double a22 )
{
	m[0] = a00;
	m[1] = a01;
	m[2] = a02;
	m[3] = a10;
	m[4] = a11;
	m[5] = a12;
	m[6] = a20;
	m[7] = a21;
	m[8] = a22;
}

mat3::mat3( const mat3 &o )
{
	m[0] = o[0];
	m[1] = o[1];
	m[2] = o[2];
	m[3] = o[3];
	m[4] = o[4];
	m[5] = o[5];
	m[6] = o[6];
	m[7] = o[7];
	m[8] = o[8];
}

mat3::~mat3()
{
}

double
mat3::determinant()
{
	return m[0] * m[4] * m[8] + m[1] * m[5] * m[6] + m[2] * m[3] * m[6] - m[2] * m[4] * m[6] - m[1] * m[3] * m[8] - m[0] * m[5] * m[7];
}

void
mat3::transpose()
{
	double tmp;

	tmp = m[1];
	m[1] = m[3];
	m[3] = tmp;

	tmp = m[2];
	m[2] = m[6];
	m[6] = tmp;

	tmp = m[5];
	m[5] = m[7];
	m[7] = tmp;
}

double
mat3::trace()
{
	return m[0] + m[4] + m[8];
}
/*
static
void
mat3::jacobi( const mat3 S, vec3 &e, mat3 &E )
{
	int i, k, l, m, state;
	double s, c, t, p, y;
	vec3 ind;
	bool changed[3];

	n = 3; // dimension
	E = mat3::identity;
	state = n;

	for ( k = 0; k < n; ++k )
	{
		ind[k] = maxind( k );
		e[k] = S(k, k);
		changed[k] = true;
	}

	while ( state != 0 )
	{
		m = 1;
		for ( k = 1; k < n - 1; ++k )
		{
			if ( abs( S(k, ind[k]) ) > abs( S(m, ind[m]) ) )
			{
				m = k;
			}
		}
		k = m;
		l = ind[m];
		p = S(k, l);

		y = (e[l] - e[k]) / 2.0;
		t = abs( y ) + sqrt( p * p + y * y );
		s = sqrt( p * p + t * t );
		c = t / s;
		s = p / s;
		t = p * p / t;
		if ( y < 0 )
		{
			s = -s;
			t = -t;
		}
		S(k, l) = 0.0;
		update( k, -t );
		update( l, t );
	}
}
*/
