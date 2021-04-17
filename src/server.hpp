#ifndef SIMPLE_SERVER_SERVER_HPP_
#define SIMPLE_SERVER_SERVER_HPP_

namespace simple_server {

class Server {
 public:
  virtual ~Server() noexcept = default;

  virtual int Start(uint16_t port, int backlog) = 0;

  virtual int Run() = 0;
};

}  // simple_server

#endif  // SIMPLE_SERVER_SERVER_HPP_
