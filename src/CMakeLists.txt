add_executable(benchmark_proc benchmark_proc.cc)
target_link_libraries(benchmark_proc benchmark::benchmark_main)
target_compile_options(benchmark_proc PRIVATE -O1)
