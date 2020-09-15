//
// Created by linux on 8/19/20.
//

#ifndef DNAANALYZER_DNAMETADATA_H
#define DNAANALYZER_DNAMETADATA_H


#include <cstddef>
#include <string>
#include "dna_sequence.h"

class DNAMetadata {
public:
    DNAMetadata(size_t id , std::string name ,DnaSequence dna);
    size_t getID() const;
    const std::string & getName() const;
    DnaSequence getDna() const;
//    void setStatus(bool isNew,bool isModified);
private:
    size_t m_id;
    std::string m_name;
    DnaSequence m_dna;
//    bool m_isNew;
//    bool m_isModified;
};

inline DNAMetadata::DNAMetadata(size_t id, std::string name, DnaSequence dna)
        :m_id(id),
         m_name(name),
         m_dna(dna)
//         m_isNew(1),
//         m_isModified(0)
{}

inline size_t DNAMetadata::getID() const
{
    return m_id;
}

inline const std::string & DNAMetadata::getName() const
{
    return m_name;
}

inline DnaSequence DNAMetadata::getDna() const
{
    return m_dna;
}

//void DNAMetadata::setStatus(bool isNew,bool isModified)
//{
//    m_isNew=isNew;
//    m_isModified=isModified;
//
//}



#endif //DNAANALYZER_DNAMETADATA_H
