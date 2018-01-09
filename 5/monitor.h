#include "systemc.h"
#include <iostream>
#include <cmath>

SC_MODULE(monitor)
{
    sc_in<bool> a[32], b[32], c[32], ci[32];
    sc_in<bool> co, clk;

    void run()
    {
        cout<<sc_time_stamp()<<" : ";
        cout<<"A = ";
        int ans=0, out=0;
        for(int i=31;i>=0;i++){
        	cout<<a[i].read();
        	ans+=pow(2,i)*a[i].read();
        }
        cout<<" B = ";
        for(int i=31;i>=0;i++){
        	cout<<b[i].read();
        	ans+=pow(2,i)*b[i].read();
        }
        cout<<" : ";
        cout<<"C = ";
        for(int i=31;i>=0;i++){
        	cout<<c[i].read();
        	out+=pow(2,i)*c[i].read();
        }
        cout<<" : ";
        if(ans==out)
        	cout<<"Correct\n";
        else
        	cout<<"Wrong\n";
    }

    SC_CTOR(monitor)
    {
        SC_METHOD(run);
        sensitive << clk.pos();
    }
};

