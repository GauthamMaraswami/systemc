#include "systemc.h"

SC_MODULE(Xor2)
{
    sc_in<bool> A, B;
    sc_out<bool> F;

    void Run()
    {
        F.write(A.read() ^ B.read());
    }

    SC_CTOR(Xor2)
    {
        SC_METHOD(Run);
        sensitive << A << B;
    }
};

