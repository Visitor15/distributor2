#include "distributor.h"

SharedFunction* sharedFunc1;
SharedFunction* sharedFunc2;
SharedFunction* sharedFunc3;

FunctionData* _functionData;

FunctionUri* _functionUri;

FunctionResponse* _functionRes;

FunctionRequest* _functionReq;


Distributor::Distributor() {

}

Distributor::~Distributor() {

}

void Distributor::DISTRIBUTE() {
    std::cout << "Time to distribute!" << std::endl;
    distributeInternal();
}

void Distributor::distributeInternal() {
    sharedFunc1 = new SharedFunction("TestSharedFunction1", Distributor::MY_SHARED_FUNCTION3);
    sharedFunc2 = new SharedFunction("TestSharedFunction2", Distributor::MY_SHARED_FUNCTION);
    sharedFunc3 = new SharedFunction("TestSharedFunction3", Distributor::MY_SHARED_FUNCTION2);

    _functionUri = VManager::GET_INSTANCE().registerFunction(*sharedFunc1);
    if(_functionUri != nullptr) {
        std::cout << "Instruction name: " << _functionUri->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(_functionUri->getInternalId()) << std::endl;

        _functionReq = new FunctionRequest("local://user:password@localhost:42424/request#" + _functionUri->getExternalId(), _functionUri);
        _functionReq->setRequestData(FunctionData());
        _functionRes = new FunctionResponse();
        std::cout << "Function URI: " << _functionReq->getFunctionUriString() << std::endl;
        if(_functionUri->resolve(_functionReq, *_functionRes)) {
            std::cout << "Instruction returned: " << _functionRes->getData().getStringData() << std::endl;
        }
        else {
            std::cout << "ERROR COULD NOT RESOLVE FUNCTION: " << sharedFunc1->getExternalId() << std::endl;
        }
    }
    else {
        std::cout << "ERROR REGISTERING FUNCTION: " << sharedFunc1->getExternalId() << std::endl;
    }

    _functionUri = VManager::GET_INSTANCE().registerFunction(*sharedFunc2);
    if(_functionUri != nullptr) {
        std::cout << "Instruction name: " << _functionUri->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(_functionUri->getInternalId()) << std::endl;

        _functionReq = new FunctionRequest("local://user:password@localhost:42424/request#" + _functionUri->getExternalId(), _functionUri);
        _functionReq->setRequestData(FunctionData());
        _functionRes = new FunctionResponse();
        std::cout << "Function URI: " << _functionReq->getFunctionUriString() << std::endl;
        if(_functionUri->resolve(_functionReq, *_functionRes)) {
            std::cout << "Instruction returned: " << _functionRes->getData().getStringData() << std::endl;
        }
        else {
            std::cout << "ERROR COULD NOT RESOLVE FUNCTION: " << sharedFunc2->getExternalId() << std::endl;
        }
    }
    else {
        std::cout << "ERROR REGISTERING FUNCTION: " << sharedFunc2->getExternalId() << std::endl;
    }

    _functionUri = VManager::GET_INSTANCE().registerFunction(*sharedFunc3);
    if(_functionUri != nullptr) {
        std::cout << "Instruction name: " << _functionUri->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(_functionUri->getInternalId()) << std::endl;

        _functionReq = new FunctionRequest("local://user:password@localhost:42424/request#" + _functionUri->getExternalId(), _functionUri);
        _functionReq->setRequestData(FunctionData());
        _functionRes = new FunctionResponse();
        std::cout << "Function URI: " << _functionReq->getFunctionUriString() << std::endl;
        if(_functionUri->resolve(_functionReq, *_functionRes)) {
            std::cout << "Instruction returned: " << _functionRes->getData().getStringData() << std::endl;
        }
        else {
            std::cout << "ERROR COULD NOT RESOLVE FUNCTION: " << sharedFunc3->getExternalId() << std::endl;
        }
    }
    else {
        std::cout << "ERROR REGISTERING FUNCTION: " << sharedFunc3->getExternalId() << std::endl;
    }
}

FunctionResponse Distributor::MY_SHARED_FUNCTION(FunctionData data) {
    data.setStringData("Hello, from MY_SHARED_FUNCTION!");
    return FunctionResponse(data);
}

FunctionResponse Distributor::MY_SHARED_FUNCTION2(FunctionData data) {
    data.setStringData("Hello, from MY_SHARED_FUNCTION2!");
    return FunctionResponse(data);
}

FunctionResponse Distributor::MY_SHARED_FUNCTION3(FunctionData data) {
    data.setStringData("Hello, from MY_SHARED_FUNCTION3!");
    return FunctionResponse(data);
}