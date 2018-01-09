// Programs submitted by 15CO104 Adithya bisht and 15CO118 Gautham M
// 17 September 2016

/*
	4:16 Decoder
*/

#include "systemc.h"
#include "driver.h"
#include "decoder.h"
#include "monitor.h"

int sc_main(int argc, char *argv[]){
	sc_signal<bool> a, b, c, d, D[16];
	sc_trace_file *t;

	driver dr("driver");
	dr.a(a);
	dr.b(b);
	dr.c(c);
	dr.d(d);

	decoder de("decoder");
	de.a(a);
	de.b(b);
	de.c(c);
	de.d(d);

	monitor mn("monitor");
	mn.a(a);
	mn.b(b);
	mn.c(c);
	mn.d(d);

	for(int i=0;i<16;i++){
		de.D[i](D[i]);
		mn.D[i](D[i]);
	}

	
    t = sc_create_vcd_trace_file("trace");
    t->set_time_unit(1, SC_NS);
    sc_trace(t, a, "A");
    sc_trace(t, b, "B");
    sc_trace(t, c, "C");
    sc_trace(t, d, "D");
    for(int i=0;i<16;i++)
    	sc_trace(t, D[i], "D"+(i+'0'));
    sc_start();
    sc_close_vcd_trace_file(t);

    return 0;
}
