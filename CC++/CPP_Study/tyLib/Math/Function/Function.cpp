
#include "Function.h"

namespace ty
{
	namespace Math
	{
		ty_export template <typename type>
		Function<type>::Function()
		{}

		ty_export template <typename type>
		Function<type>::Function( const char * exp)
		{}

		ty_export template <typename type>
		Function<type>::Function( const std::string exp)
		{}

		ty_export template <typename type>
				  template <typename funtype>
		Function<type>::Function( funtype fun )
		{}

	}
}
