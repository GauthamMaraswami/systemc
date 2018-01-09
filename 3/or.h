#include "systemc.h"

SC_MODULE(Or2)
{
    sc_in<bool> A, B;
    sc_out<bool> F;

    void Run()
    {
        F.write(A.read() | B.read());
    }

    SC_CTOR(Or2)
    {
        SC_METHOD(Run);
        sensitive << A << B;
    }
};

