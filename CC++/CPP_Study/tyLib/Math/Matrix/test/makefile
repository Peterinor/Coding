
cpp			=	c++

argument	=	-g -Wall -o 

Debug_Flag	=	-g -Wall -o 

out			=	matrix_test

test_src	=	test.cpp

$(out)	:	$(test_src)
	$(cpp) 	$(argument) 	$(out) 		$(test_src)

run		:	$(out)
	@./$(out)


debug	:	$(out)
	insight ./$(out)


clean	:
	rm $(out)

