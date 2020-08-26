#ifndef __DNA__SEQUENCE_H__
#define __DNA__SEQUENCE_H__

#include <string> /*for string*/
#include <cstring> /*for strlen*/
#include <iostream> /*for cout*/
#include <map> /*for map*/
#include <vector> /*for vector*/


inline static bool isCorrect(char c)
{
	const char *values="ATGC";
	size_t i,size=strlen(values);
	
	for(i=0;i<size;++i)
		if (values[i]==c)
			return true;
	if(c=='\0')
		return true;
		
	return false;
} 

class ValueError : public std::exception
{
public:
	virtual const char* what() const throw()
  	{
    		return "The string should contain only  A, C, T or G.";
  	}
};

class DnaSequence
{

class Nucleotide
    {
        char value; // Reference to the element to be modified

    public:
	Nucleotide(){}
	Nucleotide(char v);
        Nucleotide& operator=(char const& i);
        operator char() // This is required for getting a char value from a Nucleotide, which make the cout-lines work
        {
            return value;
        }
        const char getPair()
        {
        std::map <char, char>m;
	m['A']='T';
	m['T']='A';
	m['C']='G';
	m['G']='C';
	return m[value];
        }
    };
public:
	DnaSequence(const char* sequence);
	DnaSequence(const std::string& sequence);
	DnaSequence(const DnaSequence &dss);
	~DnaSequence();
	DnaSequence& operator = (const DnaSequence &ds);
	Nucleotide operator [](size_t index) const;
	Nucleotide& operator [](size_t index);
	const char* getSequence() const;
	size_t length() const;
	DnaSequence slice(size_t start_index, size_t end_index) const;
	DnaSequence pairing() const;
	size_t find(const DnaSequence& sub_sequence) const;
	size_t count(const DnaSequence& sub_sequence) const;
	std::vector<size_t> findAll(const DnaSequence& sub_sequence) const;
	std::vector<DnaSequence> findConsensusSequences() const;

private:
	Nucleotide *m_sequence;

friend std::ostream& operator<<(std::ostream& os, const DnaSequence& ds);
    
};


inline DnaSequence::DnaSequence(const char* sequence)
{
	size_t i;
	if (sequence==NULL)
		sequence="";
		
	m_sequence = new Nucleotide[strlen(sequence)+1];
	
	for (i=0;i<=strlen(sequence);++i)
	{
	m_sequence[i]=sequence[i];
	}

}
inline DnaSequence::DnaSequence(const std::string& sequence)
{
	size_t i;
	
	m_sequence = new Nucleotide[strlen(sequence.c_str())+1];
	
	for (i=0;i<=strlen(sequence.c_str());++i)
	{
		m_sequence[i]=sequence.c_str()[i];
	}
}
inline DnaSequence::DnaSequence(const DnaSequence &ds)
{
	size_t i;
	
	m_sequence = new Nucleotide[ds.length()+1];
	
	for (i=0;i<=ds.length();++i)
	{
		m_sequence[i]=ds.m_sequence[i];
	} 
}

inline DnaSequence::~DnaSequence()
{
	delete []m_sequence;
	m_sequence=NULL;
}

inline size_t DnaSequence::length() const
{
	size_t len=0;
	
	while(m_sequence[len]!=Nucleotide('\0'))
	{
		len++;
	}
	
	return len;
}

inline DnaSequence& DnaSequence::operator = (const DnaSequence &rhs)
{ 
	size_t i;
	Nucleotide *tmp=m_sequence;
	
	m_sequence=new Nucleotide[rhs.length()+1];
	delete [] tmp;
	
	for (i=0;i<rhs.length();++i)
	{
		m_sequence[i]=rhs.m_sequence[i];
	}

        return *this; 
}

inline const char* DnaSequence::getSequence() const
{
	size_t i;
	
	char *sequence=new char[length()+1];
	
	for(i=0;i<length();++i)
	{
		sequence[i]=m_sequence[i];
	}
	
	return sequence;
}

inline bool operator==(const DnaSequence& lhs, const DnaSequence& rhs)
{
	return !strcmp(lhs.getSequence(),rhs.getSequence());
}

inline bool operator!=(const DnaSequence& lhs, const DnaSequence& rhs)
{
	return strcmp(lhs.getSequence(),rhs.getSequence());
}

inline std::ostream& operator<<(std::ostream& os, const DnaSequence& ds)
{
	return os<<ds.getSequence();
}


inline DnaSequence::Nucleotide DnaSequence::operator[](size_t index) const
{
	if(index<0||index>length()-1)
		throw std::out_of_range("index out of range");
		
	return m_sequence[index];
}
inline DnaSequence::Nucleotide& DnaSequence::operator [](size_t index)
{
	if(index<0||index>length()-1)
		throw std::out_of_range("index out of range");
		
	return m_sequence[index];
}

inline DnaSequence DnaSequence::slice(size_t start_index, size_t end_index) const
{
	if((start_index+1)<0 || end_index>length()){
		throw std::out_of_range("index out of range!");}
		
	size_t i;
	std::string sequence("");
	
	for(i=start_index+1;i<end_index;++i)
	{
		sequence+=static_cast<char>(m_sequence[i]);	
	}

	return DnaSequence(sequence);
}

inline DnaSequence::Nucleotide::Nucleotide(char v)  
{
        if (!isCorrect(v))
		throw ValueError();
	else
		value=v;
}
	
inline DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(char const& i)
{
	if (isCorrect(i))
		value = i;
	else
		throw ValueError();
	
	return *this;
}

DnaSequence readFromFile(const char * file_name);

void writeToFile(const char *file_name,const DnaSequence& ds);

#endif
