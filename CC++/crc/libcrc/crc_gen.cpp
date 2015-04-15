#include "crc.h"
#include "crc_fmc.h"

#include "cmdline.h"

#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    if (argc < 2){

        cout << "-----------------------------------" << endl;
        cout << "FMC crc generate tool by Yu.Tang" << endl;
        cout << "usage: crc_gen <data>" << endl;
        cout << "example: crc_gen ADS " << endl;
        cout << "the result is: e7bd" << endl;
        cout << "-----------------------------------" << endl;

        return 0;
    }

    cmdline::Parser pa;
    pa.add<int>("width", "w", "crc bit width", false, 16);
    pa.add<ulong>("poly", "p", "crc poly", false, 0x1021);
    pa.add<ulong>("init", "init", "crc register init value", false, 0);
    pa.add<bool>("refin", "ri", "reflect the input bits", false, false);
    pa.add<bool>("refout", "ro", "reflect the out bits", false, false);
    pa.add<ulong>("xorout", "x", "xor with the out data", false, 0x0);

    foc::CrcFMC *cal = new foc::CrcFMC();

    unsigned short crc = cal->cal(argv[1]);
    cout << hex << crc << endl;

    delete cal;
    return 0;
}

// FPN/RI:DA:KMWH:AA:KSFO:R:32R:D:EPATA1.EAT:AP:ILS19L.CCR:A:GOLDN2.FMG:F:EAT..YKM..IMB

// /BFIBOCR FSLBOCR.REQFPN/TS193240,020392/GABFIBOCR.FSLBOCR/CABOEINGFSL1/COMWHSFO1/FNBO001
