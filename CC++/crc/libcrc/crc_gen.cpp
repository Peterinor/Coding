
#include "crc.h"

#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

    if(argc < 2){
        cout << "-----------------------------------" << endl;
        cout << "FMC crc generate tool by Yu.Tang" << endl;
        cout << "usage: crc_gen <data>" << endl;
        cout << "example: crc_gen ADS " << endl;
        cout << "the result is: e7bd" << endl;
        cout << "-----------------------------------" << endl;

        system("pause");
        return 0;
    }

    foc::CrcFMC *cal = new foc::CrcFMC();

    unsigned short crc = cal->generate(argv[1]);
    cout << hex << crc << endl;

    delete cal;
    return 0;
}

// FPN/RI:DA:KMWH:AA:KSFO:R:32R:D:EPATA1.EAT:AP:ILS19L.CCR:A:GOLDN2.FMG:F:EAT..YKM..IMB

// /BFIBOCR FSLBOCR.REQFPN/TS193240,020392/GABFIBOCR.FSLBOCR/CABOEINGFSL1/COMWHSFO1/FNBO001