#ifndef __shared_function_h__
#define __shared_function_h__

#include <bits/stringfwd.h>
#include "function_response.h"

typedef FunctionResponse* (*functionPtr)(FunctionData data);

typedef struct sharedFunctionPtr_t {

private:
    std::string _externalId;

    long _internalId;

    functionPtr _functionPtr;

public:
    sharedFunctionPtr_t() : _externalId(""), _internalId(-1) {}

    sharedFunctionPtr_t(char* strId) : _externalId(strId), _internalId(-1) {}

    sharedFunctionPtr_t(char* strId, functionPtr ptr) : _externalId(strId), _internalId(-1), _funcPtr(ptr) {}

    ~sharedFunctionPtr_t();

    long getInternalId() {
        return _internalId;
    }

    std::string getExternalId() {
        return _externalId;
    }

    FunctionResponse executeFunction(FunctionData &inputData) {
        return (*_functionPtr) (inputData);
    }

} SharedFunction;

#endif