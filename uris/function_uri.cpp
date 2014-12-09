#include "function_uri.h"
#include "managers/virtual_manager.h"

FunctionUri::FunctionUri(long internalId, std::string externalId) : Uri(internalId, externalId) {

}

FunctionUri::FunctionUri(std::string uriStr) : Uri(-1, "") {

}

FunctionUri::~FunctionUri() {
}

bool FunctionUri::resolve(FunctionRequest *request, FunctionResponse &response) {
    SharedFunction _function;
    if(VManager::GET_INSTANCE().findFunction(request->getFunctionUri()->getInternalId(), _function)) {
        response = _function.executeFunction(request->getRequestData());
        return true;
    }
    return false;
}

void FunctionUri::buildFromUriString(std::string uriStr) {

}

std::string FunctionUri::getExternalId() {
    return Uri::getExternalId();
}

long FunctionUri::getInternalId() {
    return Uri::getInternalId();
}