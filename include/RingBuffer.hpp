#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <atomic>
#include <array>
#include <stdexcept>

template <typename T, size_t Size>
class RingBuffer {
public:
    // Push an item into the buffer (thread-safe)
    bool push(const T& item) {
        size_t next = (head.load(std::memory_order_relaxed) + 1) % (Size + 1); // Ensure correct wrap-around
        if (next == tail.load(std::memory_order_acquire)) {
            return false; // Buffer is full
        }
        buffer[head.load(std::memory_order_relaxed)] = item;
        head.store(next, std::memory_order_release);
        return true;
    }

    // Pop an item from the buffer (thread-safe)
    bool pop(T& item) {
        if (tail.load(std::memory_order_acquire) == head.load(std::memory_order_acquire)) {
            return false; // Buffer is empty
        }
        item = buffer[tail.load(std::memory_order_relaxed)];
        size_t next = (tail.load(std::memory_order_relaxed) + 1) % (Size + 1);
        tail.store(next, std::memory_order_release);
        return true;
    }

    // Debug helpers
    size_t get_head() const { return head.load(std::memory_order_relaxed); }
    size_t get_tail() const { return tail.load(std::memory_order_relaxed); }

private:
    std::array<T, Size + 1> buffer; // Corrected size allocation
    std::atomic<size_t> head{0}; // Producer index
    std::atomic<size_t> tail{0}; // Consumer index
};

#endif // RINGBUFFER_HPP
