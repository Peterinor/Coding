/*
 *File		:Exception.cpp
 *Author	:tangyu
 *Date		:2011-05-27 12:13:52 
 *Version	:1.0.0
 *Modify	:
 */

#include "Exception.h"

/**	Exception implement	**/
namespace ty
{
	namespace ErrorHandle
	{
		Exception::Exception() throw()
		{
			this->exceptionType	=	ErrorHandle::OK;
			this->exceptionArg	=	ErrorHandle::OK;
		}

		const char * Exception::what() const throw()
		{
			return "ty_exception";
		}

		ErrorHandle::ty_exceptionType Exception::GetExceptionType() const
		{
			return this->exceptionType;	
		}
		ErrorHandle::ty_exceptionArg	Exception::GetExceptionArg	() const
		{
			return this->exceptionArg;	
		}
	}
}

/***	元素操作异常		***/
namespace ty
{
	namespace ErrorHandle
	{
		
		ty::ErrorHandle::NotFound::NotFound()
		{
			this->exceptionType		=	ty::ErrorHandle::NOTFOUND;
			this->exceptionArg		=	0;
		}	/**/
		const char * ty::ErrorHandle::NotFound::what() const throw()
		{
			return "NotFound";
		}
	}
}


namespace ty
{
	namespace ErrorHandle
	{
		
		ty::ErrorHandle::SizeNotCompatible::SizeNotCompatible()
		{
			this->exceptionType		=	ty::ErrorHandle::SIZENNTCOMPATIBLE;
			this->exceptionArg		=	0;
		}	/**/
		const char * ty::ErrorHandle::SizeNotCompatible::what() const throw()
		{
			return "SizeNoCompatible";
		}
	}
}
