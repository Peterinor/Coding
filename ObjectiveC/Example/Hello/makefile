gnustep_c_Flag = `gnustep-config --objc-flags` #-I/usr/include/GNUstep/
gnustep_l_Flag = `gnustep-config --base-libs`

hello	:	main.o
	gcc -o hello main.o $(gnustep_l_Flag) -fconstant-string-class=NSConstantString
main.o	:	main.m
	gcc -c -o main.o main.m $(gnustep_c_Flag)

clean	:
	rm hello main.o



