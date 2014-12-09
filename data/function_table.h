#ifndef __function_table_h__
#define __function_table_h__

#include <bits/stl_map.h>

#include "functions/shared_function.h"
#include "filters/function_uri.h"

class FunctionTable {
private:
    std::map<unsigned long, SharedFunction> _functionMap;

public:
    FunctionTable();

    ~FunctionTable();

    bool insertFunction(SharedFunction &function);

    bool findFunction(long internalId, SharedFunction& foundFunc);

    FunctionUri* replaceFunction(SharedFunction&);
};

#endif