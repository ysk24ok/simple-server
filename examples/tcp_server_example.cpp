#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

#include "tcp_server.hpp"

void greet(const std::vector<uint8_t>& data) {
  std::string name(data.begin(), data.end());
  std::cout << "Hello, " << name << std::endl;
}

int run(uint16_t port, int backlog) {
  simple_server::TcpServer server(greet);
  if (server.Start(port, backlog) < 0) {
    std::cerr << "Starting the server failed." << std::endl;
    return -1;
  }
  if (server.Run() < 0) {
    std::cerr << "Running the server failed." << std::endl;
    return -1;
  }
  return 0;
}

int main() {
  uint16_t port = 12345;
  int backlog = 1;
  size_t num_threads = 4;

  std::vector<std::thread> threads;
  threads.reserve(num_threads);
  for (size_t i = 0; i < num_threads; ++i) {
    threads.emplace_back(std::thread(run, port, backlog));
  }
  for (size_t i = 0; i < num_threads; ++i) {
    threads[i].join();
  }

  std::exit(EXIT_SUCCESS);
}
