#include <benchmark/benchmark.h>

#include "dmitrievmyshell/HelloWorld.hpp"

void Sample(benchmark::State& state) {
  for (auto _ : state) {
    auto result = dmitrievmyshell::HelloWorld();
    benchmark::DoNotOptimize(result);
  }
}

BENCHMARK(Sample);
BENCHMARK_MAIN();
