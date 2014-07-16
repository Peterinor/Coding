
cpp			=	c++

argument	=	-I/usr/local/include -L/usr/local/lib -L/usr/X11R6/lib -lglut -lGLU -lGL -lX11 -lXext -lXi -lm -Wall -o



out			=	OpenGLTest

#src			=	OpenGLTest.cpp
src			=	shape_test.c

$(out)	:	$(src)
	$(cpp) 	$(argument) 	$(out) 		$(src)

run		:	$(out)
	@./$(out)

clean	:
	rm $(out)




