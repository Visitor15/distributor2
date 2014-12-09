#include "function_request.h"
#include "uris/function_uri.h"

FunctionRequest::FunctionRequest() {
    _functionUri = new FunctionUri("");
}

FunctionRequest::FunctionRequest(std::string uriStr) {
    _functionUri = new FunctionUri(uriStr);
}

FunctionRequest::FunctionRequest(std::string uriStr, FunctionUri *uri) {
    _functionUri = new FunctionUri(uri->getInternalId(), uri->getExternalId());
    (*_functionUri).getUriStruct().fromString(uriStr);
}

FunctionRequest::~FunctionRequest() {

}

void FunctionRequest::setRequestData(FunctionData data) {
    _data = data;
}

FunctionData& FunctionRequest::getRequestData() {
    return _data;
}

std::string FunctionRequest::getFunctionUriString() {
    return _functionUri->getUriStruct().toString();
}

FunctionUri* FunctionRequest::getFunctionUri() {
    return _functionUri;
}

void FunctionRequest::setFunctionUri(FunctionUri *uri) {
}
