gnustep_c_Flag = `gnustep-config --objc-flags` #-I/usr/include/GNUstep/
gnustep_l_Flag = `gnustep-config --base-libs`

hello	:	main.o Fraction.o
	gcc -o hello main.o Fraction.o  $(gnustep_l_Flag)
main.o	:	main.m
	gcc -c -o main.o main.m $(gnustep_c_Flag)

Fraction.o	:	Fraction.h Fraction.m
	gcc -c -o Fraction.o Fraction.m $(gnustep_c_Flag)
 
clean	:
	rm hello main.o Fraction.o




