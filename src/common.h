#pragma once
#include <cstdint>

template <typename T>
static inline T &at(T *addr, std::size_t r, std::size_t c, std::size_t ld) {
  return addr[c * ld + r];
}

template <typename T>
void basic_gemm(std::size_t M, std::size_t N, std::size_t K, T *A, T *B, T *C) {
  for (std::size_t m = 0; m < M; ++m) {
    for (std::size_t n = 0; n < N; ++n) {
      for (std::size_t k = 0; k < K; ++k) {
        at<T>(C, m, n, M) = at<T>(A, m, k, M) * at<T>(B, k, n, K);
      }
    }
  }
}
