/*
 *File		:Exception.h
 *Author	:tangyu
 *Date		:2011-05-27 12:11:58 
 *Version	:1.0.0
 *Modify	:
 */

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include "../Core/tyLib.h"

#include <exception>
using std::exception;

namespace ty
{
	namespace ErrorHandle
	{
		class Exception : public exception	,	public ty::Object
		{
		public:
			Exception() throw();
			virtual ~Exception() throw() {}
			const char * what() const throw();
			ErrorHandle::ty_exceptionType 		GetExceptionType() const;
			ErrorHandle::ty_exceptionArg		GetExceptionArg	() const;
		
		protected:
			ErrorHandle::ty_exceptionType 	exceptionType;
			ErrorHandle::ty_exceptionArg 	exceptionArg;
		};
	}
}

/***	元素操作异常		***/
namespace ty
{	
	namespace ErrorHandle
	{

		class NotFound	:	public Exception
		{
		public:
			NotFound();
			const char * what() const throw();
		};
	}
}


/***	大小不符		***/
namespace ty
{
	namespace ErrorHandle
	{
		class SizeNotCompatible	:	public Exception
		{
		public:
			SizeNotCompatible();
			const char * what() const throw();
		};
	}
}




#endif
