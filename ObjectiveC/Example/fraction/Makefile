gnustep_c_Flag = `gnustep-config --objc-flags`
gnustep_l_Flag = `gnustep-config --base-libs`

src = Fraction.h Fraction.m main.m  

Fraction	:	Fraction.o $(src) Makefile
	gcc -o Fraction main.m Fraction.o  $(gnustep_l_Flag) $(gnustep_c_Flag) -fconstant-string-class=NSConstantString

Fraction.o	:	Fraction.h Fraction.m
	gcc -c -o Fraction.o Fraction.m $(gnustep_c_Flag)
 
run		:	
	@./Fraction
clean	:
	rm Fraction Fraction.o




