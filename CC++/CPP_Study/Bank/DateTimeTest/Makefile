#*
#* File		:Makefile of Bank
#* Author	:tangyu
#* Date		:2011-05-26 20:56:11 
#* Version	:0.1
#* LastMod	:2011-05-26 20:56:14 
#*

#bank	:	BankMain.cpp
#	g++ -g *.cpp -o bank

c++ = g++ -g -c -Wall

datatime_src = ../DateTime.cpp ../DateTime.h
define_src = ../define.cpp ../define.h
objs = DateTime.o define.o

DTTest	:	DateTimeTest.cpp $(objs)
	g++ -g DateTimeTest.cpp $(objs) -o DTTest
DateTime.o	:	$(datatime_src)
	$(c++) ../DateTime.cpp
define.o	:	$(define_src)
	$(c++) ../define.cpp



clean	:
	rm $(objs) DTTest
