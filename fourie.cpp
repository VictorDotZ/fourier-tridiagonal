#include "solve.hpp"

static const double C = std::sqrt(2);

double extendedEigenValue(const std::vector<double> p, const uint64_t n, const double h, const uint64_t N)
{
	return eigenValue(n, h, N) + p[n];
}

std::vector<double> solve(const std::vector<double>& p, const std::vector<double>& f, const double h, const uint64_t N)
{
	double d_n = 0.0;
	double c_n = 0.0;

	std::vector<double> y(N);

	for (size_t n = 0; n <= N - 1; ++n) {
		auto eigenVector = (n == 0) ? eigenFunction(1.0, n, N) : eigenFunction(C, n, N);

		d_n = dotProduct(f, eigenVector, h);
		auto lambda = extendedEigenValue(p, n, h, N);

		if ((std::abs(lambda) >= std::numeric_limits<double>::epsilon()))
			c_n = d_n / lambda;
		else
			c_n = 0.0;

		for (size_t i = 0; i <= N - 1; i++)
			y[i] += c_n * eigenVector[i];
	}
	return y;
}
