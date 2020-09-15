#ifndef DNAANALYZER_SLICE_H
#define DNAANALYZER_SLICE_H


#include "IExecute.h"

class Slice: public IExecute{
public:
    explicit Slice(Collection *collection);
    ~Slice();
    /*virtual*/ std::string execute(const std::vector<std::string> & params);

private:
    DNAMetadata foundSequence(const std::string& seq);
    std::string foundName(const std::vector<std::string>& params, const DNAMetadata& dnaSeq);
    DnaSequence sliceSeq(const DNAMetadata& metadata, const std::string& startIndex, const std::string& endIndex);
    std::string foundUnusedName(std::string name);
    DNAMetadata* update(const DNAMetadata& manipulateSeq,const DnaSequence& sliceDna);
    DNAMetadata* append(const std::vector<std::string> & params,const DNAMetadata& manipulateSeq,DnaSequence& sliceDna);
    bool isInPlace(std::vector<std::string> params);
    bool isID(const std::string& id);
    bool isName(const std::string& name);
    IAppend * m_appendCollection;
    IGet* m_getCollection;
    IUpdate* m_updateCollection;
};


inline Slice::Slice(Collection *collection)
        :m_appendCollection(collection),
         m_getCollection(collection),
         m_updateCollection(collection)
{}


inline Slice::~Slice(){}



inline bool Slice::isInPlace(std::vector<std::string> params)
{
    return !(params.size() > 4 && params[4] == std::string(":"));
}


inline std::string Slice::foundUnusedName(std::string name)
{
    size_t i=0;
    try
    {
        while (++i)
        {
            m_getCollection->getDNAByName(name+"_s"+std::to_string(i));
        }
    }
    catch (const std::invalid_argument& e)
    {
        name += "_s" + std::to_string(i);
    }
    return name;
}

inline bool Slice::isID(const std::string &id)
{
    return id[0]=='#';
}

inline bool Slice::isName(const std::string &name)
{
    return name[0]=='@';
}

inline DnaSequence Slice::sliceSeq(const DNAMetadata& metadata, const std::string& startIndex, const std::string& endIndex)
{
    return metadata.getDna().slice(std::stoi(startIndex), std::stoi(endIndex));
}

inline DNAMetadata* Slice::update(const DNAMetadata& manipulateSeq,const DnaSequence& sliceDna)
{
    DNAMetadata updatedSeq(manipulateSeq.getID(),manipulateSeq.getName(),sliceDna);
    return new DNAMetadata(m_updateCollection->updateDna(updatedSeq));
}

inline DNAMetadata *Slice::append(const std::vector<std::string> & params,const DNAMetadata& manipulateSeq,DnaSequence& sliceDna)
{
    std::string name=foundUnusedName(foundName(params,manipulateSeq));
    return new DNAMetadata(m_appendCollection->appendDNA(sliceDna,name));
}


#endif //DNAANALYZER_SLICE_H

























































