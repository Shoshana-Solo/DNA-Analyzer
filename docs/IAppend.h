//
// Created by shana on 8/19/20.
//

#ifndef DOCS_IAPPEND_H
#define DOCS_IAPPEND_H
#include "DNAMetadata.h"

class IAppend {
public:
    virtual DNAMetadata appendDNA(DnaSequence & newSeq , std::string seqName) = 0;
};


#endif //DOCS_IAPPEND_H
