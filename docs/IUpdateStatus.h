//
// Created by linux on 9/14/20.
//

#ifndef DNAANALYZER_IUPDATESTATUS_H
#define DNAANALYZER_IUPDATESTATUS_H


#include <cstddef>
#include <string>

class IUpdateStatus {
public:
    virtual void updateStatus(std::string name,char newStatus) = 0;

};


#endif //DNAANALYZER_IUPDATESTATUS_H
