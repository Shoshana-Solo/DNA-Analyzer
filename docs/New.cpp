//
// Created by linux on 9/13/20.
//

#include "New.h"
size_t New::s_serialName = 1;


std::string New::execute(const std::vector<std::string> & params)
{
    std::string dnaSeq = params[1];
    DnaSequence DNA(dnaSeq);
    std::string name = params.size() > 2 ? params[2].substr(1,params[2].size()-1) : "seq_" + std::to_string(s_serialName++);

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

    return "[" + std::to_string(metadata.getID()) + "] " + metadata.getName() + ": " + metadata.getDna().getSequence();

}
