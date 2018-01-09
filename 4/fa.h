#include "systemc.h"
#include "or.h"
#include "ha.h"

SC_MODULE(FullAdder)
{
    sc_in<bool> A, B, CIn;
    sc_out<bool> S, COut;

    Or2 C1;
    HalfAdder C2, C3;

    sc_signal<bool> S1, S2, S3;

    SC_CTOR(FullAdder) : C1("C1"), C2("C2"), C3("C3")
    {
        C2.A(A);
        C2.B(B);
        C2.S(S1);
        C2.C(S2);

        C3.A(S1);
        C3.B(CIn);
        C3.S(S);
        C3.C(S3);

        C1.A(S2);
        C1.B(S3);
        C1.F(COut);
    }
};

