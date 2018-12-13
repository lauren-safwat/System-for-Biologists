#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include <iostream>
#include <fstream>
using namespace std ;


class DNA ;
class Protein ;
class CodonsTable;

enum RNA_Type {mRNA=1, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA :public Sequence
{
private:
    RNA_Type type;

public:
    /** Default constructor **/
    RNA();

    /** Parameterized constructor **/
    RNA(char * seq, RNA_Type atype, int length);

    /** Copy constructor **/
    RNA(RNA& rhs);

    /** Destructor **/
    ~RNA();

    /** Setters **/
    void setRNA_Type(RNA_Type Type);
    void setRNA_Type();

    /** Getters **/
    RNA_Type getRNA_Type();

    /** Function to convert the RNA sequence into protein sequence using the codonsTable object **/
    Protein& ConvertToProtein(CodonsTable table);

    /** Function to convert the RNA sequence back to DNA **/
    DNA ConvertToDNA();

    /** Function to load sequence from file **/
    void LoadSequenceFromFile(char* filename);

    /** Function to save sequence to file **/
    void SaveSequenceToFile(char* filename);

    /** Function to be overridden to print all the RNA information **/
    void Print();

    /** Overloading the assignment operator **/
    RNA& operator=(const RNA& obj);

    /** Overloading the operator == to check if 2 RNA objects are equal **/
    bool operator== (RNA &obj);

    /** Overloading the operator != to check if 2 RNA objects are not equal **/
    bool operator!= (RNA &obj);

    /** Overloading the operator + to concatenate any two sequences of the same type **/
    RNA operator+ (RNA &obj);

    /** Overloading the operator >> to get the RNA info from the user **/
    friend istream& operator>>(istream& in, RNA &obj);

    /** Overloading the operator << to display the DNA info to the user **/
    friend ostream& operator<<(ostream& out, RNA &obj);

};


#endif // RNA_H
