#ifndef __LOAD_H__
#define __LOAD_H__

#include <fstream>
#include "IexecuteHandler.h"
#include "dna_sequence.h"

class Load: public IExecuteHandler{
public:
    Load(Collection * collection);
    ~Load();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    IAppend * m_collection;
    static size_t s_serialName;
    std::string readFromFile(std::string fileName);
};
inline Load::Load(Collection *collection)
        :m_collection(collection)
{}

inline Load::~Load(){}


#endif //DNAANALIZER_LOAD_H
