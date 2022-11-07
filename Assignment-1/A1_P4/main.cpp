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
#include <bits/stdc++.h>
#include <vector>
using namespace std;
set<string>Set_of_strings;
void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
    {
        Set_of_strings.insert(soFar); // Print the word
    }
    else // Still more chars
    // For each remaining char
    for (int i = 0; i < rest.length(); i++)
    {
        string next = soFar + rest[i]; // Glue next char
        string remaining = rest.substr(0, i)+ rest.substr(i+1);
        RecPermute(next, remaining);
    }
}
void  ListPermutations(string ST)
{
    RecPermute("", ST);
    for(auto i=Set_of_strings.begin();i!=Set_of_strings.end();i++)
    {
        cout<<*(i)<<'\n';
    }
}

int main()
{
   string S;
   cin>>S;
   ListPermutations(S);
}

