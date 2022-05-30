// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/

#include<bits/stdc++.h> //importing libraries

using namespace std;

string printSequence(string str[], string input){
    int n = input.length();
    string output = "";

    int p; 

    for(int i = 0; i<n; i++){
        if(input[i] == ' ') output += '0';

        else{
            p = input[i] - 'A';
            output += str[p];
        }
    }
    return output;
}

int main()
{
    string str[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666",
                    "7","77","777","7777","8","88","888","9","99","999","9999"};
    string input = "AADI JAIN";

    cout<<printSequence(str, input);
    
}
