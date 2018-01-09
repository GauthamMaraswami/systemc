// Programs submitted by 15CO104 and 15CO118
// Print hello world for 100 clock cycles

#include "systemc.h"
#include "driver.h"
#include "hw.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> Clk2;
    sc_clock Clk1("TestClk", 10, SC_NS, 0.5, 10, SC_NS);

    Driver D("Driver");
    D.Clk1(Clk1);
    D.Clk2(Clk2);

    HW Hello("HW");
    
    Hello.Clk1(Clk2);

    sc_start();

    return 0;
}
