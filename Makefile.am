ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS = \
	-std=c++11 -lpthread
AM_CPPFLAGS = \
	-Isrc

include_HEADERS = src/server.hpp

lib_LTLIBRARIES =

lib_LTLIBRARIES += libsimple_server.la
libsimple_server_la_SOURCES = \
	src/server.hpp \
	src/tcp_server.cpp \
	src/tcp_server.hpp

lib_LTLIBRARIES += libsimple_client.la
libsimple_client_la_SOURCES = \
	src/client.hpp \
	src/tcp_client.cpp \
	src/tcp_client.hpp

noinst_PROGRAMS =

noinst_PROGRAMS += examples/greeter_tcp_client
examples_greeter_tcp_client_SOURCES = \
	examples/greeter_tcp_client.cpp
examples_greeter_tcp_client_LDADD = \
	libsimple_client.la

noinst_PROGRAMS += examples/greeter_tcp_server
examples_greeter_tcp_server_SOURCES = \
	examples/greeter_tcp_server.cpp
examples_greeter_tcp_server_LDADD = \
	libsimple_server.la
