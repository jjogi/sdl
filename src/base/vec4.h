#ifndef _VEC4_H_
#define _VEC4_H_

#ifndef _VEC3_H_
#include "vec3.h"
#endif

class vec4 {

	private:
		double v[4];

	public:
		/***
			constructors
		***/
		vec4();
		vec4( double x, double y, double z );
		vec4( double x, double y, double z, double w );
		vec4( vec3 v );
		vec4( vec3 v, double w );

		/***
			destructors
		***/
		~vec4();

		/***
			operator overloading
		***/

		// relational

		// arithmetic

		// compound assignment

		// other

		/***
			vector functions
		***/

};

#endif

