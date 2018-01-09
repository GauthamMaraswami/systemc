#include "systemc.h"

SC_MODULE(DFlipFlop)
{
    sc_in<bool> d, clk;
    sc_out<bool> q, _q;

    void run()
    {
        q.write(d.read());
        _q.write(!d.read());
    }

    SC_CTOR(DFlipFlop)
    {
        SC_METHOD(run);
        sensitive << clk.pos();
    }
};

