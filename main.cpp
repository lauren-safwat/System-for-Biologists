#include <iostream>
#include <cstring>
#include <fstream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;

int main()
{
    /** DNA d1, d2, d3;
    cin>>d1;
    cout<<d1;
    cin>>d2;
    cout<<d2;
    d3 = d2;
    d3.Print();
    DNA d4(d3);
    d4.Print();
    DNA d5;
    d5 = (d1 + d2);
    d5.Print();
    cout << endl << endl;
    (d5.ConvertToRNA(2,5)).Print();
    cout << endl << endl;
    cout << endl << endl;
    RNA r2;
    r2 = d5.ConvertToRNA(-1,-1);
    r2.Print();
    cout << endl << endl; **/

    /** CodonsTable ct;
    RNA r1;
    cin >> r1;
    cout << r1 << endl;
    DNA d1;
    d1 = r1.ConvertToDNA();
    d1.Print();
    cout << endl << endl;
    /// (r1.ConvertToDNA()).Print();
    cout << endl << endl; **/

    CodonsTable ct;
    RNA r1;
    cin >> r1;
    r1.Print();
    cout << endl << endl;
    r1.ConvertToProtein(ct);
    cout << endl << endl;
    Protein p1(r1.ConvertToProtein(ct));
    p1.Print();
    cout << endl << endl;
    Protein p2;
    p2 = r1.ConvertToProtein(ct);
    p2.Print();


    return 0;
}





