#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

bool isPrima(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void cekPrima(int n) {
    std::lock_guard<std::mutex> guard(mtx); 
    if (isPrima(n)) {
        std::cout << n << " adalah bilangan prima.\n";
    } else {
        std::cout << n << " bukan bilangan prima.\n";
    }
}

int main() {
    std::vector<int> bilangan = {29, 15, 23, 42, 5};
    std::vector<std::thread> threads;

    for (int num : bilangan) {
        threads.push_back(std::thread(cekPrima, num));
    }

    for (auto &th : threads) {
        th.join();
    }

    return 0;
}
