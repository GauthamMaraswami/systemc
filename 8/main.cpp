// Programs submitted by 15CO104 and 15CO118
//6 November 2016
//Program 8: 32 bit register


#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "register.h"
#include <iostream>

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> d[32], q[32], _q[32];
    sc_signal<bool> clk;
    sc_clock Clk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
    sc_trace_file *t;

    /* Driver */
    driver D("driver");
    for(int i=0;i<32;i++){
        D.d[i](d[i]);
    }
    D.clk(clk);
    D.Clk(Clk);

    /* Design Under Test */
    reg R("register");
    for(int i=0;i<32;i++){
        R.d[i](d[i]);
        R.q[i](q[i]);
        R._q[i](_q[i]);
    }
    R.clk(clk);

    /* Monitor */
    monitor M("monitor");
    for(int i=0;i<32;i++){
        M.d[i](d[i]);
        M.q[i](q[i]);
        M._q[i](_q[i]);
    }
    M.clk(clk);
    M.Clk(Clk);

    sc_start();

    return 0;
}

