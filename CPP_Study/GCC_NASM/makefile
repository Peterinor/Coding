
cpp			=	gcc

argument	=	-c -o

c_argu		=	-Wall -c -o

asm_argu	=	-f elf -o

c_out		=	testc.o

asm_out		=	testa.o

out			=	test

c_src		=	test.c

asm_src		= 	test.asm 

src = $(c_src) $(asm_src) 

$(out)	:	$(src) 
	$(cpp) $(c_argu) $(c_out) $(c_src)
	nasm $(asm_argu) $(asm_out) $(asm_src) 
	ld -s -o $(out)  $(c_out) $(asm_out) 

run		:	$(out)
	./$(out)

deasm	:	$(out)
	@ndisasm -o07c00H  $(asm_out) >$(deasm_file)


clean	:
	rm $(c_out) $(asm_out) $(out)




