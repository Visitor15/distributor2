#ifndef __function_table_h__
#define __function_table_h__

#include <map>

#include "functions/shared_function.h"
#include "uris/function_uri.h"

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