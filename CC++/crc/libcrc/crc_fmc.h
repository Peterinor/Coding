
#ifndef _CRC_FMC_H_
#define _CRC_FMC_H_

#include"crc.h"

namespace foc{
      class CrcFMC : public Crc {
    public:
        CrcFMC()
            : Crc(16, 0x1021, 0xffff, true, false, 0xffff) {
        }
        ushort generate(const char * data) {
            string ds(data);
            return this->generate(ds);
        }
        ushort generate(string data) {
            ushort crc = this->cal(data);
            return (ushort)bitReverseHex(crc);
        }
    };
}

#endif