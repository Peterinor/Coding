#pragma once

#include"../../libcrc/crc_fmc.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace libcrc {

    public ref class Crc{
    protected:
        foc::Crc *pCrc;
    public:
        Crc(int width, ulong poly, ulong init, bool refIn, bool refOut, ulong xorOut){
            pCrc = new foc::Crc(width, poly, init, refIn, refOut, xorOut);
        }
        ~Crc(){
        }

        void init(){
            this->pCrc->init();
        }
        void next(int ch) {
            this->pCrc->next(ch);
        }
        ulong crc(){
            return this->pCrc->crc();
        }

        ushort cal(const char * data) {
            return this->pCrc->cal(data);
        }
        ushort cal(string data) {
            return this->pCrc->cal(data);
        }
    };

    public ref class CrcFmc {
    public:
        static unsigned short cal(String ^data){
            foc::CrcFMC * pCrc = new foc::CrcFMC();
            auto xx = (Marshal::StringToHGlobalAnsi(data));
            char *x = (char *)xx.ToPointer();
            auto r = pCrc->cal(x);
            delete pCrc;
            return r;
        }
    };
}
