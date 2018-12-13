#include "CodonsTable.h"
#include <fstream>

CodonsTable::CodonsTable()
{
    LoadCodonsFromFile("RNA_codon_table.txt");
}


void CodonsTable::LoadCodonsFromFile(const char* codonsFileName)
{
    ifstream inFile;
    inFile.open (codonsFileName);
    for(int i=1; i<=64; i++)
    {
        inFile>>codons[i].value;

        if(i == 49 || i==51 || i==57)
            codons[i].AminoAcid = ' ';
        else
            inFile>>codons[i].AminoAcid;
    }
}


Codon CodonsTable:: getAminoAcid(char * value)
{
    Codon reqCodon;
    for(int i=0; i<3; i++)
        reqCodon.value[i] = value[i];
    for(int i=0; i<64; i++)
    {
        int counter=0;
        for(int j=0; j<3; j++)
            if(reqCodon.value[j] == codons[i].value[j])
                counter++;
        if(counter == 3)
        {
            reqCodon.AminoAcid = codons[i].AminoAcid;
            break;
        }
    }
    return reqCodon;
}


void CodonsTable :: setCodon(char * value, char AminoAcid, int index)
{
    Codon reqCodon;
    for(int i=0; i<3; i++)
        reqCodon.value[i]=value[i];
    reqCodon.AminoAcid=AminoAcid;
    codons[index]= reqCodon;
}


CodonsTable::~CodonsTable(){}
