#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

class Complex{
    public:
        Complex(double r, double i):re(r),im(i){}
        Complex(double r):re(r), im(0){}
        Complex():re(0),im(0){}
        double real(){
            return re;
        }
        void real(double r){
            re = r;
        }

        double imag(){
            return im;
        }
        
        void imag(double i){
            im = i;
        }

        Complex conjugate(){
                Complex z;
                z.re = re;
                z.im = -im;
                return z;
        }
        
        Complex& operator+=(Complex& z){
            re += z.re;
            im += z.im;
            return *this;
        }
        Complex& operator-=(Complex& z){
            re -= z.re;
            im -= z.im;
            return *this;
        }

        void print(){
            std::cout<<real()<<" + "<<imag()<<"i"<<std::endl;
        }

        Complex& operator*=(Complex);
        Complex& operator/=(Complex);


       
    private:
        double re;
        double im;

};

        Complex operator+(Complex,Complex);
        Complex operator*(Complex,Complex);
        Complex operator-(Complex,Complex);
        Complex operator/(Complex,Complex);
        bool operator==(Complex,Complex);
        bool operator!=(Complex,Complex);
#endif
