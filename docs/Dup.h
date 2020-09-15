//
// Created by linux on 9/14/20.
//

#ifndef DNAANALYZER_DUP_H
#define DNAANALYZER_DUP_H


#include "IExecute.h"

class Dup: public IExecute{
public:
    explicit Dup(Collection *collection);
    ~Dup();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    IAppend * m_appendCollection;
    IGet* m_getCollection;
};


inline Dup::Dup(Collection *collection)
        :m_appendCollection(collection),
         m_getCollection(collection)
{}


inline Dup::~Dup(){}


#endif //DNAANALYZER_DUP_H
