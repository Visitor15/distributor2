#include <functions/function_request.h>
#include "functions/function_response.h"
#include "uri.h"

class FunctionUri : public Uri<FunctionUri> {
private:

public:
    FunctionUri(long internalId, std::string externalId);

    FunctionUri(std::string uriStr);

    ~FunctionUri();

    bool resolve(FunctionRequest *request, FunctionResponse &response);

    virtual bool resolve() { return false; }

    virtual void buildFromUriString(std::string uriStr);

    std::string getExternalId();

    long getInternalId();

};