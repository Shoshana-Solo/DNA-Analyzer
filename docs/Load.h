#ifndef DNAANALYZER_LOAD_H
#define DNAANALYZER_LOAD_H
#include <fstream>
#include "IExecute.h"
#include "dna_sequence.h"


class Load: public IExecute{
public:
    explicit Load(Collection *collection);
    ~Load();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    IAppend * m_appendCollection;
    IGet* m_getCollection;
    std::string readFromFile(std::string fileName);
};


inline Load::Load(Collection *collection)
        :m_appendCollection(collection),
        m_getCollection(collection)
{}


inline Load::~Load(){}


#endif //DNAANALYZER_LOAD_H
