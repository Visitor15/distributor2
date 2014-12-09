#include "function_response.h"

FunctionResponse::FunctionResponse() {

}

FunctionResponse::FunctionResponse(FunctionData data) {
    _data = data;
}

FunctionResponse::~FunctionResponse() {

}

FunctionData FunctionResponse::getData() {
    return _data;
}

