#ifndef __function_request_h__
#define __function_request_h__

#include "data/function_data.h"

class FunctionUri;

class FunctionRequest {

private:
    FunctionData _data;

    FunctionUri* _functionUri;

public:
    FunctionRequest();

    FunctionRequest(std::string uri);

    FunctionRequest(std::string uriStr, FunctionUri *uri);

    ~FunctionRequest();

    void setRequestData(FunctionData data);

    FunctionData& getRequestData();

    std::string getFunctionUriString();

    FunctionUri* getFunctionUri();

    void setFunctionUri(FunctionUri *pUri);
};

#endif