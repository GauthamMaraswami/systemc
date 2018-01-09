#include "systemc.h"

SC_MODULE(HW) {
    sc_in<bool> Clk1;

    void Run() {
        cout << "t=" << sc_time_stamp() << " | Hello World" << endl;
    }

    SC_CTOR(HW) {
        SC_METHOD(Run);
        sensitive << Clk1;
    }
};
