#include "systemc.h"

SC_MODULE(Driver) {
	sc_in<bool> Clk1;
	sc_out<bool> Clk2;
    void Run() {
		for(int i=0;i<100;i++) {
			Clk2.write(Clk1.read());
			wait();
		}
        sc_stop();
    }

    SC_CTOR(Driver) {
        SC_THREAD(Run);
        sensitive << Clk1;
    }
};

