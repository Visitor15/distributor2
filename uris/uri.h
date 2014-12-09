#include <map>
#include <utility>

const static int SCHEME     = 0;
const static int USER_INFO  = 1;
const static int HOST       = 2;
const static int PORT       = 3;
const static int ACTION     = 4;
const static int ID         = 5;

typedef struct uri_t {
private:
    std::map<int, std::string> _uriMap;

    std::string tempUri;

public:
    uri_t() : _uriMap(), tempUri("NULL") {
        init();
    }

    void init() {
        std::make_pair(1, 1);
        _uriMap.insert(std::make_pair(SCHEME, ""));
        _uriMap.insert(std::make_pair(USER_INFO, ""));
        _uriMap.insert(std::make_pair(HOST, ""));
        _uriMap.insert(std::make_pair(PORT, ""));
        _uriMap.insert(std::make_pair(ACTION, ""));
        _uriMap.insert(std::make_pair(ID, ""));
    }

    std::string toString() {
        return tempUri;
//        std::string _str("");
//        _str.append(_uriMap.find(SCHEME)->second)
//            .append("://")
//            .append(_uriMap.find(USER_INFO)->second)
//            .append("@")
//            .append(_uriMap.find(HOST)->second)
//            .append(":")
//            .append(_uriMap.find(PORT)->second)
//            .append("/")
//            .append(_uriMap.find(ACTION)->second)
//            .append("#")
//            .append(_uriMap.find(ID)->second);
//        return _str;
    }

    void fromString(std::string uriStr) {
        std::cout << "Setting URI: " << uriStr << std::endl;
        tempUri = uriStr;
        std::cout << "SET URI TO : " << toString() << std::endl;
    }

} UriStruct;

template <class T>
class Uri {
private:
    std::string _externalId;

    long _internalId;

    UriStruct _uri;

public:
    Uri(long internalId, std::string externalId) {
        _internalId = internalId;
        _externalId = externalId;

        _uri.init();
    }

    virtual ~Uri() {}

    virtual std::string getExternalId() {
        return _externalId;
    }

    virtual long getInternalId() {
        return _internalId;
    }

    UriStruct getUriStruct() {
        return _uri;
    }

    virtual bool resolve() { return false; }

    virtual void buildFromUriString(std::string uriStr) = 0;

};