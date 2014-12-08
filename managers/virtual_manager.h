#include <iostream>

#include "manager.h"
#include "data/function_table.h"

class VManager : public Manager<VManager> {
private:
    FunctionTable* _functionTable;

public:
    static const int FAILED_REGISTRATION = -1;

    static VManager INSTANCE;

private:
    VManager(VManager const&);          // Do not implement. This is a SINGLETON!
    void operator=(VManager const&);    // Do not implement. This is a SINGLETON!

    long registerFunctionInternal(SharedFunction &func);

    bool insertFunctionInternal(long funcId, SharedFunction &function);

public:
    static VManager& GET_INSTANCE();

    VManager() { _functionTable = new FunctionTable(); }

    ~VManager() {
        if(_functionTable != nullptr) {
            delete _functionTable;
            _functionTable = nullptr;
        }
    }

    InstructionID* registerFunction(SharedFunction& func);

    bool findFunction(long internalId, SharedFunction &returnFunc);

    InstructionID* replaceFunction(long funcId, SharedFunction &function);

};