#include "function_request.h"

FunctionRequest::FunctionRequest() {

}

FunctionRequest::~FunctionRequest() {

}

void FunctionRequest::setRequestData(FunctionData data) {
    _data = data;
}

FunctionData FunctionRequest::getRequestData() {
    return _data;
}