#include "systemc.h"
#include "xor.h"
#include "and.h"

SC_MODULE(HalfAdder)
{
    sc_in<bool> A, B;
    sc_out<bool> S, C;

    Xor2 C1;
    And2 C2;

    SC_CTOR(HalfAdder) : C1("C1"), C2("C2")
    {
        C1.A(A);
        C1.B(B);
        C1.F(S);

        C2.A(A);
        C2.B(B);
        C2.F(C);
    }
};

