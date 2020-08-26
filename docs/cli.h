#ifndef  __CLI_H__
#define  __CLI_H__

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


#endif //__CLI_H__