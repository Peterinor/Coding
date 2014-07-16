/*
 *File		:Matrix.cpp
 *Author	:tangyu
 *Date		:2011-06-02 12:41:56 
 *Version	:1.0.0
 *Modify	:
 */

#include "Matrix.h"

namespace ty
{
	namespace Math
	{
		/***********************************************************************************************/
		ty_export template<typename type>	
		Matrix<type>::Matrix()
		{
			this->lineSize	=	0;
			this->columSize	=	0;
		}

		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize )
		{
			this->lineSize	=	_lsize;
			this->columSize	=	_csize;
			for( ty_size i =0 ; i < this->columSize ; i++)
			{
				this->matrix_data.push_back( LineData(this->lineSize) );
			}
		}

		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize , type * data )
		{
			this->lineSize	=	_lsize;
			this->columSize	=	_csize;
			for( ty_size i =0 ; i < this->columSize ; i++)
			{
				this->matrix_data.push_back( LineData(this->lineSize , data+i*this->columSize ) );
			}
		}

		
		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize , LineData * data_vector )
		{
			this->lineSize	=	_lsize;
			this->columSize	=	_csize;
			for( ty_size i =0 ; i < this->columSize ; i++)
			{
				this->matrix_data.push_back(*(data_vector+i));
			}
		}

		ty_export template<typename type>	
		Matrix<type>::~Matrix()
		{}

		/******************************************************************************************************/		
		ty_export template<typename type>
		Matrix<type> Matrix<type>::Add			( const Matrix<type> & another)
		{
			if(this->lineSize!=another.lineSize || this->columSize!=another.columSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i].Add(another.matrix_data[i]);
			}
			return result;
		}

		ty_export template<typename type>
		Matrix<type> Matrix<type>::Minuse		( const Matrix<type> & another)
		{
			if(this->lineSize!=another.lineSize || this->columSize!=another.columSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i].Minuse(another.matrix_data[i]);
			}
			return result;
		}

		ty_export template<typename type>
		Matrix<type> Matrix<type>::Productor	( const Matrix<type> & another)
		{
			if(this->lineSize!=another.lineSize || this->columSize!=another.columSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//TODO:
		}

		ty_export template<typename type>
		Matrix<type> Matrix<type>::DotProductor	( const Matrix<type> & another)
		{
			if(this->lineSize!=another.lineSize || this->columSize!=another.columSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//TODO:
		}

		ty_export template<typename type>
				  template <typename multitype>			
		Matrix<type> Matrix<type>::Multiple		( const multitype    & coef    )
		{
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i].Multiple(coef);
			}
			return result;
		}



		/******************************************************************************************************/
		ty_export template<typename type>
				  template<typename out>	
		void Matrix<type>::PrintMatrix(out &disp)
		{
			if(this->lineSize==0)
			{
				disp<<"No Data to disp"<<endl;
				return ;
			}
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{	
				this->matrix_data[i].PrintVector(disp);
			}
		}
	}
}
