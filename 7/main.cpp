// Programs submitted by 15CO104 and 15CO118
// implementation of single bit sequential memory element using d flip flop

#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "dFF.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> InD, InClk, OutQ, OutQNeg;
    sc_clock TClk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
    sc_trace_file *Trace;

    /* Driver */
    Driver D("Driver");
    D.D(InD);
    D.Clk(InClk);
    D.TClk(TClk);

    /* Design Under Test */
    DFlipFlop F("DFlipFlop");
    F.D(InD);
    F.Clk(InClk);
    F.Q(OutQ);
    F.QNeg(OutQNeg);

    /* Monitor */
    Monitor M("Monitor");
    M.D(InD);
    M.Clk(InClk);
    M.Q(OutQ);
    M.QNeg(OutQNeg);
    M.TClk(TClk);

    Trace = sc_create_vcd_trace_file("DFF");
    sc_trace(Trace, InD, "D");
    sc_trace(Trace, InClk, "Clk");
    sc_trace(Trace, OutQ, "Q");
    sc_trace(Trace, OutQNeg, "QNeg");

    sc_start();
    sc_close_vcd_trace_file(Trace);

    return 0;
}

