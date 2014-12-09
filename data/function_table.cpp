#include "function_table.h"
#include "uris/function_uri.h"

FunctionTable::FunctionTable() {

}

FunctionTable::~FunctionTable() {

}

bool FunctionTable::insertFunction(SharedFunction &func) {
    if(_functionMap.find(func.getInternalId()) != _functionMap.end()) {
        return false;
    }
    _functionMap.insert(std::make_pair(func.getInternalId(), func));
    return true;
}

FunctionUri* FunctionTable::replaceFunction(SharedFunction &func) {
    std::map<unsigned long, SharedFunction>::iterator itter;
    itter = _functionMap.find(func.getInternalId());
    if(itter != _functionMap.end()) {
        (*itter).second = func;
        return new FunctionUri(func.getInternalId(), func.getExternalId());
    }
    return nullptr;
}

//void FunctionTable::executeFunction(long funcId) {
//
//}

bool FunctionTable::findFunction(long internalId, SharedFunction &returnFunc) {
    std::map<unsigned long, SharedFunction>::iterator itter;
    itter = _functionMap.find(internalId);
    if(itter != _functionMap.end()) {
        returnFunc = itter->second;
        return true;
    }
    return false;
}