#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    char arr[] = "Hey-Adi";

    char * tok = strtok(arr,"-");

    while(tok!=NULL)
    {
        cout << tok << " ";
        tok = strtok(NULL,"-");
    } 


}