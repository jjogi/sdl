#ifndef _MAT3_H_
#define _MAT3_H_

#ifndef _VEC3_H_
#include "vec3.h"
#endif

class mat3 {

	private:
		double m[9];

	public:
		/***
			constructors
		***/
		mat3();
		mat3( double a00, double a01, double a02,
			double a10, double a11, double a12,
			double a20, double a21, double a22 );
		mat3( const mat3 &o );

		/***
			destructors
		***/
		~mat3();

		/***
			operator overloading
		***/

		// relational

		// arithmetic
		inline
		mat3
		operator + ( const mat3 &o )
		const
		{
			return mat3( m[0] + o[0], m[1] + o[1], m[2] + o[2], m[3] + o[3], m[4] + o[4], m[5] + o[5], m[6] + o[6], m[7] + o[7], m[8] + o[8] );
		}

		inline
		mat3
		operator - ( const mat3 &o )
		const
		{
			return mat3( m[0] - o[0], m[1] - o[1], m[2] - o[2], m[3] - o[3], m[4] - o[4], m[5] - o[5], m[6] - o[6], m[7] - o[7], m[8] - o[8] );
		}

		inline
		mat3
		operator * ( const mat3 &o )
		const
		{
			return mat3( m[0] * o[0] + m[1] * o[3] + m[2] * o[6], m[0] * o[1] + m[1] * o[4] + m[2] * o[7], m[0] * o[2] + m[1] * o[5] + m[2] * o[8],
				 m[3] * o[0] + m[4] * o[3] + m[5] * o[6], m[3] * o[1] + m[4] * o[4] + m[5] * o[7], m[3] * o[2] + m[4] * o[5] + m[5] * o[8],
				 m[6] * o[0] + m[7] * o[3] + m[8] * o[6], m[6] * o[1] + m[7] * o[4] + m[8] * o[7], m[6] * o[2] + m[7] * o[5] + m[8] * o[8] );
		}

		inline
		vec3
		operator * ( const vec3 &v )
		const
		{
			return vec3( m[0] * v[0] + m[1] * v[1] + m[2] * v[2], m[3] * v[0] + m[4] * v[1] + m[5] * v[2], m[6] * v[0] + m[7] * v[1] + m[8] * v[2] );
		}

		// compund assignment

		// other
		inline
		double &
		operator [] ( const int i )
		{
			return m[i];
		}

		// TODO nötig???
		inline
		double
		operator [] ( int i )
		const
		{
			return m[i];
		}

		inline
		double &
		operator () ( const int i, const int j )
		{
			return m[3 * i + j];
		}

		/***
			matrix functions
		***/
		double determinant();
		void transpose();
		double trace();

		static void jacobi( const mat3 m, vec3 &e, mat3 &E );

};

#endif

