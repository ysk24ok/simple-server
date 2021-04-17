#include <cstdlib>
#include <iostream>

#include "tcp_server.hpp"

int main() {
  simple_server::TcpServer server;
  uint16_t port = 12345;
  int backlog = 1;
  if (server.Start(port, backlog) < 0) {
    std::cerr << "Starting the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  if (server.Run() < 0) {
    std::cerr << "Running the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::exit(EXIT_SUCCESS);
}
