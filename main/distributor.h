#ifndef __distributor_h__
#define __distributor_h__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <sstream>
#endif

#include <iostream>

class Distributor {

private:
    Distributor();

    ~Distributor();

public:
    static void DISTRIBUTE();

};

#endif