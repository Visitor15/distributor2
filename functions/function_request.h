#ifndef __function_request_h__
#define __function_request_h__

#include "data/function_data.h"

class FunctionRequest {

private:
    FunctionData _data;

public:
    FunctionRequest();

    ~FunctionRequest();

    void setRequestData(FunctionData data);

    FunctionData getRequestData();
};

#endif