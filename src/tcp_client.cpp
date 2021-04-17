#include "tcp_client.hpp"

#include <unistd.h>

namespace simple_server {

TcpClient::TcpClient() : socket_fd_(), addr_() {
  addr_.sin_family = AF_INET;
}

TcpClient::~TcpClient() noexcept {
  close(socket_fd_);
}

int TcpClient::Connect(const std::string& host, uint16_t port) {
  addr_.sin_addr.s_addr = inet_addr(host.c_str());
  addr_.sin_port = htons(port);
  socket_fd_ = socket(addr_.sin_family, SOCK_STREAM, 0);
  if (socket_fd_ < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }
  if (connect(socket_fd_, (struct sockaddr *)&addr_, sizeof(addr_)) < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }
  return 0;
}

int TcpClient::Send(const std::vector<uint8_t>& data) {
  if (send(socket_fd_, data.data(), data.size(), 0) < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }
  return 0;
}

}  // namespace simple_server
