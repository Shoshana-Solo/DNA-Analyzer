#include "CLI.h"



std::vector<std::string> CLI::input()
{
    std::cout << "cmd >>> ";
    std::string cmd;
    std::getline(std::cin, cmd);
    return parse(cmd);
}

std::vector<std::string> CLI::parse(std::string command)
{
    std::vector<std::string> parsedCommand;
    std::string word;
    std::stringstream iss( command );
    while ( iss >> word )
        parsedCommand.push_back( word );

    return parsedCommand;
}

void CLI::output(std::string output)
{
    if (output!=std::string(""))
    {
        std::cout << output << std::endl;
    }

}