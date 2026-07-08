# C++ Benchmark Notes

Vector is usually faster for sequential access because memory is contiguous.

unordered_map gives average O(1) lookup, but it has hashing overhead and worse cache locality.

Quant engineering lesson:
Big-O is not enough. Cache locality and memory layout matter.