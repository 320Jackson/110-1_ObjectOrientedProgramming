#ifndef GCD_H
#define GCD_H

// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int ArithmeticGCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    return ArithmeticGCD(b, a % b);
}

int gcd(int a, int b) {
    if(a > b) {
        int buffer = a;
        a = b;
        b = buffer;
    }
    int GCDNum = ArithmeticGCD(a, b);
    return GCDNum < 0 ? -GCDNum : GCDNum;
}

#endif