// Hrishikesh Hiraskar - 15CO121
// Gunjan Paliwal      - 15CO134
// 17 September 2016

/*
	Driver for 4:16 Decoder
*/

#include "systemc.h"

SC_MODULE(driver){
	sc_out<bool> a, b, c, d;

	void run(){	
		for(int i=0;i<16;i++){
			a.write(8&i);
			b.write(4&i);
			c.write(2&i);
			d.write(1&i);
			wait(10, SC_NS);
		}
	}

	SC_CTOR(driver){
		SC_THREAD(run);
	}
};
