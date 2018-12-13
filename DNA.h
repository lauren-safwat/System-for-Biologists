#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include "RNA.h"
#include <iostream>
#include <cstring>

using namespace std ;

class RNA;

enum DNA_Type {promoter=1, motif, tail, noncoding};

class DNA : public Sequence
{
private:
    DNA_Type type;
    DNA*  complementary_strand  ;
    int startIndex;
    int endIndex;

public:

    /** Default constructor **/
    DNA();

    /** Parameterized constructor **/
    DNA(char * seq,DNA_Type atype, int length);

    /** Copy constructor **/
    DNA(DNA& rhs);

    /** Destructor **/
    ~DNA();

    /** Setters **/
    void setDNA_Type(DNA_Type Type);
    void setDNA_Type();

    /** Getters **/
    DNA_Type getDNA_Type();
    DNA* getComplementaryStrand();

    /** Function to convert the DNA sequence to RNA sequence **/
    /** It starts by building the complementary_strand of the current DNA sequence (starting from the startIndex to the endIndex) **/
    /** Then, it builds the RNA corresponding to that complementary_strand. **/
    RNA ConvertToRNA(int Start, int End);

    /** Function to build the second strand/pair of DNA sequence **/
    /** To build a complementary_strand (starting from the startIndex to the endIndex), convert each A to T, each T to A, each C to G, and
        each G to C. Then reverse the resulting sequence. **/
    void BuildComplementaryStrand();

    /** Function to load sequence from file **/
    void LoadSequenceFromFile(char* filename);

    /** Function to save sequence to file **/
    void SaveSequenceToFile(char* filename);

    /** Function printing DNA sequence information to user **/
    void Print();

    /** Overloading the assignment operator **/
    DNA& operator=(const DNA& obj);

    /** Overloading the operator == to check if 2 DNA objects are equal **/
    bool operator== (DNA &obj);

    /** Overloading the operator != to check if 2 DNA objects are not equal **/
    bool operator!= (DNA &obj);

    /** Overloading the operator + to concatenate any two sequences of the same type **/
    DNA operator+ (DNA &obj);

    /** Overloading the operator >> to get the DNA info from the user **/
    friend istream& operator>>(istream& in, DNA &obj);

    /** Overloading the operator << to display the DNA info to the user **/
    friend ostream& operator<<(ostream& out, DNA &obj);
};


#endif // DNA_H
