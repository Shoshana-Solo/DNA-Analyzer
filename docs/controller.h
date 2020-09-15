//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_CONTROLLER_H
#define DNAANALYZER_CONTROLLER_H


#include <iostream>
#include "CLI.h"
#include "collection.h"
#include "MapCommand.h"


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
         m_map(MapCommand(m_collection))
{}

inline void Controller::run()
{
    bool exit=false;

    while(!exit)
    {
        std::vector<std::string> parsedCommand = m_cli.input();
        IExecute * command = m_map.getCommandMap(parsedCommand[0]);

        if(command)
        {
            m_cli.output(command->execute(parsedCommand));
        }
        else
        {
            if (parsedCommand[0]=="exit")
                exit=true;
            else
            {
                m_cli.output("command not found");
            }
        }

    }
    std::cout<< "end run"<< std::endl;
}

#endif //DNAANALYZER_CONTROLLER_H
