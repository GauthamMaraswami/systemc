#include "systemc.h"

SC_MODULE(And2)              // Declare module
{
    sc_in<bool> A, B;        // Input ports
    sc_out<bool> F;          // Output ports

    void Run()               // Callback
    {
        F.write(A.read() & B.read());
    }

    SC_CTOR(And2)            // Constructor
    {
        SC_METHOD(Run);      // Register callback with kernel
        sensitive << A << B; // Sensitivity list
    }
};

