/*
 *File		:max.h
 *Author	:tangyu
 *Date		:2011-05-27 21:58:43 
 *Version	:1.0.0
 *Modify	:
 */

#define ty_export

#ifndef _MAX_H_
#define _MAX_H_


ty_export template <typename T>
T max(T a, T b);

ty_export template <typename T>
T min(T a, T b);

ty_export template <typename T>
class Person
{
public:
	Person();
	~Person();
	//ty_exlport template<typename T>
	T test(T t);
};


#endif
