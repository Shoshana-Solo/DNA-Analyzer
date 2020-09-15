#include "Load.h"
#include <sstream>


std::string Load::readFromFile(std::string fileName)
{
    std::string seq="";
    std::string line;
    std::ifstream myfile("/home/shana/Desktop/c++/lessons/dna_project/src/" + fileName);

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            seq+=line;
        }
        myfile.close();
    }
    else
    {
        throw std::invalid_argument(fileName+": no such file or directory\n");
    }
    return seq;

}

std::string Load::execute(const std::vector<std::string> & params)
{
    try
    {
        std::string dnaSeq = readFromFile(params[1]);
        DnaSequence DNA(dnaSeq);

        size_t lastindex = params[1].find_last_of('.');
        std::string rawname = params[1].substr(0, lastindex);

        std::string name = params.size() > 2 ?  params[2] : rawname ;


        try
        {
            while (true)
            {
                m_getCollection->getDNAByName(name);
                name+="(1)";
            }
        }
        catch (const std::invalid_argument& e)
        {}

        DNAMetadata metadata = m_appendCollection->appendDNA(DNA , name);

        return "[" + std::to_string(metadata.getID()) + "] " + metadata.getName() + " : " + metadata.getDna().getSequence();

    }

    catch (const std::invalid_argument& e) {
        return e.what();
    }
}
