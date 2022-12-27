#include "solve.hpp"

static const double C = std::sqrt(2);

/* явный вид собственных чисел */
double eigenValue(const uint64_t n, const double h, const uint64_t N)
{
	double lambda = 2.0 * std::sin(M_PI * n / (2.0 * N - 1)) / h;
	return lambda * lambda;
}

/* явный вид компонент собственных векторов */
double eigenFunctionComponent(const double C, const uint64_t n, const uint64_t k, const uint64_t N)
{
	return C * std::cos(2.0 * M_PI * static_cast<double>(n) * static_cast<double>(k) / (2.0 * static_cast<double>(N) - 1.0));
}

std::vector<double> eigenFunction(const double C, const uint64_t n, const uint64_t N)
{
	std::vector<double> y_n(N);

	for (size_t k = 0; k < N; ++k)
		y_n[k] = eigenFunctionComponent(C, n, k, N);

	return y_n;
}

/* в моей задаче несимметрия только в нулевой компоненте, коэфф 0.5*/
double dotProduct(const std::vector<double>& u, const std::vector<double>& v, const double h)
{
	double sum = u[0] * v[0] * 0.5;

	for (size_t i = 1; i < u.size(); ++i)
		sum += u[i] * v[i];

	return h * sum;
}