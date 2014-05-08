#include "complex.h"

Complex& Complex::operator*=(Complex z){
        double s1 = real * z.getReal();
        double s2 = real * z.getImag();
        double s3 = imag * z.getReal();
        double s4 = imag * z.getImag();
    
        real = s1 - s4;
        imag = s2 + s3;
        return *this;
}

Complex& Complex::operator/=(Complex z){
        Complex zconj = z.conjugate();
        *(this) *= zconj;
        z *= zconj;
        real = real/z.getReal();
        imag = imag/z.getReal();
        return *this;
}

Complex operator+(Complex a, Complex b){
        return a+=b;
}
Complex operator-(Complex a, Complex b){
        return a-=b;
}
Complex operator*(Complex a, Complex b){
        return a*=b;
}
Complex operator/(Complex a, Complex b){
        return a/=b;
}
bool operator==(Complex a, Complex b){
        return (a.getReal() == b.getReal() && a.getImag() == b.getImag());
}
bool operator!=(Complex a, Complex b){
        return !(a==b);
}
