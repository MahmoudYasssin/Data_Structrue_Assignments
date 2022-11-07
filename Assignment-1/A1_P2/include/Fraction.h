#ifndef FARCALC_H_H
#define FARCALC_H_H


#include<iostream>
using namespace std ;
class fraction
{
private :
    int numrator , duminator ;
public :
    fraction () ;
    fraction (int x, int y ) ;
    fraction (const fraction & obj) ;
    bool operator <= (fraction obj);
    bool operator >= (fraction obj);
    bool operator == (fraction obj);
    bool operator != (fraction obj);
    friend istream & operator >> (istream & in , fraction & obj);
    friend ostream & operator << (ostream & out , fraction  obj);
    fraction operator + (fraction  obj);
    fraction operator - (fraction  obj);
    fraction operator * (fraction  obj);
    fraction operator / (fraction  obj);
    int GCD (int x , int y );
    void simplify () ;


};


#endif // FARCALC_H_H
