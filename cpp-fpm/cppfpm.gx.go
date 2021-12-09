//gx:include "cppfpm.h"

package cppfpm

//gx:extern HttpRequest
type HttpRequest struct {
    GatewayInterface string
    ServerSoftware string
    QueryString string
    RequestMethod string
    ContentType string
    ContentLength string
    ScriptFileName string
    ScriptName string
    RequestUri string
    DocumentRoot string
    ServerProtocol string
    RemoteAddress string
    RemotePort string
    ServerAddress string
    ServerPort string
    ServerName string
}

//gx:extern HttpResponse
type HttpResponse struct {
    Headers []string
    Body string
}

//gx:extern FpmStart
func FpmStart()
