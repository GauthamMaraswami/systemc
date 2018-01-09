#include "systemc.h"
#include "dflipflop.h"

SC_MODULE(reg){
	sc_in<bool> d[32], clk;
	sc_out<bool> q[32], _q[32];

	sc_vector<DFlipFlop> D;

	SC_CTOR(reg) : D("D"){
		D.init(32);
		for(int i=0;i<32;i++){
			D[i].d(d[i]);
			D[i].clk(clk);
			D[i].q(q[i]);
			D[i]._q(_q[i]);
		}
	}
};