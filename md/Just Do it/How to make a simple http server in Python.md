## How to make a simple http server in Python

 [shonenada](https://github.com/shonenada) written on 2013/4/18

### The Process of HTTP Transmission 
 *HTTP*, whose full name is "Hypertext Transfer Protocol", is a application-layer protocol.

Here is a simple introduction to transmission of HTTP.

 1. A HTTP server set up all the sockets and waiting for clients to connect.
 2. When a client ask for connecting to the server, the server accept the information from client. One example of information:

        GET /index.html HTTP/1.1
        Host: www.example.com

 In the first line, "GET" is one of HTTP request methods (all methods is enclose below), "/index.html" is a resource which is requesting, "HTTP/1.1" is the version of HTTP.

 The second line, "Host" is the remote server client requesting for.

 1. After accepting the information from client, the server will read the resource the client requesting and response to the client. If there is no the resource, return a 404 ERROR CODE.


### HTTP request methods
 1. GET
  * "GET" method is get the resource in the internet.
 2. HEAD
 3. POST
  * "POST" method will post information(mostly from a FORM) to the remote server.
 4. PUT
 5. DELETE
 6. TRACE
 7. OPTIONS
 8. CONNECT
 9. PATCH

### Further reading
 1. REST
 2. [W3.org](http://www.w3.org/Protocols/)

### Reference
 1. [HTTP in wikipedia](http://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol)
