#*
#* File		:Makefile
#* Author	:tangyu
#* Date		:2011-05-25 16:41:19 
#* Version	:0.1
#* LastMod	:2011-05-25 16:41:21 
#*
 
lifegame_src = lifegame.h lifegame.cpp
farmland_src = farmland.h farmland.cpp
main_src     = main.cpp

object       =	lifegame.o farmland.o

lifegame	:	$(object) $(main_src)
	@echo '----linking...'
	@g++ -Wall main.cpp	$(object) -o lifegame
	@echo '----running lifegame using ./lifegame'
	@#@./lifegame

farmland.o	:	$(farmland_src)
	@echo '----compiling farmland.cpp...'
	@g++ -Wall -c farmland.cpp -o farmland.o	
	
lifegame.o	:	$(lifegame_src) $(farmland_src)
	@echo '----compiling lifegame.cpp...'
	@g++ -Wall -c lifegame.cpp -o lifegame.o	
	
clean:
	@echo 'cleanning the project now...'
	@rm $(object) lifegame
