#include "systemc.h"

SC_MODULE(DFlipFlop)
{
    sc_in<bool> D, Clk;
    sc_out<bool> Q, QNeg;

    void Run()
    {
        Q.write(D.read());
        QNeg.write(!D.read());
    }

    SC_CTOR(DFlipFlop)
    {
        SC_METHOD(Run);
        sensitive << Clk.pos();
    }
};

