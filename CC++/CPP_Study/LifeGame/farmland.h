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
	/*	构造函数		*/
	Farmland(void);
	Farmland(int landsize);
	Farmland(const Farmland & src);
	Farmland(int landsize,unit_type * landdata);
	Farmland(int landsize, string landdata);
	/*	析构函数		*/
	~Farmland(void);
	/*	打印田地		*/
	void PrintLand(void);
	/*	为田地分配存储空间		*/
	void Allocate(int landsize);
	/*	清除田地的存储空间		*/
	void DeAllocate(void);
	/*	清除田地中的所有生命		*/
	void ClearLand(void);
	/*	生成下一代		*/
	string NextGeneration(void );
	/*	汇报当前的田地状况，以字符串形式返回		*/
	string ReportLandState(void );
	/*	获取一个细胞的邻居状况		*/
	int GetCellState(int i, int j);
	
	void SetLand(int landsize,string landdata);
	void SetLand(int landsize,unit_type *landdata);
	
	void SetLandData(unit_type * landdata);
	void SetLandData(string landdata);
	
	/**	获取田地大小函数		**/
	int 		GetLandSize(void ) const;
	unit_type 	GetLandData(void ) const;		/*	慎用		*/
	
	
private:
	int 			landSize;
	unit_type ** 	landData;


};



#endif
