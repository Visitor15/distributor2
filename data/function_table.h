#ifndef __function_table_h__
#define __function_table_h__

#include <bits/stl_map.h>

#include "functions/shared_function.h"

class FunctionTable {
private:
    std::map<unsigned long, SharedFunction> _functionMap;

public:
    FunctionTable();

    ~FunctionTable();

    bool insertFunction(SharedFunction &function);


};

#endif