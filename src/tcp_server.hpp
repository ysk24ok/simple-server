#ifndef SIMPLE_SERVER_TCP_SERVER_HPP_
#define SIMPLE_SERVER_TCP_SERVER_HPP_

#include <arpa/inet.h>

#include <functional>
#include <string>
#include <vector>

#include "server.hpp"

namespace simple_server {

class TcpServer : public Server {
 public:
  // TODO: Make `func` return a value to a client.
  TcpServer(std::function<void(std::vector<uint8_t>)> func);

  virtual ~TcpServer() noexcept;

  int Start(uint16_t port, int backlog = 5) override;

  int Run() override;

 private:
  uint16_t port_;
  int socket_fd_;
  sockaddr_in addr_;
  std::function<void(std::vector<uint8_t>)> func_;
};

}  // namespace simple_server

#endif  // SIMPLE_SERVER_TCP_SERVER_HPP_
