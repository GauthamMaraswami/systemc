#include "systemc.h"
#include <iostream>

SC_MODULE(driver)
{
    sc_out<bool> a[32], b[32], ci[32];
    sc_in<bool> clk;

    void run()
    {
    	int n, x, y;
    	char op;
        cout<<"Enter n : ";
        cin>>n;
        cout<<"Enter operation ( + / - ) : ";
        cin>>op;
        ci[0].write(op=='-');
        for(int i=1;i<32;i++)
        	ci[i].write(0);
        cout<<"Enter two integers to operate : ";
        cin>>x>>y;
        for(int i=0;x>0;i++)
        	a[i].write(x%2);
    	if(ci[0].read())        
    		for(int i=0;y>0;i++)
    			b[i].write(y%2);
    	else
    		for(int i=0;y>0;i++)
    			b[i].write(!(y%2));
    	wait();
        sc_stop();
    }

    SC_CTOR(driver)
    {
        SC_THREAD(run);
        sensitive << clk.pos();
    }
};

