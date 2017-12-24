#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void callFromThread(int tid) {
  mtx.lock();
  std::cout << "Launched by thread " << tid << std::endl;
  mtx.unlock();
}

int main() {
  const int numThreads = 10;
  std::thread t[numThreads];

  for(int i = 0; i < numThreads; i++) {
    t[i] = std::thread(callFromThread, i);
  }

  std::cout << "Launched from the main" << std::endl;

  for(int i = 0; i < numThreads; i++) {
    t[i].join();
  }

  return 0;
}
