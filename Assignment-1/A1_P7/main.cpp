/*
Mahmoud yassin mahmoud
20200506

Ahmed hassan ahmed foad
20200010

Omar AbdEl-Aziz El-Sayed
20200831

youssef Mohammed galal
20200664

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void BiasedSort (vector<string> &songs)
{
    int i=1;
    int k=0;
    string temp;
    for (auto it =songs.begin()+i; it<songs.end(); it++,i++)
    {
        temp = *it;
        int j;
        if (temp=="untitled")
        {
            songs.erase(songs.begin()+i,songs.begin()+(i+1));
            songs.emplace(songs.begin(),temp);
            k++;

        }
        else
        {
            for (j=i; j>k&&temp <songs[j-1]; j--)
            {
                songs[j]=songs[j-1];
            }
            songs[j]=temp;
        }


    }
}

int main()
{
    vector<string> Song_list= {"youssef","untitled","omar","mahmoud","ahmed","untitled","untitled"};
   // vector<string> Song_list(12);
  //  for (int i=0 ; i<12 ; i++)
   // {
 //       cin>>Song_list[i];
//    }
    BiasedSort(Song_list);
    cout <<endl;
    cout <<endl;
    cout <<endl;
    for (auto it1 =Song_list.begin(); it1<Song_list.end(); it1++)
        cout << *it1 <<endl;
}
