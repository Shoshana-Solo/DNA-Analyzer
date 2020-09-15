//
// Created by linux on 9/15/20.
//

#ifndef DNAANALYZER_PAIR_H
#define DNAANALYZER_PAIR_H


#include "IExecute.h"

class Pair: public IExecute{
public:
    explicit Pair(Collection *collection);
    ~Pair();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    DNAMetadata foundSequence(const std::string& seq);
    std::string foundName(const std::vector<std::string>& params, const DNAMetadata& dnaSeq);
    DnaSequence pairSeq(const DNAMetadata& metadata);
    std::string foundUnusedName(std::string name);
    DNAMetadata* update(const DNAMetadata& manipulateSeq,const DnaSequence& pairDna);
    DNAMetadata* append(const std::vector<std::string> & params,const DNAMetadata& manipulateSeq,DnaSequence& pairDna);
    bool isInPlace(std::vector<std::string> params);
    bool isID(const std::string& id);
    bool isName(const std::string& name);
    IAppend * m_appendCollection;
    IGet* m_getCollection;
    IUpdate* m_updateCollection;
};


inline Pair::Pair(Collection *collection)
        :m_appendCollection(collection),
         m_getCollection(collection),
         m_updateCollection(collection)
{}


inline Pair::~Pair(){}



inline bool Pair::isInPlace(std::vector<std::string> params)
{
    return !(params.size() > 2 && params[2] == std::string(":"));
}


inline std::string Pair::foundUnusedName(std::string name)
{
    size_t i=0;
    try
    {
        while (++i)
        {
            m_getCollection->getDNAByName(name+"_p"+std::to_string(i));
        }
    }
    catch (const std::invalid_argument& e)
    {
        name += "_p" + std::to_string(i);
    }
    return name;
}

inline bool Pair::isID(const std::string &id)
{
    return id[0]=='#';
}

inline bool Pair::isName(const std::string &name)
{
    return name[0]=='@';
}

inline DnaSequence Pair::pairSeq(const DNAMetadata& metadata)
{
    return metadata.getDna().pairing();
}

inline DNAMetadata* Pair::update(const DNAMetadata& manipulateSeq,const DnaSequence& pairDna)
{
    DNAMetadata updatedSeq(manipulateSeq.getID(),manipulateSeq.getName(),pairDna);
    return new DNAMetadata(m_updateCollection->updateDna(updatedSeq));
}

inline DNAMetadata *Pair::append(const std::vector<std::string> & params,const DNAMetadata& manipulateSeq,DnaSequence& pairDna)
{
    std::string name=foundName(params,manipulateSeq);
    return new DNAMetadata(m_appendCollection->appendDNA(pairDna,name));
}


#endif //DNAANALYZER_PAIR_H
