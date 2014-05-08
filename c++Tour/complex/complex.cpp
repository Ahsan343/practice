#include "complex.h"


Complex& Complex::operator*=(Complex z){
        double s1 = re * z.re;
        double s2 = re * z.im;
        double s3 = im * z.re;
        double s4 = im * z.im;
        re = s1 - s4;
        im = s2 + s3;
        return *this;
 }


Complex& Complex::operator/=(Complex z){
    Complex zconj = z.conjugate();
    *(this) *= zconj;
    z *= zconj;
    re = re/z.re;
    im = im/z.re;
    return *this;
}

Complex operator+(Complex a, Complex b){
        return a+=b;
}

Complex operator-(Complex a, Complex b){
        return a-=b;
}

Complex operator/(Complex a, Complex b){
        return a/=b;
}

Complex operator*(Complex a, Complex b){
        return a*=b;
}

bool operator==(Complex a, Complex b){
        return (a.real() == b.real() && a.imag() == b.imag());
}

bool operator!=(Complex a, Complex b){
        return !(a==b);
}



