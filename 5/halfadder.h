#include "systemc.h"
#include "xor2.h"
#include "and2.h"

SC_MODULE(halfadder)
{
    sc_in<bool> a, b;
    sc_out<bool> s, c;

    xor2 X;
    and2 A;

    SC_CTOR(halfadder) : X("X"), A("A")
    {
        X.a(a);
        X.b(b);
        X.y(s);

        A.a(a);
        A.b(b);
        A.y(c);
    }
};

