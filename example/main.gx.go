//gx:include "gxext.h"

package main

import . "github.com/link552/gx-web/cpp-fpm"

func HandleRequest(httpRequest HttpRequest) HttpResponse {
    httpResponse := HttpResponse {}
    httpResponse.Headers = append(httpResponse.Headers, "Content-Type: text/plain; charset=UTF-8")
    httpResponse.Body = "GatewayInterface: " + httpRequest.GatewayInterface + "\n" +
        "ServerSoftware: " + httpRequest.ServerSoftware + "\n" +
        "QueryString: " + httpRequest.QueryString + "\n" +
        "RequestMethod: " + httpRequest.RequestMethod + "\n" +
        "ContentType: " + httpRequest.ContentType + "\n" +
        "ContentLength: " + httpRequest.ContentLength + "\n" +
        "ScriptFileName: " + httpRequest.ScriptFileName + "\n" +
        "ScriptName: " + httpRequest.ScriptName + "\n" +
        "RequestUri: " + httpRequest.RequestUri + "\n" +
        "DocumentRoot: " + httpRequest.DocumentRoot + "\n" +
        "ServerProtocol: " + httpRequest.ServerProtocol + "\n" +
        "RemoteAddress: " + httpRequest.RemoteAddress + "\n" +
        "RemotePort: " + httpRequest.RemotePort + "\n" +
        "ServerAddress: " + httpRequest.ServerAddress + "\n" +
        "ServerPort: " + httpRequest.ServerPort + "\n" +
        "ServerName: " + httpRequest.ServerName + "\n"
    return httpResponse
}

func main() {
    FpmStart()
}
