#include "systemc.h"

SC_MODULE(xor2)
{
    sc_in<bool> a, b;
    sc_out<bool> y;

    void run()
    {
        y.write(a.read() ^ b.read());
    }

    SC_CTOR(xor2)
    {
        SC_METHOD(run);
        sensitive << a << b;
    }
};

