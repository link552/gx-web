#include "gx.hh"

struct HttpRequest {
    gx::String gatewayInterface;
    gx::String serverSoftware;
    gx::String queryString;
    gx::String requestMethod;
    gx::String contentType;
    gx::String contentLength;
    gx::String scriptFileName;
    gx::String scriptName;
    gx::String requestUri;
    gx::String documentUri;
    gx::String documentRoot;
    gx::String serverProtocol;
    gx::String remoteAddress;
    gx::String remotePort;
    gx::String serverAddress;
    gx::String serverPort;
    gx::String serverName;
};

struct HttpResponse {
    gx::Slice<gx::String> headers;
    /* gx::String headers[10] */
    gx::String body;
};

void FpmStart();

HttpResponse HandleRequest(HttpRequest);

void Trace(const char*);
