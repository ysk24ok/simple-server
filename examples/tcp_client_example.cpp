#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

#include "tcp_client.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./command [name]" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::vector<uint8_t> data(argv[1], argv[1] + strlen(argv[1]));

  std::string host = "127.0.0.1";
  uint16_t port = 12345;
  simple_server::TcpClient client;
  if (client.Connect(host, port) < 0) {
    std::cerr << "Establishing connection to the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  if (client.Send(data) < 0) {
    std::cerr << "Sending data to the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::exit(EXIT_SUCCESS);
}
