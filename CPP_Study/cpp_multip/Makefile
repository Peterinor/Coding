#*
#* File		:Makefile
#* Author	:tangyu
#* Date		:2011-05-26 16:49:13 
#* Version	:0.1
#* LastMod	:2011-05-26 16:49:15 
#*

multi	:	sum.o main.cpp
	@echo "Compiling main.cpp and linking...";
	@g++ -Wall main.cpp sum.o -o multi;

sum.o	:	sum.cpp	sum.h
	@echo "Compiling sum.cpp ...";
	@g++  -Wall -c sum.cpp sum.h
	
clean	:	
	@echo "Cleaning ... ";
	@rm sum.o multi;

