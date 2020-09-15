//
// Created by linux on 9/13/20.
//

#ifndef DNAANALYZER_NEW_H
#define DNAANALYZER_NEW_H


#include "IExecute.h"
#include "dna_sequence.h"


class New: public IExecute{
public:
    explicit New(Collection *collection);
    ~New();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    IAppend * m_appendCollection;
    IGet* m_getCollection;
    static size_t s_serialName;
};


inline New::New(Collection *collection)
        :m_appendCollection(collection),
         m_getCollection(collection)
{}


inline New::~New(){}


#endif //DNAANALYZER_NEW_H
