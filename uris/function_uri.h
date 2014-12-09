#include <functions/function_request.h>
#include "functions/function_response.h"
#include "uri.h"

class FunctionUri : public Uri<FunctionUri> {
private:

public:
    FunctionUri(long internalId, std::string externalId);

    ~FunctionUri();

    bool resolve(FunctionRequest *request, FunctionResponse &response);

    virtual std::string getExternalId() {
        return Uri::getExternalId();
    }

    virtual long getInternalId() {
        return Uri::getInternalId();
    }

};