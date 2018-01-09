#include "systemc.h"

SC_MODULE(Monitor)
{
    sc_in<bool> A, B, S, C, TClk;

    void Run()
    {
        bool inA, inB, outS, outC;

        inA = A.read();
        inB = B.read();

        outS = S.read();
        outC = C.read();

        cout << "t=" << sc_time_stamp() << " | "
             << "[A = " << inA << ", "
             << "B = " << inB << "] | "
             << "[S = " << outS << ", "
             << "C = " << outC << "] | " << endl;
    }

    SC_CTOR(Monitor)
    {
        SC_METHOD(Run);
        sensitive << TClk.pos();
    }
};

