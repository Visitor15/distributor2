#include <bits/stringfwd.h>

typedef struct uri_t {

} UriStruct;

template <class T>
class Uri {
private:
    std::string _externalId;

    long _internalId;

public:
    std::string getExternalId() {
        return _externalId;
    }

    long getInternalId() {
        return _internalId;
    }

    bool resolve();

};