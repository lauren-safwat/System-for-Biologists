#include "DNA.h"
#include "RNA.h"
class RNA;
DNA::DNA()
{
    startIndex = 0;
    endIndex = len;
}



DNA::DNA(char * seq,DNA_Type atype, int Length):Sequence(Length)
{
    startIndex = 0;
    endIndex = len;
    type = atype;
    setSeq(seq);
    BuildComplementaryStrand();
}

DNA::DNA(DNA& rhs)
{
    type = rhs.type;
    len  = rhs.len;
    setSeq(rhs.seq);
    BuildComplementaryStrand();
}


void DNA::setDNA_Type()
{
    cout << "\nChoose the type of DNA: \n"
         << "1) promoter \n"
         << "2) motif \n"
         << "3) tail \n"
         << "4) noncoding \n"
         << "Your choice is: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        type = promoter;
        break;
    case 2:
        type = motif;
        break;
    case 3:
        type = tail;
        break;
    case 4:
        type = noncoding;
        break;
    }
}


void DNA::setDNA_Type(DNA_Type Type)
{
    type = Type;
}


DNA_Type DNA::getDNA_Type()
{
    return type;
}


DNA* DNA::getComplementaryStrand()
{
    return complementary_strand;
}


DNA& DNA::operator=(const DNA& obj)
{
    type = obj.type;
    len = obj.len;
    setSeq(obj.seq);
    BuildComplementaryStrand();
    return *this;
}

void DNA::BuildComplementaryStrand()
{
    complementary_strand = new DNA ;
    complementary_strand->len = len;
    complementary_strand->seq = new char [len] ;
    for (int i = 0 ; i < len ; i++)
    {
        switch (seq[i])
        {
        case 'T':
            complementary_strand->seq[i]='A';
            break;
        case 'A':
            complementary_strand->seq[i]='T';
            break;
        case 'G':
            complementary_strand->seq[i]='C';
            break;
        case 'C':
            complementary_strand->seq[i]='G';
            break;
        }
    }

    for(int i=0 ; i < ((len / 2)) ; i++ )
    {

        swap(complementary_strand->seq[i], complementary_strand->seq[len-1-i]);

    }
}


RNA DNA:: ConvertToRNA(int Start, int End)
{
    char *seq2;
    int length = End - Start + 1;
    if(Start == -1 && End == -1)
    {
        Start = 0;
        End = len;
        length = len;
    }
    seq2= new char [length];
    for(int i=0; i<length; i++)
    {
        if(complementary_strand->seq[Start]=='T')
            seq2[i]='U';
        else
            seq2[i]=complementary_strand->seq[Start];
        Start++;
    }
    RNA rna(seq2, mRNA, length);
    int choice2;
    cout << "\nDo you want to change the default type (mRNA) of the resulting RNA sequence: \n"
         << "1) Yes\n"
         << "2) No\n";
    cin >> choice2;
    if (choice2 == 1)
        rna.setRNA_Type();
    return rna;
}


void DNA::Print()
{
    string DNA_types[4]= {"promoter","motif","tail","noncoding"};
    cout << "DNA type: " << DNA_types[type-1] << endl;
    cout << "1st strand: ";
    for (int i=0; i<len; i++)
        cout << seq[i] << " ";
    cout << endl << "2nd strand: ";
    for (int i=0; i<len; i++)
        cout << complementary_strand->seq[i] << " ";
    cout << endl;
}



bool DNA::operator== (DNA &obj)
{
    int counter=0;
    if((type != obj.type) || (len != obj.len))
        return false;
    else
    {
        for(int i=0; i<len; i++)
            if(seq[i] == obj.seq[i])
                counter++;
        if(counter == len)
            return true;
        else
            return false;

    }
}


bool DNA::operator!= (DNA &obj)
{
    int counter=0;
    if((type != obj.type) || (len != obj.len))
        return true;
    else
    {
        for(int i=0; i<len; i++)
            if(seq[i] == obj.seq[i])
                counter++;
        if(counter == len)
            return false;
        else
            return true;

    }
}


DNA DNA::operator+ (DNA &obj)
{
    if(type == obj.type)
    {
        DNA Res;
        Res.type = type;
        Res.len = len + obj.len;
        Res.seq = new char[Res.len];
        int index=0;
        for(int i=0; i<len; i++)
        {
            Res.seq[index] = seq[i];
            index++;
        }
        for(int i=0; i<obj.len; i++)
        {
            Res.seq[index] = obj.seq[i];
            index++;
        }
        Res.BuildComplementaryStrand();
        return Res;
    }
    else
        cout << "They don't have the same type." << endl;
}

void DNA::LoadSequenceFromFile(char* filename) {}


void DNA::SaveSequenceToFile(char* filename) {}


istream& operator>>(istream& in, DNA &obj)
{
    obj.setDNA_Type();
    cout << "Enter the length of the DNA strand: ";
    in >> obj.len;
    obj.seq = new char[obj.len];
    cout << "Enter DNA sequence: ";
    for (int i=0; i<obj.len; i++)
        in >> obj.seq[i];
    obj.BuildComplementaryStrand();
    return in;
}


ostream& operator<<(ostream& out, DNA &obj)
{
    out << "DNA sequence is: ";
    for(int i=0; i<obj.len; i++)
        out << obj.seq[i] << " ";
    out << endl;
    return out;
}



DNA::~DNA()
{
    delete seq;
}
