#include "systemc.h"

SC_MODULE(Monitor)
{
    sc_in<bool> A, B, CIn, S, COut, TClk;

    void Run()
    {
        bool inA, inB, inCIn, outS, outCOut;

        inA = A.read();
        inB = B.read();
        inCIn = CIn.read();

        outS = S.read();
        outCOut = COut.read();

        cout << "t=" << sc_time_stamp() << " | "
             << "[A = " << inA << ", "
             << "B = " << inB << ", "
             << "Cin = " << inCIn << "] | "
             << "[S = " << outS << ", "
             << "Cout = " << outCOut << "] | " << endl;
    }

    SC_CTOR(Monitor)
    {
        SC_METHOD(Run);
        sensitive << TClk.pos();
    }
};

