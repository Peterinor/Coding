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
			this->lineSize		=	0;
			this->columnSize	=	0;
		}

		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize )
		{
			this->lineSize		=	_lsize;
			this->columnSize	=	_csize;
			for( ty_size i =0 ; i < this->lineSize ; i++)
			{
				this->matrix_data.push_back( LineData(this->columnSize) );
			}
		}

		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize , type * data )
		{
			this->lineSize		=	_lsize;
			this->columnSize	=	_csize;
			for( ty_size i =0 ; i < this->lineSize ; i++)
			{
				this->matrix_data.push_back( LineData(this->columnSize , data+i*this->columnSize ) );
			}
		}

		
		ty_export template<typename type>
		Matrix<type>::Matrix( ty_size _lsize , ty_size _csize , LineData * data_vector )
		{
			this->lineSize		=	_lsize;
			this->columnSize	=	_csize;
			for( ty_size i =0 ; i < this->lineSize ; i++)
			{
				this->matrix_data.push_back(*(data_vector+i));
			}
		}

		ty_export template<typename type>	
		Matrix<type>::~Matrix()
		{
			//TODO:maybe something needed to do someday			
		}

		/******************************************************************************************************/		
		ty_export template<typename type>
		Matrix<type> Matrix<type>::Add			( const Matrix<type> & another) const
		{
			if(this->lineSize!=another.lineSize || this->columnSize!=another.columnSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columnSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i]+another.matrix_data[i];
			}
			return result;
		}

		ty_export template<typename type>
		Matrix<type> Matrix<type>::Minuse		( const Matrix<type> & another) const
		{
			if(this->lineSize!=another.lineSize || this->columnSize!=another.columnSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columnSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i]-another.matrix_data[i];
			}
			return result;
		}

		ty_export template<typename type>
		Matrix<type> Matrix<type>::Productor	( const Matrix<type> & another) const
		{
			if(this->lineSize!=another.lineSize || this->columnSize!=another.columnSize)
			{
				throw SizeNotCompatible();
				//return ;
			}			
			Matrix<type> trans = another.Transpose();// Matrix<type>(another).Transpose();//another.Transpose();
			//trans.PrintMatrix(std::cout);			
			Matrix<type> result( this->lineSize , another.columnSize );
			for( ty_size i =0 ; i < result.lineSize ; i++ )
			{
				for( ty_size j = 0 ; j < result.columnSize ; j++ )
				{
					result.matrix_data[i][j]=this->matrix_data[i].InnerProductor(trans.matrix_data[j]);		
				}			
			}
			return result;
		}

		ty_export template<typename type>
				  template<typename Fun >
		Matrix<type> Matrix<type>::DotToDotOperate	( const Matrix<type> & another , Fun & fun ) const 
		{
			if(this->lineSize!=another.lineSize || this->columnSize!=another.columnSize)
			{
				throw SizeNotCompatible();
				//return ;
			}
			//TODO:
			Matrix<type> result( this->lineSize , this->columnSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i] = this->matrix_data[i].DotToDotOperate(another.matrix_data[i],fun );
			}
			return result;
		}

		/*
		 *Name		:	Multiple
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
				  template<typename multitype>			
		Matrix<type> Matrix<type>::Multiple		( const multitype    & coef    ) const
		{
			//Matrix<type> result(*this);
			Matrix<type> result(this->lineSize , this->columnSize );
			for( ty_size i = 0 ; i < this->lineSize ; i++ )
			{
				result.matrix_data[i]=this->matrix_data[i].Multiple(coef);
			}
			return result;
		}

		
		/*
		 *Name		:	Transpose
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Matrix<type> Matrix<type>::Transpose() const
		{
			Matrix<type> temp( this->columnSize , this->lineSize );
			type * temp_data =new type[this->lineSize];

			for( ty_size i = 0 ; i < temp.lineSize ; i++ )
			{
				for( ty_size j =0 ; j < temp.columnSize ; j++ )
				{
					temp_data[j] = this->matrix_data[j][i];
				}			
				LineData line( temp.columnSize , temp_data );	
				temp.matrix_data[i] = line;
			}

			delete temp_data;
			return temp;
		}
		
		/*
		 *Name		:	Inverse
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Matrix<type> Matrix<type>::Inverse() const
		{
			//TODO:
		}


		/*
		 *Name		:	Combine
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Matrix<type> Matrix<type>::Combine	( const Matrix<type> & another , bool line ) const
		{
			if(line)
			{
				if(this->lineSize!=another.lineSize )
				{
					throw SizeNotCompatible();
					//return ;
				}
				//TODO:
				Matrix<type> result( this->lineSize , this->columnSize + another.columnSize );
				for( ty_size i = 0 ; i < result.lineSize ; i++ )
				{
					result.matrix_data[i] = this->matrix_data[i].Combine(another.matrix_data[i]);
				}
				return result;
			}
			else
			{										
				if(this->columnSize!=another.columnSize)
				{
					throw SizeNotCompatible();
					//return ;
				}
				Matrix<type> result( this->lineSize + another.lineSize , this->columnSize );
				for( ty_size i = 0 ; i < this->lineSize ; i++ )
				{
					result.matrix_data[i] = this->matrix_data[i] ;
				}
				for( ty_size i = 0 ; i < this->lineSize ; i++ )
				{
					result.matrix_data[i+this->lineSize] = another.matrix_data[i] ;
				}
				return result;
			}
						
		}

		/******************************************************************************************************/
		/*
		 *Name		:	PrintMatrix
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
				  template<typename out>	
		void Matrix<type>::PrintMatrix(out &disp) const 
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
