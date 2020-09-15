//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_CLI_H
#define DNAANALYZER_CLI_H


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class CLI{
public:
    std::vector<std::string> input();
    void output(std::string output);

private:
    std::vector<std::string> parse(std::string s);
};



#endif //DNAANALYZER_CLI_H
