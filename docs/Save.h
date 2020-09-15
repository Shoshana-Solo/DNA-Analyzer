//
// Created by linux on 9/13/20.
//

#ifndef DNAANALYZER_SAVE_H
#define DNAANALYZER_SAVE_H


#include <fstream>
#include "IExecute.h"
#include "dna_sequence.h"
#include "IGet.h"

class Save: public IExecute{
public:
    explicit Save(Collection *collection);
    ~Save();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    IGet* m_getCollection;


};


inline Save::Save(Collection *collection)
        :m_getCollection(collection)
//         m_updateStatusCollection(collection)
{}


inline Save::~Save(){}


#endif //DNAANALYZER_SAVE_H
