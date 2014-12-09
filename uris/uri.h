#include <bits/stringfwd.h>
#include <bits/basic_string.h>

static const int SCHEME     = 0;
static const int USER_INFO  = 1;
static const int HOST       = 2;
static const int PORT       = 3;
static const int ACTION     = 4;
static const int ID         = 5;

static const enum URI_SCHEME {

};

typedef struct uri_t {
private:
    std::map<int, std::string> _uriMap;

public:
    uri_t() : init() {}

    void init() {
        _uriMap.insert(std::make_pair<int, std::string>(SCHEME, ""));
        _uriMap.insert(std::make_pair<int, std::string>(USER_INFO, ""));
        _uriMap.insert(std::make_pair<int, std::string>(HOST, ""));
        _uriMap.insert(std::make_pair<int, std::string>(PORT, ""));
        _uriMap.insert(std::make_pair<int, std::string>(ACTION, ""));
        _uriMap.insert(std::make_pair<int, std::string>(ID, ""));
    }

    std::string toString() {
        std::string _str("");
        _str.append(_uriMap.find(SCHEME))
            .append("://")
            .append(_uriMap.find(USER_INFO))
            .append("@")
            .append(_uriMap.find(HOST))
            .append(":")
            .append(_uriMap.find(PORT))
            .append("/")
            .append(_uriMap.find(ACTION))
            .append("#")
            .append(_uriMap.find(ID));
        return _str;
    }

} UriStruct;

template <class T>
class Uri {
private:
    std::string _externalId;

    long _internalId;

    UriStruct _uri;

public:
    Uri(long internalId, std::string externalId);

    std::string getExternalId() {
        return _externalId;
    }

    long getInternalId() {
        return _internalId;
    }

    bool resolve();

};