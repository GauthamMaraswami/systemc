// Hrishikesh Hiraskar - 15CO121
// Gunjan Paliwal      - 15CO134
// 17 September 2016

/*
	DUT of 4:16 Decoder
*/

#include "systemc.h"

SC_MODULE(decoder){
	sc_in<bool> a, b, c, d;
	sc_out<bool> D[16];

	void run(){
		int i = a.read()*8 + b.read()*4 + c.read()*2 + d.read()*1;
		for(int j=0;j<16;j++)
			D[j].write((i==j));
	}

	SC_CTOR(decoder){
		SC_METHOD(run);
		sensitive<<a<<b<<c<<d;
	}
};
