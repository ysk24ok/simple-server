#include <cstdlib>
#include <iostream>

#include "tcp_client.hpp"

int main() {
  std::string host = "127.0.0.1";
  uint16_t port = 12345;
  simple_server::TcpClient client;
  if (client.Connect(host, port) < 0) {
    std::cerr << "Establishing connection to the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  const size_t alphabet_size = 26;
  std::vector<uint8_t> data(alphabet_size);
  for (size_t i = 0; i < alphabet_size; ++i) {
    data[i] = static_cast<uint8_t>('a' + i);
  }
  if (client.Send(data) < 0) {
    std::cerr << "Sending data to the server failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::exit(EXIT_SUCCESS);
}
