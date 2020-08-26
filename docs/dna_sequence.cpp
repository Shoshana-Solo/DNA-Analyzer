#include "dna_sequence.h"
#include <cstring> /*for strlen*/
#include <fstream> /*for read and write file*/

using std::cout;
using std::string;
using std::vector;


DnaSequence DnaSequence::pairing() const
{
	size_t i;
	size_t len=length();
	std::string sequence("");


	for(i=0;i<len;i++)
	{
		sequence+=m_sequence[len-i-1].getPair();
	}
	
	return DnaSequence(sequence);
}

size_t DnaSequence::find(const DnaSequence& sub_sequence) const
{

	size_t i,j;
	size_t len_sequence=length();
	size_t len_sub_sequence=sub_sequence.length();
	
	if(len_sub_sequence<=len_sequence)
	{
		for(i=0;i<len_sequence;++i)
		{
			for(j=0;j<len_sub_sequence;++j)
			{
				if(m_sequence[i+j]!=const_cast<DnaSequence&>(sub_sequence)[j])
					break;
			}
			if(j==len_sub_sequence)
				return i;
		}
	}
	return -1;
}

vector<size_t> DnaSequence::findAll(const DnaSequence& sub_sequence) const
{
	size_t i,j;
	size_t len_sequence=length();
	size_t len_sub_sequence=sub_sequence.length();
	vector<size_t> v;
	
	if(len_sub_sequence<=len_sequence)
	{
		for(i=0;i<len_sequence;++i)
		{
			for(j=0;j<len_sub_sequence;++j)
			{
				if(m_sequence[i+j]!=const_cast<DnaSequence&>(sub_sequence)[j])
					break;
			}
			if(j==len_sub_sequence)
				v.push_back(i);
		}
	}
	
	return v;

}

size_t DnaSequence::count(const DnaSequence& sub_sequence) const
{
	return findAll(sub_sequence).size();
}

vector<DnaSequence> DnaSequence::findConsensusSequences() const
{
	size_t i,j;
	vector<size_t> start_codons=findAll("ATG");
	
	vector<size_t> end_codons=findAll("TAG");
	
	vector<size_t> end_codons2=findAll("TAA");
	end_codons.insert(end_codons.end(),end_codons2.begin(),end_codons2.end());
	
	vector<size_t> end_codons3=findAll("TGA");
	end_codons.insert(end_codons.end(),end_codons3.begin(),end_codons3.end());
		
	size_t sum_of_start=start_codons.size();
	size_t sum_of_end=end_codons.size();
	vector<DnaSequence> consensus_sequences;
	
	for(i=0;i<sum_of_start;++i)
	{
		for(j=0;j<sum_of_end;++j)
		{
			if(end_codons[j]>start_codons[i])
				if((end_codons[j]-start_codons[i])%3==0)
					consensus_sequences.push_back(slice(start_codons[i]-1,end_codons[j]+3));
		}
	}

	return consensus_sequences;

}


DnaSequence readFromFile(const char * file_name) 
{ 

  std::ifstream ifs(file_name);
  std::string line( (std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()) );
	/*string line;
	std::ifstream myfile (file_name);
  
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
			getline (myfile,line);

		myfile.close();
	}

	else cout << "Unable to open file";*/
	const char *tmp=line.c_str();
	
	return DnaSequence(std::string(tmp,tmp+strlen(tmp)-3));
} 

void writeToFile(const char *file_name,const DnaSequence& ds)
{

	std::ofstream myfile (file_name);
	const char *data=ds.getSequence();
	if (myfile.is_open())
	{
		myfile << std::string(data,data+strlen(data)-3);
		myfile.close();
	}
	else cout << "Unable to open file";
}



