/*
 *File		:Vector.h
 *Author	:tangyu
 *Date		:2011-06-01 12:40:23 
 *Version	:1.0.0
 *Modify	:2011-06-02 12:40:27 
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "../../Core/tyLib.h"

#include "../../Exception/_Exception.h"


namespace ty
{
	namespace Math
	{
		using namespace ty::ErrorHandle;
		ty_export template <typename type>
		class Vector	:	public Object
		{
		public:
			Vector();
			Vector(ty_size n);
			template<typename datatype>
			Vector(ty_size n , datatype * data);
			Vector(char * data);
			Vector(std::string data);

			Vector(const Vector<type> & vec);
			Vector<type> & operator=( const Vector<type> &vec);
		
		private:
			void Allocate(ty_size n);
		public:
			~Vector();

			Vector<type> Add		( const Vector<type> & another ) const ;
			Vector<type> Minuse		( const Vector<type> & another ) const ;

			template <typename multitype>
			Vector<type> Multiple	( const multitype & coef ) const ;

			type		 InnerProductor	( const Vector<type> & another ) const ;
			Vector<type> OuterProductor	( const Vector<type> & another ) const ;
			//TODO:to over the design
			template <typename Fun>	
			Vector<type> DotToDotOperate( const Vector<type> & another , Fun & fun ) const ;

			Vector<type> Combine		( const Vector<type> & another ) const ;

			Vector<type> operator+( const Vector<type> & another ) const ;
			Vector<type> operator-( const Vector<type> & another ) const ;
			template <typename multitype>
			Vector<type> operator*( const multitype & coef		  ) const ;

			type	&	 operator[](ty_size index);
			type		 operator[](ty_size index) const;

			ty_size		 Size() const 
			{
				return this->demension;
			}
			
//			template<typename type>
//			template <typename multitype>
//			friend Vector<type> operator*( const multitype & coef	, const Vector<type> & another );
			//friend Vector<type> operator*( const Vector<type> & another, const multitype & coef	 );
			
			type		 Norm			() const;

			bool		 Correlation	(const Vector<type> & another );

			template <typename out>
			void PrintVector(out &disp=std::cout) const ;
			
		private:
			ty::ty_size		demension	;
			type *			vector_data	;		
		};
	}
}


#endif
