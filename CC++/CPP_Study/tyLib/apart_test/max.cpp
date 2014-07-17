/*
 *File		:max.cpp
 *Author	:tangyu
 *Date		:2011-05-27 22:00:15 
 *Version	:1.0.0
 *Modify	:
 */

#include "max.h"
 
ty_export template<typename T>
T max(T a ,T b)
{
	return a>b	?	a	:	b;

}

ty_export template<typename T>
T min(T a, T b)
{
	return a>b	?	b	:	a;
	
}


ty_export template<typename T> 
Person<T>::Person()
{
}

ty_export template<typename T> 
Person<T>::~Person()
{
}

ty_export template<typename T> 
T Person<T>::test(T a)
{
	return a;
}
