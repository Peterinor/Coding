/*
 *File		:tyLibDefs.h
 *Author	:tangyu
 *Date		:2011-05-27 22:00:44 
 *Version	:1.0.0
 *Modify	:
 */
#ifndef _TYLIBDEFS_H_
#define _TYLIBDEFS_H_

/**是否支持模板等分离编译方式**/
#ifndef EXPORT_SUPPORT
#define TY_EXPORT
#endif

/**定义模板分离编译关键字**/
#ifndef TY_EXPORT
#define ty_export	export
#else
#define ty_export
#endif

namespace ty
{
	typedef unsigned int	ty_size		;

	/**	the father of all the classes in ty or any others ty::%		***/
	class Object
	{
	public:
		virtual ~Object(){}
	};
	
}

/**		错误和异常处理部分		**/
namespace ty
{
	namespace ErrorHandle
	{
		typedef int				ty_errorType;
		typedef int				ty_errorNo	;
	
		typedef enum ErrorType
		{	
			OK						=		0,
			NOTFOUND				=		1,
			SIZENNTCOMPATIBLE		=		2
		}ExcetionType;

		typedef enum ErrorNo
		{
		}ExcetionArg;

		typedef	 int			ty_exceptionType	;
		typedef	 int			ty_exceptionArg	;
	}
}

#endif
