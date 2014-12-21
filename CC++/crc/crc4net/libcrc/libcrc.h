// libcrc.h

#pragma once

#include"../../libcrc/crc.h"


#include<iostream>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace libcrc {

	public ref class CrcFmc
	{
	public:
		static unsigned short crc_gen(String ^data){
			foc::CrcFMC * crc = new foc::CrcFMC();
			auto xx = (Marshal::StringToHGlobalAnsi(data));
			char *x = (char *)xx.ToPointer();
			auto r = crc->generate(x);
			delete crc;
			return r;
		}
	};
}
