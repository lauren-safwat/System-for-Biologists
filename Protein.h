#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "CodonsTable.h"
#include <iostream>
#include <fstream>


using namespace std ;
class DNA;
class CodonsTable;

enum Protein_Type {Hormon=1, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
private:
    Protein_Type type;
public:
    /** Default constructor **/
    Protein();

    /** Parameterized constructor **/
    Protein(char * p, Protein_Type type, int length);

    /** Copy constructor **/
    Protein(const Protein & prot) ;

    /** Destructor **/
    ~Protein() ;

    /** Setters **/
    void setProtein_Type(Protein_Type Type);
    void setProtein_Type();

    /** Getters **/
    Protein_Type getProtein_Type();

    /** Function that returns an array of DNA sequences that can possibly generate that protein sequence **/
    DNA* GetDNAStrandsEncodingMe(DNA & bigDNA, const CodonsTable & ct);

    /** Function to load sequence from file **/
    void LoadSequenceFromFile(char* filename);

    /** Function to save sequence to file **/
    void SaveSequenceToFile(char* filename);

    /** Function printing Protein sequence information to user **/
    void Print();

    /** Overloading the assignment operator **/
    Protein& operator=(const Protein& obj);

    /** Overloading the operator == to check if 2 Protein objects are equal **/
    bool operator== (Protein &obj);

    /** Overloading the operator != to check if 2 Protein objects are not equal **/
    bool operator!= (Protein &obj);

    /** Overloading the operator + to concatenate any two sequences of the same type **/
    Protein operator+ (Protein &obj);

    /** Overloading the operator >> to get the Protein info from the user **/
    friend istream& operator>>(istream& in, Protein &obj);

    /** Overloading the operator << to display the Protein info to the user **/
    friend ostream& operator<<(ostream& out, Protein &obj);

};


#endif // PROTEIN_H
