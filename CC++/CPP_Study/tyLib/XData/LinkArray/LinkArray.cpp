/*
 *File		:LinkArray.cpp
 *Author	:tangyu
 *Date		:2011-05-27 22:14:42 
 *Version	:1.0.0
 *Modify	:
 */

#include <iostream>


#include "LinkArray.h"

namespace ty
{
	namespace XData
	{
		/**
		 *Chinese:构造函数
		 *English:Construction
		 */
		ty_export template <typename index_type, typename value_type>
		LinkArray<index_type , value_type>::LinkArray()
		{
			lastError=0;
		}
		
		/*
		 *Name		:	
		 *Function	:	Chinese:析构函数         English:DisConstruction
		 *Arguement	:	None
		 *Return	:	None
		 *Using		:	None
		 */
		ty_export template <typename index_type, typename value_type>
		LinkArray<index_type , value_type>::~LinkArray()
		{
		}


		
		/*
		 *Name		:	Add
		 *Function	:	Chinese:向关联数组中添加一个元素
		 *Arguement	:	index:元素索引    value:元素值
		 *Return	:	None
		 *Using		:	
		 */
		ty_export template <typename index_type, typename value_type>
		void LinkArray<index_type , value_type>::Add(index_type index , value_type value)
		{
			linkPair temp={index,value};
			this->arr_data.push_back(temp);
		}

		
		/*
		 *Name		:	Remove
		 *Function	:	Chinese:从关联数组中移除一个元素
		 *Arguement	:	index:索引值
		 *Return	:	
		 *Using		:	
		 */
		ty_export template <typename index_type, typename value_type>
		void LinkArray<index_type , value_type>::Remove(index_type index)
		{
			ArrayIterator it;
			for(it=this->arr_data.begin();it<this->arr_data.end()+1;it++)
			{
				if((*it).index==index)
				{
					this->arr_data.erase(it);			
				}
				//cout<<(*it).value<<endl;
			}
		}


		/*
		 *Name		:	Remove
		 *Function	:	Chinese:从关联数组中移除值为value的所有元素
		 *Arguement	:	value
		 *Return	:	
		 *Using		:	
		 */
		ty_export template <typename index_type, typename value_type>
		void LinkArray<index_type , value_type>::Remove(value_type value)
		{
			ArrayIterator it;
			for(it=this->arr_data.begin();it<this->arr_data.end()+1;it++)
			{
				if((*it).value==value)
				{
					this->arr_data.erase(it);			
				}
				//cout<<(*it).value<<endl;
			}
		}
		
			
		/*
		 *Name		:	PrintArray
		 *Function	:	Chinese:打印数组
		 *Arguement	:	
		 *Return	:	
		 *Using		:	
		 */
		ty_export template <typename index_type, typename value_type>
		template <typename out >
		void LinkArray<index_type , value_type>::PrintArray(out &disp) const
		{
			if(disp==std::cout)
			{
				disp<<"Data are as follows!"<<std::endl;
				disp<<"index		value"	<<std::endl;
				for(ty_size i=0;i<this->arr_data.size();i++)
				{
					disp<<arr_data[i].index<<"		"<<arr_data[i].value<<std::endl;
				}
				return ;
			}
			disp<<"Data are as follows!\n";
			disp<<"index		value  \n";
			for(ty_size i=0;i<this->arr_data.size();i++)
			{
				disp<<arr_data[i].index<<"		"<<arr_data[i].value<<"\n";
			}
			return ;
			/*
				disp.WriteLine("Data are as follows!");
				disp.WriteLine("index 		value "	 );
				for(ty_size i=0;i<this->arr_data.size();i++)
				{
					disp.Write(arr_data[i].index);disp.Write("		");disp.WriteLine(arr_data[i].value);
				}	
			*/	
			
		}


		/*
		 *Name		:	[]()
		 *Function	:	Chinese:重载[]运算符
		 *Arguement	:	index:元素索引	
		 *Return	:	value_type:返回index对应值
		 *Using		:	arr["a"];
		 */
		ty_export template <typename index_type, typename value_type>
		value_type & LinkArray<index_type , value_type>::operator [](index_type index)
		{
			for(ty_size i=0;i<this->arr_data.size();i++)
			{
				if(this->arr_data[i].index==index)
				{
					this->lastError=ErrorHandle::OK;
					return this->arr_data[i].value;	
				}
				
			}
			this->lastError=ErrorHandle::NOTFOUND;
			throw ErrorHandle::NotFound();
			//return value_type();
		}


		/*
		 *Name		:	[]()
		 *Function	:	Chinese:重载[]运算符
		 *Arguement	:	index:元素索引	
		 *Return	:	value_type:返回index对应值
		 *Using		:	arr["a"];
		 */
		ty_export template <typename index_type, typename value_type>
		value_type LinkArray<index_type , value_type>::operator [](index_type index) const
		{
			for(ty_size i=0;i<this->arr_data.size();i++)
			{
				if(this->arr_data[i].index==index)
				{
					this->lastError=ErrorHandle::OK;
					return this->arr_data[i].value;	
				}
				
			}
			this->lastError=ErrorHandle::NOTFOUND;
			throw ErrorHandle::NotFound();
			return value_type();
		}


		/*
		 *Name		:	GetLastError
		 *Function	:	Chinese:获取最后一次操作等错误
		 *Arguement	:	None
		 *Return	:	y_errorType
		 *Using		:	
		 */
		ty_export template <typename index_type, typename value_type>
		ty::ErrorHandle::ty_errorNo LinkArray<index_type , value_type>::GetLastError()
		{
			ty::ErrorHandle::ty_errorNo temp=this->lastError;
			this->lastError	=	ty::ErrorHandle::OK;
			return temp;	
		}

	}
}



















