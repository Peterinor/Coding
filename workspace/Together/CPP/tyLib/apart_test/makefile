
cpp			=	c++

argument	=	-Wall -o


out			=	apart_test

test_src	=	apart_test.cpp max.h max.cpp _max.h

$(out)	:	$(test_src)
	$(cpp) 	$(argument) 	$(out) 		$(test_src)

run		:	$(out)
	@./$(out)

clean	:
	rm $(out)




