
crc_src=crc.h crc.cpp
crc_obj=crc.obj

out=crc_gen

main:crc crc_gen.cpp
	g++ crc_gen.cpp $(crc_obj) -o crc_gen

crc:$(crc_src)
	g++ -c crc.cpp -o $(crc_obj)

clean: 
	del *.obj
	del $(out)
