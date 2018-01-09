// Programs submitted by 15CO104 and 15CO118
// Implementation of full adder

#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "fa.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> InA, InB, InCIn, OutS, OutCOut;
    sc_clock TClk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
    sc_trace_file *Trace;

    /* Driver */
    Driver D("Driver");
    D.A(InA);
    D.B(InB);
    D.CIn(InCIn);
    D.TClk(TClk);

    /* Design Under Test */
    FullAdder F("FullAdder");
    F.A(InA);
    F.B(InB);
    F.CIn(InCIn);
    F.S(OutS);
    F.COut(OutCOut);

    /* Monitor */
    Monitor M("Monitor");
    M.A(InA);
    M.B(InB);
    M.CIn(InCIn);
    M.S(OutS);
    M.COut(OutCOut);
    M.TClk(TClk);

    Trace = sc_create_vcd_trace_file("FullAdder");
    sc_trace(Trace, InA, "A");
    sc_trace(Trace, InB, "B");
    sc_trace(Trace, InCIn, "CIn");
    sc_trace(Trace, OutS, "S");
    sc_trace(Trace, OutCOut, "COut");

    sc_start();
    sc_close_vcd_trace_file(Trace);

    return 0;
}

