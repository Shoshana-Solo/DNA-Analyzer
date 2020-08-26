#ifndef DOCS_DNAMETADATA_H
#define DOCS_DNAMETADATA_H

#include <cstddef>
#include <string>
#include "dna_sequence.h"

class DNAMetadata {
public:
    DNAMetadata(size_t m_id , std::string m_name ,DnaSequence m_dna);
    size_t getID();
    const std::string & getName();
    std::string getDna();
private:
    size_t m_id;
    std::string m_name;
    DnaSequence m_dna;
};

inline DNAMetadata::DNAMetadata(size_t id, std::string name, DnaSequence dna)
:m_id(id),
m_name(name),
m_dna(dna)
{}

inline size_t DNAMetadata::getID()
{
    return m_id;
}

inline const std::string & DNAMetadata::getName()
{
    return m_name;
}

inline std::string DNAMetadata::getDna()
{
    return m_dna.getSequence();
}



#endif //DOCS_DNAMETADATA_H
