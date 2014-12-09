#include "function_uri.h"

FunctionUri::FunctionUri(long internalId, std::string externalId) : Uri<FunctionUri>(internalId, externalId) {

}

FunctionUri::~FunctionUri() {
}

bool FunctionUri::resolve(FunctionRequest *request, FunctionResponse &response) {

}