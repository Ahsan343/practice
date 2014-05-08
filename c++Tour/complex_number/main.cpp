#include<iostream>
#include "complex.h"

int main(){
        std::cout<<"Constructor 1:"<<std::endl;;
        Complex z1(2.0, 3.0);
        std::cout<<"Real:"<<z1.getReal()<<std::endl;
        std::cout<<"Imaginary:"<<z1.getImag()<<std::endl;
        std::cout<<"Constructor 2:"<<std::endl;;
        Complex z2(2.0);
        std::cout<<"Real:"<<z2.getReal()<<std::endl;
        std::cout<<"Imaginary:"<<z2.getImag()<<std::endl;
        std::cout<<"Constructor 3:"<<std::endl;
        Complex z3;
        std::cout<<"Real:"<<z3.getReal()<<std::endl;
        std::cout<<"Imaginary:"<<z3.getImag()<<std::endl;
        z3.setReal(4.0);
        z3.setImag(5.0);
        std::cout<<"New Real:"<<z3.getReal()<<std::endl;
        std::cout<<"New Imaginary:"<<z3.getImag()<<std::endl;

        z2 += z1;
        std::cout<<"Addition (2 + 3i) + (2 + 0i) = ";
        std::cout<<z2.getReal()<<" + "<<z2.getImag()<<"i"<<std::endl;


        std::cout<<"Multiplication: *= test:(2+3i)*(4+5i): z1 *= z3:";
        z1 *= z3;
        std::cout<<z1.getReal()<<" + "<<z1.getImag()<<"i"<<std::endl;

        z1.setReal(4);
        z1.setImag(2);
        z3.setReal(3);
        z3.setImag(-1);
        std::cout<<"Divion: /= test:(4+2i)/(3-i): z1 /= z3:";
        z1 /= z3;
        std::cout<<z1.getReal()<<" + "<<z1.getImag()<<"i"<<std::endl;


        Complex a(1,1);
        Complex b(2,2);
        Complex c;
        c = a + b;
        std::cout<<"1 + i + 2 + 2i  = ";
        c.print();
    
        c = b - a;
        std::cout<<"2 + 2i - 1 - i  = ";
        c.print();

        c = a * b;
        std::cout<<"(1+i)(2+2i) = ";
        c.print();

        Complex d(2,0);
        c = b /d ;
        std::cout<<"(2+2i)/(2 + 0i):";
        c.print();

        if(a == b)
        {
            std::cout<<"Yes!";
            a.print();
            std::cout<<" is equal to ";
            b.print();
        }
        else
        {
            std::cout<<"No!";
            a.print();
            std::cout<<" is not equal to ";
            b.print();
        }

        d.setReal(1);
        d.setImag(1);


        if(a == d)
        {
            std::cout<<"Yes!";
                a.print();
                std::cout<<" is equal to ";
                d.print();
        }
        else
        {
            std::cout<<"No!";
                a.print();
                std::cout<<" is not equal to ";
                d.print();
        }
        
        return 0;


}
