#ifndef SIMPLE_SERVER_CLIENT_HPP_
#define SIMPLE_SERVER_CLIENT_HPP_

#include <string>
#include <vector>

namespace simple_server {

class Client {
 public:
  virtual ~Client() noexcept = default;

  virtual int Connect(const std::string& host, uint16_t port) = 0;

  virtual int Send(const std::vector<uint8_t>& data) = 0;
};

}  // namespace simple_server

#endif  // SIMPLE_SERVER_CLIENT_HPP_
