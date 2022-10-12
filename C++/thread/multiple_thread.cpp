#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex g_lock;

void mythread(int n) {
    g_lock.lock();
    std::cout << "This is thread " << n << std::endl; 
    g_lock.unlock();
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.push_back(std::thread(mythread, i));
    }

    for (int i = 0; i < 5; i++) {
        threads[i].join();
    }

    return 0;
}
