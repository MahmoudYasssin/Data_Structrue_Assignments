#include "FractionCalculator.h"
#include <Fraction.h>

#include <iostream>
using namespace std ;
FractionCalculator ::FractionCalculator ()
{

}
 void FractionCalculator ::begincalulator()
{
    cout << "welcome  "<<endl ;
    fraction obj1 ,obj2 ;
    cout << " please enter the first fraction :"<<endl;
    cin>> obj1 ;
    cout << " please enter the second fraction :"<<endl;
    cin >> obj2 ;
    int response =1 ;
    while (response)
    {
        cout << " press 1 for adding "<<endl;
        cout << " press 2 for subtracting "<<endl;
        cout << " press 3 for multiplication  "<<endl;
        cout << " press 4 for division  "<<endl;
        cout << " press 5 for simplification  "<<endl;
        cout << " press 0 to exit  "<<endl;
        cin >> response ;
        if (response ==1)
        {
            fraction obj3(obj1 +obj2 );
            cout<< obj1 << " + " <<obj2 << "=" <<obj3 <<endl;

        }
        else if (response == 2)
        {
              fraction obj3(obj1 -obj2 );
               cout<< obj1 << " -" <<obj2 << "=" <<obj3 <<endl;

        }
        else if (response ==3)
        {
         fraction obj3(obj1 *obj2 );
         cout<< obj1 << " *" <<obj2 << "=" <<obj3 <<endl;
        }
        else if (response == 4 )
        {
            fraction obj3(obj1 /obj2 );
            cout<< obj1 << " /" <<obj2 << "=" <<obj3 <<endl;

        }

     /*   else if (response == 5 )
        {
            cout << obj1 << "="<< obj1.simplify () <<endl;
            cout << obj2<< "="<<obj2.simplify()<<endl ;
        }*/
        else if (response == 0)
        {
            cout << " thank you ";
            break;
        }



    }

}
