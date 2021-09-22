#pragma once
#include <cstdint>

#define AT(addr, r, c, ld) addr[c * ld + r]

template <typename T>
void basic_gemm(std::size_t M, std::size_t N, std::size_t K, T *A, T *B, T *C) {
  for (std::size_t m = 0; m < M; ++m) {
    for (std::size_t n = 0; n < N; ++n) {
      for (std::size_t k = 0; k < K; ++k) {
        AT(C, m, n, M) += AT(A, m, k, M) * AT(B, k, n, K);
      }
    }
  }
}

template <typename T>
void cache_optimized_gemm(std::size_t M, std::size_t N, std::size_t K, T *A,
                          T *B, T *C) {
  for (std::size_t n = 0; n < N; ++n) {
    for (std::size_t k = 0; k < K; ++k) {
      for (std::size_t m = 0; m < M; ++m) {
        AT(C, m, n, M) += AT(A, m, k, M) * AT(B, k, n, K);
      }
    }
  }
}
