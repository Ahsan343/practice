#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

class Complex{
    public:
        Complex(double re, double im):real(re),imag(im){ }
        Complex(double re):real(re),imag(0){}
        Complex():real(0),imag(0){}

        void setReal(double re){
            real = re;
        }

        void setImag(double im){
            imag = im;
        }

        double getReal(){
            return real;
        }

        double getImag(){
            return imag;
        }

        Complex conjugate(){
            Complex z(real, -imag);
            return z;
        }

        Complex& operator+=(Complex z){
            real += z.real;
            imag += z.imag;
            return *this;
        }

        Complex& operator-=(Complex z){
            real -= z.real;
            imag -= z.imag;
            return *this;
        }

        void print(){
            std::cout<<getReal()<<" + "<<getImag()<<"i"<<std::endl;
        }

        Complex& operator*=(Complex z);
        Complex& operator/=(Complex z);

    private:
        double real;
        double imag;

};

Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
bool operator==(Complex a, Complex b);
bool operator!=(Complex a, Complex b);
#endif


