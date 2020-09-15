//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_MAPCOMMAND_H
#define DNAANALYZER_MAPCOMMAND_H


#include <map>
#include "Load.h"
#include "New.h"
#include "Save.h"
#include "Dup.h"
#include "Slice.h"
#include "Pair.h"


class MapCommand
{
public:
    explicit MapCommand(Collection& collection);
    IExecute * getCommandMap(std::string command);

private:
    std::map<std::string, IExecute *> m_commands;
};

inline MapCommand::MapCommand(Collection& collection)
{
    m_commands.insert(std::pair<std::string ,IExecute *>("load", new Load(&collection)));
    m_commands.insert(std::pair<std::string ,IExecute *>("new", new New(&collection)));
    m_commands.insert(std::pair<std::string ,IExecute *>("save", new Save(&collection)));
    m_commands.insert(std::pair<std::string ,IExecute *>("dup", new Dup(&collection)));
    m_commands.insert(std::pair<std::string ,IExecute *>("slice", new Slice(&collection)));
    m_commands.insert(std::pair<std::string ,IExecute *>("pair", new Pair(&collection)));
}

inline IExecute * MapCommand::getCommandMap(std::string command)
{
    return m_commands[command];
}



#endif //DNAANALYZER_MAPCOMMAND_H
