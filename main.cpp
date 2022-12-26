#include "eigenvalues.hpp"
#include "solve.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<double> solution(const double h, const uint64_t N)
{
	std::vector<double> res(N);
	for (size_t i = 0; i <= N - 1; ++i)
		res[i] = std::cos(M_PI * (i * h));
	return res;
}

std::vector<double> pFunc(const double h, const uint64_t N)
{
	std::vector<double> p(N);

	for (size_t i = 0; i <= N - 1; ++i)
		p[i] = 2.0;

	return p;
}

std::vector<double> func(const std::vector<double>& p, const std::vector<double>& y, const double h, const uint64_t N)
{
	std::vector<double> f(N);
	for (size_t i = 0; i <= N - 1; ++i) {
		f[i] = M_PI * M_PI * std::cos(M_PI * i * h) + p[i] * y[i];
	}
	return f;
}

double error(const std::vector<double>& u, const std::vector<double>& v, const double h)
{
	std::vector<double> diff(u.size());

	for (size_t i = 0; i <= u.size() - 1; ++i)
		diff[i] = u[i] - v[i];

	return std::sqrt(dotProduct(diff, diff, h));
}

int main(int argc, char* argv[])
{
	size_t N = std::stoull(argv[1]);
	double h = 1.0 / (static_cast<double>(N) - 0.5);

	auto groundTruth = solution(h, N);
	auto p = pFunc(h, N);
	auto f = func(p, groundTruth, h, N);
	auto res = solve(p, f, h, N);

	std::ofstream fout;
	fout.open(argv[2]);

	fout << std::scientific;
	for (size_t i = 0; i <= N - 1; ++i)
		fout << i * h << '\t' << res[i] << '\t' << groundTruth[i] << std::endl;

	fout.close();

	std::cout << N << "\t" << std::scientific << error(res, groundTruth, h) << std::endl;

	return 0;
}