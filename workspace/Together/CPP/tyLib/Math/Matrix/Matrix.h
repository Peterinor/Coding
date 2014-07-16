/*
 *File		:Matrix.h
 *Author	:tangyu
 *Date		:2011-06-02 12:41:46 
 *Version	:1.0.0
 *Modify	:
 */
#ifndef _MATRIX_H_
#define _MATRIX_H_


#include "../../Core/tyLib.h"

#include "../Vector/_Vector.h"

#include "../../Exception/_Exception.h"

#include <vector>

namespace ty
{
	namespace Math
	{
		using namespace ty::ErrorHandle;
		ty_export template<typename type>		
		class Matrix	:	public	Object
		{
		private:
			typedef Vector<type> 				LineData;
			typedef std::vector<LineData>		MatrixData;
	
		public:
			Matrix();
			Matrix( ty_size _lsize , ty_size _csize 							);
			Matrix( ty_size _lsize , ty_size _csize , type * data 				);
			Matrix( ty_size _lsize , ty_size _csize , LineData * data_vector 	);			

			~Matrix();

			Matrix<type> Add			( const Matrix<type> & another );
			Matrix<type> Minuse			( const Matrix<type> & another );
			Matrix<type> Productor		( const Matrix<type> & another );
			Matrix<type> DotProductor	( const Matrix<type> & another );

			template <typename multitype>			
			Matrix<type> Multiple		( const multitype    & coef    );
			
			//TODO:to over the design

			template<typename out>
			void PrintMatrix			( out &disp );

		private:
			ty::ty_size lineSize	;
			ty::ty_size columSize	;

			MatrixData matrix_data	;
			
		};
	}
}


#endif
