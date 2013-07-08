#ifndef _VEC3_H_
#define _VEC3_H_

#include <cmath>

class vec3 {

	private:
		double v[3];

	public:
		/***
			constructors
		***/
		vec3();
		vec3( double x, double y, double z );
		vec3( const vec3 &o );

		/***
			destructors
		***/
		~vec3();

		/***
			operator overloading
		***/

		// relational
		inline
		bool
		operator == ( const vec3 &o )
		{
			return v[0] == o[0] && v[1] == o[1] && v[2] == o[2];
		}

		// arithmetic
		inline
		vec3
		operator + ( const vec3 &o )
		const
		{
			return vec3( v[0] + o[0], v[1] + o[1], v[2] + o[2] );
		}

		inline
		vec3
		operator - ( const vec3 &o )
		const
		{
			return vec3( v[0] - o[0], v[1] - o[1], v[2] - o[2] );
		}

		inline
		vec3
		operator * ( const double s )
		const
		{
			return vec3( v[0] * s, v[1] * s, v[2] * s );
		}

		inline
		vec3
		operator / ( const double s )
		const
		{
			return vec3( v[0] / s, v[1] / s, v[2] / s );
		}

		// compound assignment
		inline
		vec3 &
		operator += ( const vec3 &o )
		{
			this->v[0] += o[0];
			this->v[1] += o[1];
			this->v[2] += o[2];

			return *this;
		}

		inline
		vec3 &
		operator -= ( const vec3 &o )
		{
			this->v[0] -= o[0];
			this->v[1] -= o[1];
			this->v[2] -= o[2];

			return *this;
		}

		inline
		vec3 &
		operator *= ( const double s )
		{
			this->v[0] *= s;
			this->v[1] *= s;
			this->v[2] *= s;

			return *this;
		}

		inline
		vec3 &
		operator /= ( const double s )
		{
			this->v[0] /= s;
			this->v[1] /= s;
			this->v[2] /= s;

			return *this;
		}

		// other
		inline
		double &
		operator [] ( const int i )
		{
			return v[i];
		}

		// TODO nötig???
		inline
		double
		operator [] ( int i )
		const
		{
			return v[i];
		}

		/***
			vector functions
		***/
		inline
		double
		length()
		{
			return sqrt( v[0] * v[0] + v[1] * v[1] + v[2] * v[2] );
		}

		inline
		vec3
		cross( const vec3 &o )
		{
			return vec3( v[1] * o[2] - v[2] * o[1], v[2] * o[0] - v[0] * o[2], v[0] * o[1] - v[1] * o[0] );
		}

		inline
		double
		dot( const vec3 &o )
		{
			return v[0] * o[0] + v[1] * o[1] + v[2] * o[2];
		}

		inline
		void
		normalize()
		{
			double l = this->length();
			v[0] /= l;
			v[1] /= l;
			v[2] /= l;
		}

		inline
		double
		min()
		{
			if ( v[0] < v[1] )
				return v[0] < v[2] ? v[0] : v[2];
			else
				return v[1] < v[2] ? v[1] : v[2];
		}

		inline
		double
		max()
		{
			if ( v[0] > v[1] )
				return v[0] > v[2] ? v[0] : v[2];
			else
				return v[1] > v[2] ? v[1] : v[2];
		}

};

#endif

