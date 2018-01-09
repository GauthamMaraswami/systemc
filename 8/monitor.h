#include "systemc.h"

SC_MODULE(monitor)
{
    sc_in<bool> d[32], clk;
	sc_in<bool> q[32], _q[32];
	sc_in<bool> Clk;

    void run()
    {
    	if(clk.read()){
	        cout<<sc_time_stamp()<<" : ";
	        cout<<"D = ";
	        for(int i=31;i>=0;i--)
	        	cout<<d[i].read();
	        cout<<" : Q = ";
	        for(int i=31;i>=0;i--)
	        	cout<<q[i].read();
	        cout<<" Q' = ";
	        for(int i=31;i>=0;i--)
	        	cout<<_q[i].read();
	        int f=1;
	        for(int i=0;i<32;i++)
	        	if(d[i].read()!=q[i].read())
	        		f=0;
	        if(f)
	        	cout<<" Correct\n";
	        else
	        	cout<<" Wrong\n";
	        cout<<endl;
	    }
    }

    SC_CTOR(monitor)
    {
        SC_METHOD(run);
        sensitive << clk << Clk.pos();
    }
};

