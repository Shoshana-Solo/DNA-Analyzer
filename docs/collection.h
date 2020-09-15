//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_COLLECTION_H
#define DNAANALYZER_COLLECTION_H



#include <vector>
#include "DNAMetadata.h"
#include "IAppend.h"
#include "IUpdate.h"
#include "IDelete.h"
#include "IGet.h"
//#include "IUpdateStatus.h"

class Collection:public IAppend ,public IDelete, public IUpdate,public IGet{
public:
    /*virtual*/ DNAMetadata appendDNA(DnaSequence & newSeq , std::string seqName);
    /*virtual*/ DNAMetadata getDNAByName(const std::string& name) const;
    /*virtual*/ DNAMetadata  getDNAById(size_t id) const;
    /*virtual*/ DNAMetadata updateDna(const DNAMetadata& metadata);
//    void updateStatus(const std::string& name, bool isNew, bool isModified);
//    void decNumOfModified();
//    void decNumOfNew();
//    void incNumOfModified();
//    void incNumOfNew();
    static size_t s_id;
//    static size_t s_numOfModifiedSeq;
//    static size_t s_numOfNewSeq;

private:
    std::vector<DNAMetadata> m_dnaCollection;
};

inline DNAMetadata Collection::appendDNA(DnaSequence & newSeq , std::string seqName)
{
    DNAMetadata metadata(s_id++ , seqName , newSeq);
    m_dnaCollection.push_back(metadata);

    return metadata;
}

inline DNAMetadata Collection::getDNAByName(const std::string &name) const
{
    for (size_t i = 0; i < m_dnaCollection.size(); ++i)
    {
        if (m_dnaCollection[i].getName() == name)
        {
            return m_dnaCollection[i];
        }
    }

    throw std::invalid_argument("get DNA By Name: name doesn't exist");
}


inline DNAMetadata Collection::getDNAById(size_t id) const
{
    for (size_t i = 0; i < m_dnaCollection.size(); ++i)
    {
        if (m_dnaCollection[i].getID()==id)
        {
            return m_dnaCollection[i];
        }
    }

    throw std::invalid_argument("get DNA By Id: ID doesn't exist");
}

inline DNAMetadata Collection::updateDna(const DNAMetadata &metadata)
{
    for (size_t i = 0; i < m_dnaCollection.size(); ++i)
    {
        if (m_dnaCollection[i].getID()==metadata.getID())
        {
            m_dnaCollection[i]=metadata;
            return m_dnaCollection[i];
        }
    }

    throw std::invalid_argument("update Dna: ID "+std::to_string(metadata.getID())+std::string(" doesn't exist"));
}

//void Collection::updateStatus(const std::string& name, bool isNew, bool isModified, bool old=0)
//{
//    for (size_t i = 0; i < m_dnaCollection.size(); ++i)
//    {
//        if (m_dnaCollection[i].getName()==name)
//        {
//             m_dnaCollection[i].setStatus(isNew,isModified);
//             if(!isModified&&!isNew)
//             {
//
//             }
//             else
//             {
//                 s_numOfModifiedSeq+=isModified;
//                 s_numOfNewSeq+=isNew;
//
//                 s_numOfModifiedSeq-=isNew;
//                 s_numOfNewSeq-=isModified;
//             }
//        }
//    }
//}
//
//void Collection::decNumOfModified()
//{
//    --s_numOfModifiedSeq;
//}
//
//void Collection::decNumOfNew()
//{
//    --s_numOfNewSeq;
//}
//
//void Collection::incNumOfModified()
//{
//    ++s_numOfModifiedSeq;
//}
//
//void Collection::incNumOfNew()
//{
//    ++s_numOfNewSeq;
//}


#endif //DNAANALYZER_COLLECTION_H
