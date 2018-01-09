#include "systemc.h"

SC_MODULE(Driver)
{
    sc_out<bool> A, B, CIn;
    sc_in<bool> TClk;

    void Run()
    {
        A.write(false);
        B.write(false);
        CIn.write(false);
        wait();

        A.write(false);
        B.write(false);
        CIn.write(true);
        wait();

        A.write(false);
        B.write(true);
        CIn.write(false);
        wait();

        A.write(false);
        B.write(true);
        CIn.write(true);
        wait();

        A.write(true);
        B.write(false);
        CIn.write(false);
        wait();

        A.write(true);
        B.write(false);
        CIn.write(true);
        wait();

        A.write(true);
        B.write(true);
        CIn.write(false);
        wait();

        A.write(true);
        B.write(true);
        CIn.write(true);
        wait();

        sc_stop();
    }

    SC_CTOR(Driver)
    {
        SC_THREAD(Run);
        sensitive << TClk.pos();
    }
};

