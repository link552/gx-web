# Gx Web

A simple example of web development using the [Gx](https://github.com/nikki93/gx) compiler.

Application code is written in a subset of [Go](https://github.com/golang/go) for quick and easy development, then transpiled to C++ with Gx and compiled to a single, small native binary. Take advantage of your favorite C/C++ libraries and their performance while handling the higher level application and business logic with the clean syntax and data-driven design of Go.

## Getting Started

For easy implementation of FastCGI, I decided to develop exclusively for the linux_x86_64 platform. The fastest way to get this example up and running is to use [Docker](https://www.docker.com/products/docker-desktop):

```sh
git clone https://github.com/link552/gx-web.git
cd gx-web
docker build -t gx-web:latest .

# Linux/Mac
docker run -it -p 0.0.0.0:8080:80/tcp -v $(pwd):/gx-web --name gx-web gx-web:latest

# Windows
docker run -it -p 0.0.0.0:8080:80/tcp -v %cd%:/gx-web --name gx-web gx-web:latest
```

You now have Gx Web running! Visit [localhost:8080](http://localhost:8080) in your browser.

## How It Works

This example includes a very simple FastCGI implementation. The `HttpRequest` and `HttpResponse` structures are exposed to Go for use in the application logic. After compiling to a single binary, `spawn-fcgi` will run the application on a unix socket. Nginx is used to handle general HTTP server needs and makes a `fastcgi_pass` to proxy to the open socket.

## Motivation

Gx was originally made for game development, but I wanted to test it's viability for web development. Although C++ is used in some cases for development of web applications, other languages are often preferred due to their ease-of-use. Gx makes it possible to keep this ease-of-use with Go while also keeping the benefits of C++ under the hood. Ultimately my goal was to wire everything together and build enough infrastructure to write a request handler in Go that runs lightening fast.

## Conclusion

Although I managed to meet my goal, I recognize there's a lot more infrastructure that will need to be added to have all the features you'd expect in a modern web application. From serialization to databases to executing commands, all of these would need to be built in C++ and exposed to Go with a simple interface. Gx is also quite young in it's development and requires extension to support full Go syntax. This project has opened my mind to new possibilities and new ways of thinking about web development.

## License

Gx Web is licensed under the terms of [MIT](https://opensource.org/licenses/MIT).
