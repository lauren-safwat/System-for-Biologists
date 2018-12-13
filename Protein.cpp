#include "Protein.h"
#include "CodonsTable.h"
#include "Sequence.h"
#include <fstream>

Protein::Protein()
{
    //ctor
}

Protein :: Protein(char * p,Protein_Type type,int length):Sequence(length)
{
    type = type;
    setSeq(p);
}

Protein::Protein(const Protein & prot)
{
    type = prot.type;
    len = prot.len;
    setSeq(prot.seq);
}


void Protein::setProtein_Type(Protein_Type Type)
{
    type = Type;
}


void Protein::setProtein_Type()
{
    cout << "\nChoose the type of Protein: \n"
         << "1) Hormon \n"
         << "2) Enzyme \n"
         << "3) TF \n"
         << "4) Cellular_Function \n"
         << "Your choice is: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        type = Hormon;
        break;
    case 2:
        type = Enzyme;
        break;
    case 3:
        type = TF;
        break;
    case 4:
        type = Cellular_Function;
        break;
    }
}


Protein_Type Protein::getProtein_Type()
{
    return type;
}


Protein& Protein::operator=(const Protein& obj)
{
    type = obj.type;
    len = obj.len;
    setSeq(obj.seq);
    return *this;
}

bool Protein::operator== (Protein &obj)
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


bool Protein::operator!= (Protein &obj)
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


Protein Protein::operator+ (Protein &obj)
{
    if(type == obj.type)
    {
        Protein Res;
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
        return Res;
    }
    else
        cout << "They don't have the same type." << endl;
}

DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA, const CodonsTable & ct)
{
    DNA* d;
    d = new DNA[30];
    int nSeq=0;
    int seqLength = len*3;
    for(int i=0; i<bigDNA.getLen(); i++)
    {
        int counter=0;
        for(int j=0; j<len; j++)
            if(bigDNA.ConvertToRNA(i,i+seqLength-1).ConvertToProtein(ct).getSeq(j) == seq[j])
                counter++;
        if(counter == len)
        {
            d[nSeq].setLen(seqLength);
            d[nSeq].setDNA_Type(bigDNA.getDNA_Type());
            char* strand;
            strand = new char[seqLength];
            for(int j=0; j<seqLength; j++)
            {
                strand[j] = bigDNA.getSeq(i);
                i++;
            }
            d[nSeq].setSeq(strand);
            nSeq++;
        }
        else
            continue;
    }
    for(int i=nSeq; i<30; i++)
        d[nSeq].~DNA();
    return d;
}


void Protein::LoadSequenceFromFile(char* filename) {}


void Protein::SaveSequenceToFile(char* filename) {}


void Protein::Print()
{
    string Protein_types[4]= {"Hormon","Enzyme","TF","Cellular_Function"};
    cout << "Protein type: " << Protein_types[type-1] << endl;
    cout << "Protein sequence: ";
    for (int i=0; i<len; i++)
        cout << seq[i] << " ";
    cout << endl;
}


istream& operator>>(istream& in, Protein &obj)
{
    cout << "Enter the length of the Protein sequence: ";
    in >> obj.len;
    obj.seq = new char[obj.len];
    for (int i=0; i<obj.len; i++)
        in >> obj.seq[i];
    return in;
}


ostream& operator<<(ostream& out, Protein &obj)
{
    out << "Protein sequence: ";
    for (int i=0; i<obj.len; i++)
        out << obj.seq[i] << " ";
    out << endl;
    return out;
}



Protein::~Protein()
{
    delete seq;
}
