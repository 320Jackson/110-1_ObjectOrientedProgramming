#include <iostream>
#include "dot.h"
using namespace std;

int main() {
    double u[2] = {1, 2}, v[2] = {3, 4};
    cout << dot(u, 2, v, 2) << "\n";
    return 0;
}