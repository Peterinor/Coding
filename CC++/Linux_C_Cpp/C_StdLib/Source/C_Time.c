#include <stdio.h>
#include <time.h>

int main(void )
{
	struct tm t;
	/**************************************获取系统时间******************************************/
	/*
	 * time()
	 * 库注释：	Return the current time and put it in *TIMER if TIMER is not NULL.
	 */
	time_t now=time(NULL);
	/*
	 * localtime()
	 * 库注释：	Return the `struct tm' representation of TIMER in the local timezone.
	 */
	t=(*localtime(&now));

	printf("Data Time Now:\n");
	printf("Time Now Is: %d-%d-%d   %d:%d:%d\n",t.tm_year+1900,t.tm_mon+1,t.tm_mday,  t.tm_hour,t.tm_min,t.tm_sec);
	printf("year 	: %d\n",t.tm_year+1900);
	printf("month	: %d\n",t.tm_mon+1);	/* Month.	[0-11] */
	printf("day  	: %d\n",t.tm_mday);
	printf("hour 	: %d\n",t.tm_hour);
	printf("minuter : %d\n",t.tm_min);
	printf("second	: %d\n",t.tm_sec);

	/**OR ：*/
	/*
	 *asctime()
	 *库注释：	Return a string of the form "Day Mon dd hh:mm:ss yyyy\n"
	 */
	char * str_time=asctime(&t);
	printf("Time Now Is: %s\n",str_time);

	/**OR ：*/
	/*
	 * ctime()，功能上禹asctime一样，只是使用的参数不同罢了，ctime直接使用time()获取的time_t型数值，
	 * 而asctime则要借助于localtime，由此可知，ctime实则完成了localtime和asctime两者的功能！！
	 * 库注释	：Equivalent to `asctime (localtime (timer))'.
	 */
	char * time_str=ctime(&now);
	printf("Time Now Is: %s\n",time_str);

	/**************************************更改系统时间******************************************/

	return 0;
}
