#ifndef SIMPLE_SERVER_TCP_CLIENT_HPP_
#define SIMPLE_SERVER_TCP_CLIENT_HPP_

#include <arpa/inet.h>

#include <string>

#include "client.hpp"

namespace simple_server {

class TcpClient : public Client {
 public:
  TcpClient();

  virtual ~TcpClient() noexcept;

  int Connect(const std::string& host, uint16_t port) override;

  int Send(const std::vector<uint8_t>& data) override;

 private:
  int socket_fd_;
  sockaddr_in addr_;
};

}  // namespace simple_server

#endif  // SIMPLE_SERVER_TCP_CLIENT_HPP_
