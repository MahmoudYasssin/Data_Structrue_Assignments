/*
Mahmoud yassin mahmoud
20200506

Ahmed hassan ahmed foad
20200010

Omar AbdEl-Aziz El-Sayed
20200831

youssef M.galal
20200664

*/

#include "Fraction.h"
#include <iostream>
using namespace std;
fraction ::fraction ()
{

}
fraction ::fraction (int x , int y )
{
    numrator = x ;
    duminator = y ;
}
fraction ::fraction (const fraction & obj )
{
    numrator = obj .numrator ;
    duminator = obj.duminator ;
}
int fraction :: GCD (int x, int y)
{
    if (y == 0)
        return x ;
    else
        return GCD (y , x%y) ;
}
void fraction ::simplify ()
{
     int a=GCD(numrator,duminator);
    numrator/=a;
    duminator/=a;

}
bool fraction :: operator == (fraction obj)
{

    if (numrator==obj.numrator&&duminator==obj.duminator)
        return 1;
    else
        return 0;


}
bool fraction :: operator != (fraction obj)
{

    if (numrator==obj.numrator&&duminator==obj.duminator)
        return 0;
    else
        return 1;


}
bool fraction :: operator >= (fraction obj)
{

    if(( float )numrator/duminator>=( float )obj.numrator/obj.duminator)
        return 1 ;
    else
        return 0;
}
bool fraction :: operator <= (fraction obj)
{

    if(( float )numrator/duminator<=( float )obj.numrator/obj.duminator)
        return 1 ;
    else
        return 0;
}
istream & operator >> (istream & in , fraction & obj)
{
    cout<<"enter nominator : ";
    in>>obj.numrator;
    cout<<"enter dominator : ";
    in>>obj.duminator;
    obj.simplify();
    return in;
}
ostream & operator << (ostream & out , fraction  obj)
{
   if (obj.duminator==0)
        out<<"error ( undefined ) "<<endl;
   else if (obj.numrator==0)
        out<<0<<endl;
    else if (obj.duminator==obj.numrator)
        out<<1<<endl;
    else
        out<<obj.numrator<<'/'<<obj.duminator;
    return out;
}
fraction fraction ::operator+(fraction  obj)
{
    fraction fra ;
    fra.duminator= duminator*obj.duminator;
    fra.numrator = numrator*obj.duminator+obj.numrator*duminator;
    fra.simplify();
    return fra;
}
fraction fraction ::operator-(fraction  obj)
{
    fraction fra;
    fra.duminator = duminator*obj.duminator;
    fra.numrator = numrator*obj.duminator-obj.numrator*duminator;
    fra.simplify();
    return fra;
}

fraction fraction ::operator*(fraction  obj)
{
    fraction fra;
    fra.duminator = duminator*obj.duminator;
    fra.numrator = numrator*obj.numrator;
    fra.simplify();
    return fra;
}
fraction fraction ::operator/(fraction  obj)
{
    fraction fra;
    fra.duminator = duminator*obj.numrator;
    fra.numrator = numrator*obj.duminator;
    fra.simplify();
    return fra;
}
