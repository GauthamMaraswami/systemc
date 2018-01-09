// Hrishikesh Hiraskar - 15CO121
// Gunjan Paliwal      - 15CO134
// 17 September 2016

/*
	Driver for 4:16 Decoder
*/

#include "systemc.h"

SC_MODULE(driver){
	sc_out<bool> D[16];

	void run(){	
		for(int i=0;i<16;i++){
			for(int j=0;j<16;j++)
				D[j]=(i==j);
			wait(10, SC_NS);
		}
	}

	SC_CTOR(driver){
		SC_THREAD(run);
	}
};
