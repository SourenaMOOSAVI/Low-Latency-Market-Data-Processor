#include "RingBuffer.hpp"
#include "Common.hpp"
#include <benchmark/benchmark.h>

static void BM_RingBufferPushPop(benchmark::State& state) {
    RingBuffer<TimedData, 1024> buffer;
    TimedData item{"test", std::chrono::high_resolution_clock::now()};

    for (auto _ : state) {
        buffer.push(item);
        buffer.pop(item);
    }
}
BENCHMARK(BM_RingBufferPushPop);

BENCHMARK_MAIN();