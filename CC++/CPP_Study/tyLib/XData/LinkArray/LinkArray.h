/*
 *File		:LinkArray.h
 *Author	:tangyu
 *Date		:2011-05-27 22:01:32 
 *Version	:1.0.0
 *Modify	:
 */

#include "../../Core/tyLib.h"


#include "../../Exception/_Exception.h"

#include <vector>
using std::vector;

namespace ty
{
	namespace XData
	{
		//ty_export template <typename pair>
		ty_export template <typename index_type, typename value_type>
		class LinkArray	:	public ty::Object
		{
		public:
			LinkArray();
			/**	No Need Of Copy Construction Function**/
			~LinkArray();

			void 	Add(index_type index , value_type value);
			void	Remove(index_type index);
			void	Remove(value_type value);
			
			template <typename out >
			void 	PrintArray(out &disp=std::cout) const ;

			value_type & operator[](index_type index);
			value_type	 operator[](index_type index) const ;

			ErrorHandle::ty_errorNo	GetLastError() ;	

			//template <typename _index_type=index_type, typename _value_type=index_type>
			struct linkPair
			{
				index_type index;
				value_type value;
			};

			typedef 	vector<linkPair >	ArrayData;
			typedef typename 	ArrayData::iterator ArrayIterator;
			

		private:
			ArrayData						arr_data;
			
			ErrorHandle::ty_errorNo			lastError;

		};		
		
	}
}


















