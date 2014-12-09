#ifndef __function_data_h__
#define __function_data_h__

typedef struct raw_data_t {
private:

public:
    function_data_t() : _length(0) {}

    char* _buf;
    unsigned long _length;
} Blob;


typedef struct function_data_t {
public:
    function_data_t() : Blob(), _strData("") {}

    void setStringData(std::string str) {
        _strData(str);
    }

    std::string getStringData() {
        return _strData;
    }

    Blob getBlobData() {
        return _blob;
    }

    bool hasData() {
        return _blob._length > 0;
    }

private:
    Blob _blob;
    std::string _strData;

} FunctionData;

#endifvoid function_data_t::setStringData(char const *string){

}
