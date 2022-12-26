#pragma once

#include "eigenvalues.hpp"
#include <cstddef>
#include <cstdint>
#include <vector>

std::vector<double> solve(const std::vector<double>& p, const std::vector<double>& f, const double h, const uint64_t N);