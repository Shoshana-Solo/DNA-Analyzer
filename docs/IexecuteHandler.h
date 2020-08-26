#ifndef __IEXECUTEHANDLER_H__
#define __IEXECUTEHANDLER_H__

#include <iostream>
#include <vector>
#include "collection.h"


class IExecuteHandler{
public:
    virtual std::string execute(const std::vector<std::string> & params) = 0;

private:

    IExecuteHandler * m_IExecuteHandler;
};

#endif //__IEXECUTEHANDLER_H__