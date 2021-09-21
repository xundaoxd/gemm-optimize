#include <benchmark/benchmark.h>

#include "common.h"

#define BENCH(x) BENCHMARK(x)->DenseRange(32, 1024, 32)

static void BasicGEMM(benchmark::State &state) {
  std::size_t n = state.range(0);
  std::size_t M = n, N = n, K = n;
  double *a = new double[M * K];
  double *b = new double[K * N];
  double *c = new double[M * N];

  for (auto _ : state) {
    basic_gemm<double>(M, N, K, a, b, c);
  }

  delete[] a;
  delete[] b;
  delete[] c;
}
BENCH(BasicGEMM);
