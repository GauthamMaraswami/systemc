#include "systemc.h"

SC_MODULE(and2)              // Declare module
{
    sc_in<bool> a, b;        // Input ports
    sc_out<bool> y;          // Output ports

    void run()               // Callback
    {
        y.write(a.read() & b.read());
    }

    SC_CTOR(and2)            // Constructor
    {
        SC_METHOD(run);      // Register callback with kernel
        sensitive << a << b; // Sensitivity list
    }
};

