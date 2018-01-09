// Programs submitted by 15CO104 and 15CO118
// implementation of half adder

#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "ha.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> InA, InB, OutS, OutC;
    sc_clock TClk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
    sc_trace_file *Trace;

    /* Driver */
    Driver D("Driver");
    D.A(InA);
    D.B(InB);
    D.TClk(TClk);

    /* Design Under Test */
    HalfAdder H("HalfAdder");
    H.A(InA);
    H.B(InB);
    H.S(OutS);
    H.C(OutC);

    /* Monitor */
    Monitor M("Monitor");
    M.A(InA);
    M.B(InB);
    M.S(OutS);
    M.C(OutC);
    M.TClk(TClk);

    Trace = sc_create_vcd_trace_file("HalfAdder");
    sc_trace(Trace, InA, "A");
    sc_trace(Trace, InB, "B");
    sc_trace(Trace, OutS, "S");
    sc_trace(Trace, OutC, "C");

    sc_start();
    sc_close_vcd_trace_file(Trace);

    return 0;
}

