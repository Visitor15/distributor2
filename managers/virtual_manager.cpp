#include "virtual_manager.h"

VManager& VManager::GET_INSTANCE() {
    return INSTANCE;
}

FunctionUri* VManager::registerFunction(SharedFunction &function) {

    if(registerFunctionInternal(function) != FAILED_REGISTRATION) {
        return new FunctionUri(function.getInternalId(), function.getExternalId());
    }
    else {
        return nullptr;
    }
}

long VManager::registerFunctionInternal(SharedFunction &function) {
    long generated_id = -1;
    do {
        generated_id = Utils::RANDOM_LONG(1, LONG_MAX, true);
    } while (!insertFunctionInternal(generated_id, function));
    return generated_id;
}

bool VManager::insertFunctionInternal(long funcId, SharedFunction &function) {
    function.setInternalId(funcId);
    return _functionTable->insertFunction(function);
}

FunctionUri* VManager::replaceFunction(long funcId, SharedFunction &function) {
    function.setInternalId(funcId);
    return _functionTable->replaceFunction(function);
}

bool VManager::findFunction(long internalId, SharedFunction &returnFunc) {
    return _functionTable->findFunction(internalId, returnFunc);
}