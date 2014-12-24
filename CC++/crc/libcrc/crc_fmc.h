
#ifndef _CRC_FMC_H_
#define _CRC_FMC_H_

#include"crc.h"

namespace foc{
      class CrcFMC : public Crc {
    public:
        CrcFMC()
            : Crc(16, 0x1021, 0xffff, true, false, 0xffff) {
        }
        ushort cal(const char * data){
            ushort crc = Crc::cal(data);
            return (ushort)bitReverseHex(crc);
        }
        ushort cal(string data){
            ushort crc = Crc::cal(data);
            return (ushort)bitReverseHex(crc);
        }
    };
}

#endif