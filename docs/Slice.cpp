//
// Created by linux on 9/14/20.
//

#include "Slice.h"


DNAMetadata Slice::foundSequence(const std::string& seq)
{
    if (isID(seq))
    {
        return m_getCollection->getDNAById(std::stoi(seq.substr(1, seq.size() - 1)));
    }
    if (isName(seq))
    {
        return m_getCollection->getDNAByName(seq.substr(1, seq.size() - 1));
    }

    throw std::invalid_argument(
            std::string("ERROR!\n USEGE: slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]\n"));
}

std::string Slice::foundName(const std::vector<std::string>& params, const DNAMetadata& dnaSeq)
{
    std::string name;
    if(params.size()>5 && params[5]!="@@")
    {
        name=params[5].substr(1,params[5].size()-1);
    }
    else
    {
        name=dnaSeq.getName();
    }
    return name;
}

std::string Slice::execute(const std::vector<std::string> &params)
{
    try
    {
        DNAMetadata *metadata,manipulateSeq= foundSequence(params[1]);
        DnaSequence sliceDna=sliceSeq(manipulateSeq,params[2], params[3]);

        if (!isInPlace(params))
        {
            metadata=append(params,manipulateSeq,sliceDna);
        }
        else
        {
            metadata=update(manipulateSeq,sliceDna);
        }

        std::string ret= "[" + std::to_string(metadata->getID()) + "] " + metadata->getName() + ": " + metadata->getDna().getSequence();

        delete metadata;
        return ret;
    }

    catch (const std::exception& e)
    {
        return std::string("error in slice: "+std::string(e.what()));
    }
}


