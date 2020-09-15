//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_IEXECUTE_H
#define DNAANALYZER_IEXECUTE_H


#include <iostream>
#include <vector>
#include "collection.h"

//class Params;

class IExecute{
public:
    virtual std::string execute(const std::vector<std::string> & params) = 0;
};


#endif //DNAANALYZER_IEXECUTE_H
