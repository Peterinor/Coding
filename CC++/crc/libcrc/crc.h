
#ifndef _CRC_H_
#define _CRC_H_

#include <string>
using namespace std;

typedef unsigned long           ulong;
typedef unsigned long long      ullong;
typedef unsigned int            uint;
typedef unsigned short          ushort;
typedef unsigned char           uchar;

ulong bitReverse(ulong v, int b);
ulong bitReverseHex(ulong v);

#define BITMASK(X) (1L << (X))

namespace foc {

    class Crc {
    protected:
        int   _width;         /* Parameter: crc width in bits [8,32].   */
        ulong _poly;          /* Parameter: The algorithm's polynomial. */
        ulong _init;          /* Parameter: Initial register value.     */
        bool  _refIn;         /* Parameter: reverse input bytes?        */
        bool  _refOut;        /* Parameter: reverse output CRC?         */
        ulong _xorOut;        /* Parameter: XOR this to output CRC.     */

    private:
        ulong _register;      /* Context: Context during execution.     */

    public:

        Crc(int width, ulong poly, ulong init = 0, bool refIn = false, bool refOut = false, ulong xorOut = 0){
            this->_width  = width;
            this->_poly   = poly;
            this->_init   = init;
            this->_refIn  = refIn;
            this->_refOut = refOut;
            this->_xorOut = xorOut;
        }
        ~Crc(){
        }

        ulong mask(){
            return (((1L << (this->_width - 1)) - 1L) << 1) | 1L;
        }

        void init(){
            this->_register = this->_init;
        }
        void next(int ch) {
            ulong uch = (ulong)ch;
            ulong topbit = BITMASK(this->_width - 1);

            if (this->_refIn) {
                uch = bitReverse(uch, 8);
            }
            this->_register ^= (uch << (this->_width - 8));
            for (int i = 0; i < 8; i++) {
                if (this->_register & topbit){
                    this->_register = (this->_register << 1) ^ this->_poly;
                }
                else {
                    this->_register <<= 1;
                }
                this->_register &= this->mask();
            }
        }
        ulong crc(){
            if (this->_refOut)
                return this->_xorOut ^ bitReverse(this->_register, this->_width);
            else
                return this->_xorOut ^ this->_register;
        }

        ushort cal(const char * data) {
            string ds(data);
            return this->cal(ds);
        }
        ushort cal(string data) {
            this->init();
            for (int i = 0, l = data.size(); i < l; i++){
                this->next(data[i]);
            }
            return (ushort)this->crc();
        }
    };

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