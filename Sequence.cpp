#include "Sequence.h"
#include <iostream>

Sequence::Sequence(){}

Sequence::Sequence(int length)
{
    seq = new char [length] ;
    len = length ;
}


Sequence :: Sequence(Sequence& rhs)
{
    len = rhs.len;
    seq = new char [len];
    for(int i=0; i<len; i++)
        seq[i] = rhs.seq[i];
}


void Sequence::setLen(int length)
{
    len = length;
}


void Sequence::setSeq(char * sequence)
{
    seq = new char[len];
    for(int i=0; i<len; i++)
        seq[i] = sequence[i];
}


void Sequence::setSeq(int index, char value)
{
    seq[index] = value;
}


int Sequence::getLen()
{
    return len;
}


char* Sequence::getSeq()
{
    return seq;
}


char Sequence::getSeq(int index)
{
    return seq[index];
}


Sequence::~Sequence()
{
    delete seq;
}
