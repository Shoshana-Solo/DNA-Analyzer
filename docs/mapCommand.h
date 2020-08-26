#ifndef __MAPCOMMAND_H__
#define __MAPCOMMAND_H__

#include <map>
//#include "cli.h"
#include "executeHandler.h"
#include "Load.h"


class MapCommand
{
public:
    MapCommand(Collection * collection);
    IExecuteHandler * getCommandMap(std::string command);

private:
    std::map<std::string, IExecuteHandler *> m_commands;
};

inline MapCommand::MapCommand(Collection * collection)
{
    m_commands.insert(std::pair<std::string ,IExecuteHandler *>("load",new Load(collection)));
}

inline IExecuteHandler * MapCommand::getCommandMap(std::string command)
{
    return m_commands[command];
}


#endif //__MAPCOMMAND_H__