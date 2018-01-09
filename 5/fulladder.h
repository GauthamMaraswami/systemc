#include "systemc.h"
#include "or2.h"
#include "halfadder.h"

SC_MODULE(fulladder)
{
    sc_in<bool> a, b, ci;
    sc_out<bool> s, co;

    or2 O;
    halfadder H1, H2;

    sc_signal<bool> S1, S2, S3;

    SC_CTOR(fulladder) : O("O"), H1("H1"), H2("H2")
    {
        H1.a(a);
        H1.b(b);
        H1.s(S1);
        H1.c(S2);

        H2.a(S1);
        H2.b(ci);
        H2.s(s);
        H2.c(S3);

        O.a(S2);
        O.b(S3);
        O.y(co);
    }
};

