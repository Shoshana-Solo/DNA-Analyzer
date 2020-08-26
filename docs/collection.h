#ifndef  __COLLECTION_H__
#define  __COLLECTION_H__
#include <iostream>
#include <vector>
#include <IAppend.h>
#include <IUpdate.h>
#include <IDelete.h>

class Collection:public IAppend , public IUpdate ,public IDelete{
public:
    /*virtual*/ DNAMetadata appendDNA(DnaSequence & newSeq , std::string seqName);
    std::string getDNAByName(DnaSequence & seq){return  "in getDNAByName";}
    size_t getDNAById(DnaSequence & seq){return  1;}

    static size_t s_id;
//    static std::string s_name;

private:
    std::vector<DNAMetadata> m_dnaCollection;
};

inline DNAMetadata Collection::appendDNA(DnaSequence & newSeq , std::string seqName)
{
    DNAMetadata metadata(s_id++ , seqName , newSeq);
    m_dnaCollection.push_back(metadata);
    return metadata;
}

#endif //__COLLECTION_H__