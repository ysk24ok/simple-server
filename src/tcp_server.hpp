#ifndef SIMPLE_SERVER_TCP_SERVER_HPP_
#define SIMPLE_SERVER_TCP_SERVER_HPP_

#include <arpa/inet.h>

#include <string>

#include "server.hpp"

namespace simple_server {

class TcpServer : public Server {
 public:
  TcpServer();

  virtual ~TcpServer() noexcept;

  int Start(uint16_t port, int backlog = 5) override;

  int Run() override;

 private:
  uint16_t port_;
  int socket_fd_;
  sockaddr_in addr_;
};

}  // namespace simple_server

#endif  // SIMPLE_SERVER_TCP_SERVER_HPP_
