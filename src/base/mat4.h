#ifndef _MAT4_H_
#define _MAT4_H_

class mat4 {

	private:
		double m[16];

	public:
		/***
			constructors
		***/
		mat4();
		mat4( double a00, double a01, double a02, double a03,
			double a10, double a11, double a12, double a13,
			double a20, double a21, double a22, double a23,
			double a30, double a31, double a32, double a33 );
		mat4( const mat4 &m );

		/***
			destructors
		***/
		~mat4();

		/***
			operator overloading
		***/

		// relational

		// arithmetic

		// compound assignment

		// other

		/***
			matrix functions
		***/

};

#endif

