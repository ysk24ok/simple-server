simple-server
===

Build the source.

```console
$ ./autogen.sh
$ ./configure
$ make
```

Run the server.

```console
$ examples/greeter_tcp_server
```

Then, run the client.

```console
$ examples/greeter_tcp_client Alice
```
