#include "systemc.h"

SC_MODULE(Driver)
{
    sc_out<bool> D, Clk;
    sc_in<bool> TClk;

    void Pulse()
    {
        Clk.write(false);
        wait();
        Clk.write(true);
        wait();
    }

    void Run()
    {
        D.write(false);
        Pulse();

        D.write(true);
        Pulse();

        sc_stop();
    }

    SC_CTOR(Driver)
    {
        SC_THREAD(Run);
        sensitive << TClk.pos();
    }
};

