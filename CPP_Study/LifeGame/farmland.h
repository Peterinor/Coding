/*
 * File		:farmland.h
 * Author	:tangyu
 * Date		:2011-05-22 22:33:24 
 * Version	:0.1
 * LastMod	:2011-05-24 22:33:27 
 */
#ifndef _FARMLAND_H_
#define _FARMLAND_H_

#include<string>

using std::string;


typedef bool unit_type;


#define _LIFE	'@'
#define _DEATH	'+'

#define _TOO_CROWDED	3
#define _TOO_LONELY	2


class Farmland
{
public:
	/*	���캯��		*/
	Farmland(void);
	Farmland(int landsize);
	Farmland(const Farmland & src);
	Farmland(int landsize,unit_type * landdata);
	Farmland(int landsize, string landdata);
	/*	��������		*/
	~Farmland(void);
	/*	��ӡ���		*/
	void PrintLand(void);
	/*	Ϊ��ط���洢�ռ�		*/
	void Allocate(int landsize);
	/*	�����صĴ洢�ռ�		*/
	void DeAllocate(void);
	/*	�������е���������		*/
	void ClearLand(void);
	/*	������һ��		*/
	string NextGeneration(void );
	/*	�㱨��ǰ�����״�������ַ�����ʽ����		*/
	string ReportLandState(void );
	/*	��ȡһ��ϸ�����ھ�״��		*/
	int GetCellState(int i, int j);
	
	void SetLand(int landsize,string landdata);
	void SetLand(int landsize,unit_type *landdata);
	
	void SetLandData(unit_type * landdata);
	void SetLandData(string landdata);
	
	/**	��ȡ��ش�С����		**/
	int 		GetLandSize(void ) const;
	unit_type 	GetLandData(void ) const;		/*	����		*/
	
	
private:
	int 			landSize;
	unit_type ** 	landData;


};



#endif
