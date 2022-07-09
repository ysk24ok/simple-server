#include "tcp_server.hpp"

#include <unistd.h>

#include <array>
#include <iostream>

namespace simple_server {

constexpr size_t kBufferSize = 1024;

TcpServer::TcpServer(std::function<void(std::vector<uint8_t>)> func) : socket_fd_(), addr_() {
  func_ = func;
  addr_.sin_family = AF_INET;
}

TcpServer::~TcpServer() noexcept {
  close(socket_fd_);
}

int TcpServer::Start(uint16_t port, int backlog) {
  addr_.sin_port = htons(port);
  socket_fd_ = socket(addr_.sin_family, SOCK_STREAM, 0);
  if (socket_fd_ < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }

  int optval = 1;
  setsockopt(socket_fd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));

  if (bind(socket_fd_, (struct sockaddr *)&addr_, sizeof(addr_)) < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }
  if (listen(socket_fd_, backlog) < 0) {
    // TODO: Notify the caller of the error content
    return -1;
  }
  return 0;
}

int TcpServer::Run() {
  int client_socket_fd;
  sockaddr client_addr;
  socklen_t client_addrlen = sizeof(client_addr);
  while (true) {
    client_socket_fd = accept(socket_fd_, &client_addr, &client_addrlen);
    if (client_socket_fd < 0) {
      // TODO: Notify the caller of the error content
      return -1;
    }
    std::array<char, kBufferSize> buf;
    std::vector<uint8_t> data;
    ssize_t rsize;
    while (true) {
      rsize = recv(client_socket_fd, &buf, buf.size(), 0);
      if (rsize == 0) {
        break;
      } else if (rsize == -1) {
        // TODO: Notify the caller of the error content
        break;
      } else {
        size_t original_size = data.size();
        data.reserve(data.size() + rsize);
        data.insert(data.begin() + original_size, buf.begin(), buf.begin() + rsize);
      }
    }
    func_(data);
    if (close(client_socket_fd) < 0) {
      // TODO: Notify the caller of the error content
      return -1;
    }
  }
  return 0;
}

}  // namespace simple_server
