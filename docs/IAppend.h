//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_IAPPEND_H
#define DNAANALYZER_IAPPEND_H
#include "DNAMetadata.h"

class IAppend {
public:
    virtual DNAMetadata appendDNA(DnaSequence & newSeq , std::string seqName) = 0;
};



#endif //DNAANALYZER_IAPPEND_H
