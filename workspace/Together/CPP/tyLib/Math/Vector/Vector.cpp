/*
 *File		:Vector.cpp
 *Author	:tangyu
 *Date		:2011-06-01 12:41:05 
 *Version	:1.0.0
 *Modify	:2011-06-02 12:41:12 
 */


#include "Vector.h"


#include <cmath>

namespace ty
{
	namespace Math
	{
		ty_export template<typename type>
		Vector<type>::Vector()
		{
			this->Allocate(0);	
		}

		ty_export template<typename type>
		Vector<type>::Vector(ty_size n)
		{
			this->Allocate(n);
			for( ty_size i=0; i<this->demension ;i++ )
			{
				this->vector_data[i]=0;					
			}
		}

		ty_export template<typename type>
				  template<typename datatype>
		Vector<type>::Vector(ty_size n , datatype * data)
		{
			this->Allocate(n);
			for( ty_size i=0; i<this->demension ;i++ )
			{
				this->vector_data[i]=(type)data[i];					
			}
		}

		ty_export template<typename type>
		Vector<type>::Vector( char * data)
		{
			//TODO:
		}

		ty_export template<typename type>
		Vector<type>::Vector(std::string data)
		{	
			//TODO:to check this carefully!
			new (this) Vector<type>(data.c_str());	
		}


		/*
		 *Name		:	copy Construction and operator=
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Vector<type>::Vector(const Vector<type> &vec)
		{	
			this->Allocate(vec.demension);
			//TODO:	to comprehension this difference here!!
			//std::memcpy(this->vector_data , vec.vector_data , this->demension);
			for( ty_size i =0 ; i< this->demension ;i++ )
			{
				this->vector_data[i]=vec.vector_data[i];				
			}
			
		}

		ty_export template<typename type>
		Vector<type> & Vector<type>::operator=(const Vector<type> &vec)
		{
			//TODO:to check this carefully!
			new (this) Vector<type>(vec);
			return *this;			
		}

		
		/*
		 *Name		:	Allocate
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		void Vector<type>::Allocate(ty_size n)
		{
			this->demension=n;
			if(this->demension==0)
			{
				this->vector_data=NULL;
				return ;				
			}
			this->vector_data=new type[this->demension];
			/*
			for( ty_size i=0; i<this->demension ;i++ )
			{
				this->vector_data[i]=0;					
			}*/		
		}


		ty_export template<typename type>
		Vector<type>::~Vector()
		{
			delete this->vector_data;			
		}



		/*****************************************************************************************/
		/*
		 *Name		:	Add
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Vector<type> Vector<type>::Add( const Vector<type> & another)
		{
			if(this->demension!=another.demension)
			{
				throw SizeNotCompatible();
				//return ;	// for guarentee!				
			}
			
			Vector<type> result(this->demension,this->vector_data);
			//return Vector<type>( result );
			for(ty_size i = 0 ; i < result.demension ; i++)
			{
				result.vector_data[i]+=another.vector_data[i];		
			}
			return result;
		}

		
		/*
		 *Name		:	Minuse
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Vector<type> Vector<type>::Minuse( const Vector<type> & another)
		{
			if(this->demension!=another.demension)
			{
				throw SizeNotCompatible();
				//return ;	// for guarentee!				
			}
			
			Vector<type> result(this->demension,this->vector_data);
			//return Vector<type>( result );
			for(ty_size i = 0 ; i < result.demension ; i++)
			{
				result.vector_data[i]-=another.vector_data[i];		
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
		Vector<type> Vector<type>::Multiple( const multitype & coef)
		{
			Vector<type> result(this->demension,this->vector_data);
			//return Vector<type>( result );
			for(ty_size i = 0 ; i < result.demension ; i++)
			{
				result.vector_data[i]*=coef;	
			}
			return result;				
		}

		
		/*
		 *Name		:	InnerProductor
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		type Vector<type>::InnerProductor( const Vector<type> &another)
		{
			if(this->demension!=another.demension)
			{
				throw SizeNotCompatible();
				//return ;	// for guarentee!				
			}	
			type result=0;
			for(ty_size i =0 ; i<this->demension ; i++)
			{
				result+=this->vector_data[i]*another.vector_data[i];		
			}
			return result;					
		}

		
		/*
		 *Name		:	OuterProductor
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		Vector<type> Vector<type>::OuterProductor( const Vector<type> &another)
		{
			if(this->demension!=another.demension)
			{
				throw SizeNotCompatible();
				//return ;	// for guarentee!				
			}		
			//TODO:	
			return *this;
		}

		
		/*
		 *Name		:	Norm
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
		type 		Vector<type>::Norm() const
		{
			type result=0;	
			result=0;
			for (ty_size i =0 ; i < this->demension ;i++ )
			{
				result+=this->vector_data[i]*this->vector_data[i];
			}
			return std::sqrt(result);			
		}

		
		/*
		 *Name		:	Correlation
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>		
		bool		Vector<type>::Correlation(const Vector<type> & another)
		{
			if(this->demension!=another.demension)
			{
				throw SizeNotCompatible();
				//return ;	// for guarentee!				
			}	
			if(! this->Norm() * another.Norm())
				return true;
			ty_size i = 0 ;
			for( i = 0 ; i < this->demension ; i++ )
			{
				if((int)this->vector_data[i])
					break;
			}
			type coef = another.vector_data[i]/this->vector_data[i];
			for( ty_size k = 0 ; k < this->demension ; k++ )
			{
				if(another.vector_data[k]!=coef*this->vector_data[k])
					return false;				
			}
			return true;			
		}


		/**********************************************************************/
		/*
		 *Name		:	PrintVector
		 *Function	:	
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template<typename type>
				  template<typename out>
		void Vector<type>::PrintVector( out &disp) const
		{
			if(disp==std::cout)
			{
#if	TY_DEBUG
				disp<<"Vector is as follows :"<<std::endl;
#endif
				disp<<"("<<this->vector_data[0];
				for( ty_size i=1; i<this->demension ;i++ )
				{
					disp<<","<<this->vector_data[i];					
				}
				disp<<")"/*"."*/<<std::endl;
				
			}
			
		}
	}

}
