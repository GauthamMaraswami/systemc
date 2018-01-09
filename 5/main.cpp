//programmed by 15c0104 adithya Bisht and Gautham M

#include "systemc.h"
#include "driver.h"
#include "monitor.h"
#include "fulladder.h"
#include <iostream>

int sc_main(int argc, char* argv[])
{
    //sc_signal<bool> a, b, ci, s, co;
    sc_clock clk("TestClk", 10, SC_NS, 0.5, 10, SC_NS);
    sc_trace_file *t;

    //sc_bv<4> a, b, c;
    //sc_signal<bool> co;

    sc_signal<bool> a[32], b[32], ci[32], s[32], co;

    /* driver */
    driver D("driver");
    for(int i=0;i<32;i++){
	    D.a[i](a[i]);
	    D.b[i](b[i]);
	    D.ci[i](ci[i]);
	}
   	D.clk(clk);

    /* Design Under Test */
    sc_vector<fulladder> F("fulladder");
    F.init(32);
    for(int i=0;i<32;i++){
    	F[i].a(a[i]);
    	F[i].b(b[i]);
    	F[i].s(s[i]);
    	if(i)
    		F[i].ci(F[i-1].co);
    	if(i<31)
    		F[i].co(F[i+1].ci);
    }
    F[31].co(co);

    /* Monitor */
    monitor M("monitor");
    for(int i=0;i<32;i++){
		M.a[i](a[i]);
		M.b[i](b[i]);
		M.c[i](s[i]);
		M.ci[i](ci[i]);
	}
	M.co(co);
	M.clk(clk);

/*
    t = sc_create_vcd_trace_file("trace");
    sc_trace(t, a,  "A");
    sc_trace(t, b,  "B");
    sc_trace(t, ci, "CIn");
    sc_trace(t, s,  "Sum");
    sc_trace(t, co, "COut");
*/
    sc_start();
//    sc_close_vcd_trace_file(t);

    return 0;
}
