#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

void vectorVsUnorderedMap() {
    const int n = 1000000;
    std::vector<int> vec(n);
    std::unordered_map<int, int> umap;
    umap.reserve(n);

    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
        umap[i] = i + 1;
    }

    long long vecSum = 0;
    auto vec_s = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        vecSum += vec[i];
    }
    auto vec_e = std::chrono::high_resolution_clock::now();

    long long mpSum = 0;
    auto mp_s = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        mpSum += umap[i];
    }
    auto mp_e = std::chrono::high_resolution_clock::now();

    auto vec_time =
        std::chrono::duration_cast<std::chrono::microseconds>(vec_e - vec_s);
    auto umap_time =
        std::chrono::duration_cast<std::chrono::microseconds>(mp_e - mp_s);

    std::cout << "Vector sum: " << vecSum << '\n';
    std::cout << "Unordered map sum: " << mpSum << '\n';
    std::cout << "Time by vector: " << vec_time.count() << " microseconds\n";
    std::cout << "Time by unordered_map: " << umap_time.count() << " microseconds\n";
}

int main() {
    vectorVsUnorderedMap();
    return 0;
}
