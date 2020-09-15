//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_IUPDATE_H
#define DNAANALYZER_IUPDATE_H


#include "DNAMetadata.h"

class IUpdate {
public:
    virtual DNAMetadata updateDna(const DNAMetadata& metadata) = 0;

};


#endif //DNAANALYZER_IUPDATE_H
