#include "solve.hpp"

std::vector<double> solve(const std::vector<double>& p, const std::vector<double>& f, const double h, const uint64_t N)
{
	std::vector<double> alpha(N);
	std::vector<double> beta(N);

	const double c_0 = 2.0 / h / h + p[0];
	const double b_0 = 2.0 / h / h;
	const double f_0 = f[0];

	alpha[1] = b_0 / c_0;
	beta[1] = f_0 / c_0;

	for (size_t k = 1; k <= N - 2; ++k) {
		const double b_k = 1.0 / h / h;
		const double c_k = 2.0 / h / h + p[k];
		const double a_k = 1.0 / h / h;
		const double f_k = f[k];

		alpha[k + 1] = b_k / (c_k - alpha[k] * a_k);
		beta[k + 1] = (a_k * beta[k] + f_k) / (c_k - alpha[k] * a_k);
	}

	const double a_N_minus_1 = 1.0 / h / h;
	const double c_N_minus_1 = 1.0 / h / h + p[N - 1];

	std::vector<double> y(f.size());

	y[N - 1] = (f[N - 1] + a_N_minus_1 * beta[N - 1]) / (c_N_minus_1 - a_N_minus_1 * alpha[N - 1]);

	for (size_t k = N - 2; k != static_cast<size_t>(-1); --k)
		y[k] = alpha[k + 1] * y[k + 1] + beta[k + 1];

	return y;
}