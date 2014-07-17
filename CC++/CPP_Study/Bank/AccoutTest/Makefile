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


account_src = Account.cpp Account.h
accountmanage_src = AccountManage.cpp AccountManage.h
bank_src = Bank.cpp Bank.h
datatime_src = DateTime.cpp DateTime.h
exception_src = Exception.cpp Exception.h
logmanage_src = LogManage.cpp LogManage.h
logrecord_src = LogRecord.cpp LogRecord.h
else_src = define.cpp define.h

objs = Account.o AccountManage.o Bank.o DateTime.o Exception.o LogManage.o LogRecord.o define.o

bank	:	BankMain.cpp $(objs)
	g++ -g BankMain.cpp $(objs) -o bank

Account.o	:	$(account_src)
	$(c++) Account.cpp
AccountManage.o	:	$(account_src)
	$(c++) AccountManage.cpp
Bank.o	:	$(bank_src)
	$(c++) Bank.cpp
DateTime.o	:	$(datatime_src)
	$(c++) DateTime.cpp
Exception.o	:	$(exception_src)
	$(c++) Exception.cpp
LogManage.o	:	$(logmanage_src)
	$(c++) LogManage.cpp
LogRecord.o	:	$(logrecord_src)
	$(c++) LogRecord.cpp
define.o	:	$(else_src)
	$(c++) define.cpp
 



clean	:
	rm $(objs) bank
