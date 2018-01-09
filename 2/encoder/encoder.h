// Hrishikesh Hiraskar - 15CO121
// Gunjan Paliwal      - 15CO134
// 17 September 2016

/*
	DUT of 4:16 Encoder
*/

#include "systemc.h"

SC_MODULE(encoder){
	sc_in<bool> D[16];
	sc_out<bool> a, b, c, d;

	void run(){
		for(int i=0;i<16;i++){
			if(D[i].read()){
				a.write(8&i);
				b.write(4&i);
				c.write(2&i);
				d.write(1&i);
			}
		}
	}

	SC_CTOR(encoder){
		SC_METHOD(run);
		for(int i=0;i<16;i++)
			sensitive<<D[i];
	}
};
