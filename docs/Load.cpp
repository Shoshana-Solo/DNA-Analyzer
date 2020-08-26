#include "Load.h"
#include <sstream>

size_t Load::s_serialName = 1;

std::string Load::readFromFile(std::string fileName)
{
    std::string dnaSeq = "";
    std::string line;
    std::ifstream myfile("/home/shana/Desktop/c++/lessons/DNA_project/src/" + fileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            dnaSeq += line;
        }
        myfile.close();
    }

    return dnaSeq;

}

std::string Load::execute(const std::vector<std::string> & params)
{
    std::string dnaSeq = readFromFile(params[1]);
    DnaSequence DNA(dnaSeq);
    std::string name = (params.size() > 2 ?  params[2] : params[1] + "_" + std::to_string(s_serialName++));
    DNAMetadata metadata = m_collection->appendDNA(DNA , name);

    return "[" + std::to_string(metadata.getID()) + "] " + metadata.getName() + " : " + metadata.getDna();

}

