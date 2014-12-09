#include <functions/function_request.h>
#include "uri.h"

class FunctionUri : Uri<FunctionUri> {
private:

public:
    FunctionUri(long internalId, std::string externalId);

    ~FunctionUri();

    bool resolve(FunctionRequest *request, FunctionResponse &response);

};