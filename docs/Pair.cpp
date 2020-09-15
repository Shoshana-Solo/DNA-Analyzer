//
// Created by linux on 9/15/20.
//

#include "Pair.h"



DNAMetadata Pair::foundSequence(const std::string& seq)
{
    if (isID(seq))
    {
        return m_getCollection->getDNAById(std::stoi(seq.substr(1, seq.size() - 1)));
    }
    if (isName(seq))
    {
        return m_getCollection->getDNAByName(seq.substr(1, seq.size() - 1));
    }

    throw std::invalid_argument(std::string("ERROR!\n USEGE: pair <seq> [: [@<new_seq_name>|@@]]\n"));
}

std::string Pair::foundName(const std::vector<std::string>& params, const DNAMetadata& dnaSeq)
{
    std::string name;
    if(params.size()>3 && params[3]!="@@")
    {
        name=params[3].substr(1,params[3].size()-1);
    }
    else
    {
        name=dnaSeq.getName();
    }
    return foundUnusedName(name);
}

std::string Pair::execute(const std::vector<std::string> &params)
{
    try
    {
        DNAMetadata *metadata, manipulatedSeq = foundSequence(params[1]);
        DnaSequence pairDna=pairSeq(manipulatedSeq);

        if (!isInPlace(params))
        {
            metadata=append(params, manipulatedSeq, pairDna);
        }
        else
        {
            metadata=update(manipulatedSeq, pairDna);
        }

        std::string ret= "[" + std::to_string(metadata->getID()) + "] " + metadata->getName() + ": " + metadata->getDna().getSequence();

        delete metadata;
        return ret;
    }

    catch (const std::exception& e)
    {
        return std::string("error in pair: "+std::string(e.what()));
    }
}

