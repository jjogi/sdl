#ifndef _QUAT_H_
#define _QUAT_H_

#include <cmath>

#ifndef _VEC3_H_
#include "vec3.h"
#endif

class quat {

	private:
		// TODO q[3]/v[3] und q0/r ?!?
		double q[4];

	public:
		/***
			constructors
		***/
		quat();
		quat( double w, double x, double y, double z );
		quat( vec3 &axis, double angle );
		quat( double r, const vec3 &v ); // TODO

		/***
			destructors
		***/
		~quat();

		/***
			operator overloading
		***/

		// relational

		// arithmetic
		inline
		quat
		operator + ( const quat &o )
		const
		{
			return quat( q[0] + o[0], q[1] + o[1], q[2] + o[2], q[3] + o[3] );
		}

		inline
		quat
		operator - ( const quat &o )
		const
		{
			return quat( q[0] - o[0], q[1] - o[1], q[2] - o[2], q[3] - o[3] );
		}

		inline
		quat
		operator * ( const quat &o )
		const
		{
			vec3 v1( q[1], q[2], q[3] ), v2( o[1], o[2], o[3] );
			return quat( q[0] * o[0] - v1.dot( v2 ), v2 * q[0] + v1 * o[0] + v1.cross( v2 ) );
		}

		// compound assignment
		inline
		quat &
		operator += ( const quat &o )
		{
			this->q[0] += o[0];
			this->q[1] += o[1];
			this->q[2] += o[2];
			this->q[3] += o[3];

			return *this;
		}

		inline
		quat &
		operator -= ( const quat &o )
		{
			this->q[0] -= o[0];
			this->q[1] -= o[1];
			this->q[2] -= o[2];
			this->q[3] -= o[3];

			return *this;
		}

		inline
		quat &
		operator *= ( const quat &o )
		{
			vec3 v1( q[1], q[2], q[3] ), v2( o[1], o[2], o[3] );
			this->q[0] = this->q[0] * o[0] - v1.dot( v2 );
			vec3 tmp( v2 * this->q[0] + v1 * o[0] + v1.cross( v2 ) );
			this->q[1] = tmp[1];
			this->q[2] = tmp[2];
			this->q[3] = tmp[3];

			return *this;
		}

		// other
		inline
		double &
		operator [] ( const int i )
		{
			return q[i];
		}

		// TODO nötig???
		inline
		double
		operator [] ( int i )
		const
		{
			return q[i];
		}

		/***
			quaternion functions
		***/
		double
		norm()
		{
			return sqrt( q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3] );
		}

		void
		conjugate()
		{
			q[1] = -q[1];
			q[2] = -q[2];
			q[3] = -q[3];
		}

};

#endif

