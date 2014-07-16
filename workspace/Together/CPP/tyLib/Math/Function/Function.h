#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "../../Core/tyLib.h"

namespace ty
{
	namespace Math
	{
		const char 	    op[][5]	=	{"+"  , "-" , "*"  , "/"  ,  "^" , "&" 	};
		const char  boolop[][5]	=	{"and", "or", "not", "&&" ,  "||", "!"	};
		const char   bitop[][5]	=	{">>" , "<<", "~"  , "xor"				};

		char sym[]	=	{'x','s'};

		const char atomfun[][5] =	{"sin","cos", "tan", "cot", "log", "ln" , "exp"};
		//sin(x)*ln(3*x)+6

		template <typename type>
		class Expression	:	public	Object
		{
		public:
			type operator()( type x );
		};

		ty_export template <typename type>
		class Function		:	public	Expression<type>
		{
		public:
			Function();
			Function( const char * exp			);
			Function( const std::string exp		);
			template <typename funtype>
			Function( funtype fun 			);

			type operator()( type x );
		private:
		};
			
	}

}


#endif
