#include "Save.h"


std::string Save::execute(const std::vector<std::string> & params)
{
    try
    {
        std::string dnaSeq=m_getCollection->getDNAByName(params[1]).getDna().getSequence();
        std::string fileName="/home/shana/Desktop/c++/lessons/dna_project/src/" + ((params.size() > 2?  params[2] : params[1] )+ ".rawdna");

        std::ofstream myfile;
        myfile.open (fileName);
        myfile << dnaSeq;
        myfile.close();

//        m_updateStatusCollection->updateStatus(params[1],'S');
        return std::string("");
    }
    catch (const std::invalid_argument& e)
    {
        return std::string("Sequence does not exist");
    }

}
