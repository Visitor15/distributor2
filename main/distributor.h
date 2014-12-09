#ifndef __distributor_h__
#define __distributor_h__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <sstream>
#endif

#include <iostream>

#include "functions/shared_function.h"
#include "uris/function_uri.h"
#include "functions/function_response.h"
#include "functions/function_request.h"
#include "data/function_data.h"
#include "managers/virtual_manager.h"

class Distributor {
private:
    static FunctionResponse MY_SHARED_FUNCTION(FunctionData data);
    static FunctionResponse MY_SHARED_FUNCTION2(FunctionData data);
    static FunctionResponse MY_SHARED_FUNCTION3(FunctionData data);

private:
    Distributor();

    ~Distributor();

    static void distributeInternal();

public:
    static void DISTRIBUTE();

};

#endif