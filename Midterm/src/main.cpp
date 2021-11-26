#include <iostream>
#include "binary.h"

int main() {
    int ab[6]={1,1,1,0,1,0};
	Binary a(ab,6);
	Binary b(a);

    a.resize(8);
    b.setBit(2, 0);

    std::cout << a.toString() << "\n";
    std::cout << b.toString() << "\n";
}