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

			Matrix<type> Add			( const Matrix<type> & another ) const ;
			Matrix<type> Minuse			( const Matrix<type> & another ) const ;
			Matrix<type> Productor		( const Matrix<type> & another ) const ;
			
			template <typename Fun>	
			Matrix<type> DotToDotOperate( const Matrix<type> & another , Fun & fun ) const ;

			template <typename multitype>			
			Matrix<type> Multiple		( const multitype    & coef    ) const ;

			//转置
			Matrix<type> Transpose	() const ;
			//求逆
			Matrix<type> Inverse	() const;

			Matrix<type> Combine	( const Matrix<type> & another , bool line = true ) const;
			
			//TODO:to over the design

			template<typename out>
			void PrintMatrix		( out &disp ) const ;

		private:
			ty::ty_size lineSize	;
			ty::ty_size columnSize	;

			MatrixData matrix_data	;
			
		};//转置 逆矩阵
	}
}


#endif
