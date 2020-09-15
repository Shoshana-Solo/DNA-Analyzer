//
// Created by linux on 9/13/20.
//

#ifndef DNAANALYZER_IGET_H
#define DNAANALYZER_IGET_H


#include <string>
#include "DNAMetadata.h"

class IGet {
public:
    virtual DNAMetadata getDNAByName(const std::string& name) const = 0;
    virtual DNAMetadata getDNAById(size_t id) const = 0;
};


#endif //DNAANALYZER_IGET_H
