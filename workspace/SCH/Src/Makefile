#*
#* File		:Makefile
#* Author	:tangyu
#* Date		:2011-05-26 16:49:13 
#* Version	:0.1
#* LastMod	:2011-05-26 16:49:15 
#*

src = SCH.cpp SCHMain.cpp Sig.cpp

obj = Sig.o SCH.o

cc= g++  -Wall

SCH	:	Sig.o SCH.o SCHMain.cpp
	@echo "Compiling SCHMain.cpp and linking...";
	$(cc) SCHMain.cpp Sig.o SCH.o -o SCH

Sig.o	:	Sig.cpp
	@echo "Compiling Sig.cpp...";
	$(cc) -c Sig.cpp
	
SCH.o	:	SCH.cpp
	@echo "Compiling SCH.cpp...";
	$(cc) -c SCH.cpp
clean	:
	@rm $(obj) SCH
