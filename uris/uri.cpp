#include "uri.h"
template<typename T>
Uri<T>::Uri(long internalId, std::string externalId) {

}

template<typename T>
Uri<T>::~Uri() {

}

template<typename T>
bool Uri<T>::resolve() {

}

template<typename T>
std::string Uri<T>::getExternalId() {
    return _externalId;
}

template<typename T>
long Uri<T>::getInternalId() {
    return _internalId;
}