//
// Created by linux on 9/14/20.
//

#include "Dup.h"


std::string Dup::execute(const std::vector<std::string> & params)
{
    const size_t id=std::stoi(params[1].substr(1,params[1].size()-1));

    DNAMetadata dnaSeq = m_getCollection->getDNAById(id);
    DnaSequence DNA(dnaSeq.getDna());

    std::string name = params.size() > 2 ? params[2].substr(1,params[2].size()-1) : dnaSeq.getName();

    size_t i=0;
    try
    {
        while (++i)
        {
            if(i!=2 || params.size()<=2)
                m_getCollection->getDNAByName(name+"_"+std::to_string(i));
        }
    }
    catch (const std::invalid_argument& e)
    {
        name+="_"+std::to_string(i);
    }

    DNAMetadata metadata = m_appendCollection->appendDNA(DNA , name);

    return "[" + std::to_string(metadata.getID()) + "] " + metadata.getName() + ": " + metadata.getDna().getSequence();

}