#include "systemc.h"
#include <iostream>

SC_MODULE(driver)
{
    sc_out<bool> d[32], clk;
    sc_in<bool> Clk;

    void run()
    {
        cout<<"Enter integer to store in register : ";
        int n;
        cin>>n;
        clk.write(1);
        for(int i=0;n>0;i++){
            d[i].write(n%2);
            n/=2;
        }
        wait();
        clk.write(0);
        sc_stop();
    }

    SC_CTOR(driver)
    {
        SC_THREAD(run);
        sensitive << Clk.pos();
    }
};

