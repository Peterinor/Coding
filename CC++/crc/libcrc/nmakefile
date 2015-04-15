
crc_src = crc.h crc.cpp
crc_obj = crc.obj

out = crc_gen.exe

main: crc crc_gen.cpp
    cl crc_gen.cpp crc.obj

    crc_gen ADS

crc: $(crc_src)
    cl -c crc.cpp -o $(crc_obj)

clean: 
    del *.obj
    del $(out)
