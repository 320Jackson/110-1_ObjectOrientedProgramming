#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H

#include <string>

double *add(double *u, int dim_u, double *v, int dim_v) {
    if (dim_u != dim_v || dim_u < 1 || dim_v < 1) {
        throw std::string("undefined.");
    }

    double *result = new double[dim_u];
    for(int Run = 0; Run < dim_u; Run++) {
        result[Run] = u[Run] + v[Run];
    }
    return result;
}

double *scale(double *u, int dim_u, double d_delta) {
    if (dim_u < 1) {
        throw std::string("undefined.");
    }

    double *result = new double[dim_u];
    for(int Run = 0; Run < dim_u; Run++) {
        result[Run] = u[Run] * d_delta;
    }
    return result;
}

#endif