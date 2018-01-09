#include "systemc.h"

SC_MODULE(Monitor)
{
    sc_in<bool> Clk1;

    void Run()
    {
        if (Clk1.read() == true)
            cout << "t=" << sc_time_stamp() << "Hello World" << endl;
    }

    SC_CTOR(Monitor)
    {
        SC_METHOD(Run);
        sensitive << Clk1.pos();
    }
};

