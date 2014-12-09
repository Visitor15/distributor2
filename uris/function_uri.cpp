#include "function_uri.h"

FunctionUri::FunctionUri(long internalId, std::string externalId) : Uri(internalId, externalId) {

}

FunctionUri::~FunctionUri() {
}

bool FunctionUri::resolve(FunctionRequest *request, FunctionResponse &response) {

}