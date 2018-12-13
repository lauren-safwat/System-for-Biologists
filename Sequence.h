#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std ;

class Sequence
{
protected:
    char * seq ;
    int len ;

public:
    /** Default constructor **/
    Sequence();

    /** Parameterized constructor **/
    Sequence(int length);

    /** Copy constructor **/
    Sequence(Sequence& rhs);

    /** Destructor **/
    virtual ~Sequence();

    /** Setters **/
    void setLen(int length);
    void setSeq(char * sequence);
    void setSeq(int index, char value);

    /** Getters **/
    int getLen();
    char* getSeq();
    char getSeq(int index);

    /** pure virtual function that should be overridden because every type of sequence has its own details to be printed **/
    virtual void Print()= 0;

    /** friend function that will find the LCS (longest common subsequence) between 2 sequences of any type, according to polymorphism **/
    friend char* Align(Sequence * s1, Sequence * s2);

    /** Pure virtual function to load sequence from file that will be overridden for all the child classes **/
    virtual void LoadSequenceFromFile(char* filename)=0;

    /** Pure virtual function to save sequence to file that will be overridden for all the child classes **/
    virtual void SaveSequenceToFile(char* filename)=0;
};

#endif // SEQUENCE_H
