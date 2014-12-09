#ifndef __function_response_h__
#define __function_response_h__

#include "data/function_data.h"

class FunctionResponse {

private:
    FunctionData _data;
public:
    FunctionResponse();

    FunctionResponse(FunctionData data);

    ~FunctionResponse();

    FunctionData getData() {
        return _data;
    }

};

#endif