#include "RNA.h"

RNA::RNA(){}


RNA::RNA(char * seq, RNA_Type atype, int length):Sequence (length)
{
    type = atype;
    setSeq(seq);
}


RNA::RNA(RNA& rhs)
{
    type = rhs.type;
    len = rhs.len;
    setSeq(rhs.seq);
}


void RNA::setRNA_Type(RNA_Type Type)
{
    type = Type;
}


void RNA::setRNA_Type()
{
    cout << "\nChoose the type of RNA: \n"
         << "1) mRNA \n"
         << "2) pre_mRNA \n"
         << "3) mRNA_exon \n"
         << "4) mRNA_intron \n"
         << "Your choice is: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        type = mRNA;
        break;
    case 2:
        type = pre_mRNA;
        break;
    case 3:
        type = mRNA_exon;
        break;
    case 4:
        type = mRNA_intron;
        break;
    }
}


RNA_Type RNA::getRNA_Type()
{
    return type;
}


DNA RNA::ConvertToDNA()
{
    DNA dna;
    dna.setLen(len);
    dna.setDNA_Type();
    for (int i=0; i<len; i++)
    {
        switch (seq[i])
        {
        case 'U':
            dna.setSeq(i, 'A');
            break;
        case 'A':
            dna.setSeq(i, 'T');
            break;
        case 'G':
            dna.setSeq(i, 'C');
            break;
        case 'C':
            dna.setSeq(i, 'G');
            break;
        }
    }

    for(int i=0; i<len/2; i++)
    {
        char temp;
        temp = dna.getSeq(i);
        dna.setSeq(i, dna.getSeq(len-i-1));
        dna.setSeq(len-i-1, temp);
    }
    dna.BuildComplementaryStrand();
    return dna;
}


Protein& RNA :: ConvertToProtein(CodonsTable table)
{
    int length;
    if (len%3 != 0)
    {
        cout<<"invalid conversion"<<endl;
    }
    else if (len%3 == 0)
    {
        Codon* C;
        length=len/3;
        cout << length;
        C = new Codon[length];
        int num=0;
        char *prot;
        prot = new char [length];

        for (int i=0; i<length; i++)
        {
            for (int j=0; j<3; j++)
            {
                C[i].value[j] = seq[num];
                num++;
            }
            C[i].AminoAcid = table.getAminoAcid(C[i].value).AminoAcid;
            prot[i] = C[i].AminoAcid;
            cout << endl << C[i].value << "->" << C[i].AminoAcid;
        }
        Protein object(prot, Cellular_Function, length);
        return object;
    }

}



RNA::~RNA()
{
    delete seq ;
}

void RNA::LoadSequenceFromFile(char* filename) {}


void RNA::SaveSequenceToFile(char* filename) {}



void RNA::Print()
{
    string RNA_types[4]= {"mRNA","pre_mRNA","mRNA_exon","mRNA_intron"};
    cout << "RNA type: " << RNA_types[type-1] << endl;
    cout << "RNA sequence: ";
    for (int i=0; i<len; i++)
        cout << seq[i] << " ";
    cout << endl;
}


RNA& RNA::operator=(const RNA& obj)
{
    type = obj.type;
    len = obj.len;
    setSeq(obj.seq);
    return *this;
}


bool RNA::operator== (RNA &obj)
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


bool RNA::operator!= (RNA &obj)
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


RNA RNA::operator+ (RNA &obj)
{
    if(type == obj.type)
    {
        RNA Res;
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


istream& operator>>(istream& in, RNA &obj)
{
    obj.setRNA_Type();
    cout << "Enter the length of the RNA sequence: ";
    in >> obj.len;
    obj.seq = new char[obj.len];
    cout << "Enter RNA sequence: ";
    for (int i=0; i<obj.len; i++)
        in >> obj.seq[i];
    return in;
}


ostream& operator<<(ostream& out, RNA &obj)
{
    out << "RNA sequence: ";
    for (int i=0; i<obj.len; i++)
        out << obj.seq[i] << " ";
    out << endl;
    return out;
}
