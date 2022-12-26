#pragma once
#include <cmath>
#include <cstdint>
#include <vector>

/* явный вид собственных чисел */
double eigenValue(const uint64_t n, const double h, const uint64_t N);

/* явный вид компонент собственных векторов */
double eigenFunctionComponent(const double C, const uint64_t n, const uint64_t k, const uint64_t N);

std::vector<double> eigenFunction(const double C, const uint64_t n, const uint64_t N);

/* в моей задаче несимметрия только в нулевой компоненте, коэфф 0.5*/
double dotProduct(const std::vector<double>& u, const std::vector<double>& v, const double h);