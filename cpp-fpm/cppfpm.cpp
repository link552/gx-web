#include <iostream>
#include "fcgio.h"
#include "cppfpm.h"

using namespace std;

void FpmStart() {
    // Backup the stdio streambufs
    streambuf *cinBuf = cin.rdbuf();
    streambuf *coutBuf = cout.rdbuf();
    streambuf *cerrBuf = cerr.rdbuf();

    FCGX_Request fcgxRequest;

    FCGX_Init();
    FCGX_InitRequest(&fcgxRequest, 0, 0);

    while (FCGX_Accept_r(&fcgxRequest) == 0) {
        fcgi_streambuf cinFcgiBuf(fcgxRequest.in);
        fcgi_streambuf coutFcgiBuf(fcgxRequest.out);
        fcgi_streambuf cerrFcgiBuf(fcgxRequest.err);

        cin.rdbuf(&cinFcgiBuf);
        cout.rdbuf(&coutFcgiBuf);
        cerr.rdbuf(&cerrFcgiBuf);

        HttpRequest httpRequest;
        httpRequest.gatewayInterface = FCGX_GetParam("GATEWAY_INTERFACE", fcgxRequest.envp);
        httpRequest.serverSoftware = FCGX_GetParam("SERVER_SOFTWARE", fcgxRequest.envp);
        httpRequest.queryString = FCGX_GetParam("QUERY_STRING", fcgxRequest.envp);
        httpRequest.requestMethod = FCGX_GetParam("REQUEST_METHOD", fcgxRequest.envp);
        httpRequest.contentType = FCGX_GetParam("CONTENT_TYPE", fcgxRequest.envp);
        httpRequest.contentLength = FCGX_GetParam("CONTENT_LENGTH", fcgxRequest.envp);
        httpRequest.scriptFileName = FCGX_GetParam("SCRIPT_FILENAME", fcgxRequest.envp);
        httpRequest.scriptName = FCGX_GetParam("SCRIPT_NAME", fcgxRequest.envp);
        httpRequest.requestUri = FCGX_GetParam("REQUEST_URI", fcgxRequest.envp);
        httpRequest.documentUri = FCGX_GetParam("DOCUMENT_URI", fcgxRequest.envp);
        httpRequest.documentRoot = FCGX_GetParam("DOCUMENT_ROOT", fcgxRequest.envp);
        httpRequest.serverProtocol = FCGX_GetParam("SERVER_PROTOCOL", fcgxRequest.envp);
        httpRequest.remoteAddress = FCGX_GetParam("REMOTE_ADDR", fcgxRequest.envp);
        httpRequest.remotePort = FCGX_GetParam("REMOTE_PORT", fcgxRequest.envp);
        httpRequest.serverAddress = FCGX_GetParam("SERVER_ADDR", fcgxRequest.envp);
        httpRequest.serverPort = FCGX_GetParam("SERVER_PORT", fcgxRequest.envp);
        httpRequest.serverName = FCGX_GetParam("SERVER_NAME", fcgxRequest.envp);

        HttpResponse httpResponse = HandleRequest(httpRequest);

        for (int i = 0; i < len(httpResponse.headers); i++) {
            cout << httpResponse.headers[i] << "\r\n";
        }

        cout << "\r\n" << httpResponse.body;

        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    cerr.rdbuf(cerrBuf);
}
