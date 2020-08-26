
#ifndef  __CONTROLLER_H__
#define  __CONTROLLER_H__
#include <iostream>
#include "cli.h"
#include "collection.h"
#include "executeHandler.h"
#include "mapCommand.h"

//class Collection;
//class CLI;
//class ExecuteHandler;

class Controller{
public:
    Controller();
    void run();

private:
    Collection m_collection;
    CLI m_cli;
    MapCommand m_map;
};

inline Controller::Controller()
:m_collection(Collection()),
m_cli(CLI()),
m_map(MapCommand(&m_collection))
{}

inline void Controller::run()
{
    std::vector<std::string> parsedCommand = m_cli.input();
    IExecuteHandler * command = m_map.getCommandMap(parsedCommand[0]);
    if(command)
    {
        m_cli.output(command->execute(parsedCommand));
    }

    else
    {
        m_cli.output("command not found");
    }
    std::cout<< "end run"<< std::endl;
}


#endif //__CONTROLLER_H__