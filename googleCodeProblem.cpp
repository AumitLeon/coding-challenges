/* Google technical interview prep -- given 2 strings, one of which has an extra character, output the extra character
    @author Aumit Leon
    @Date August 28th, 2017
    Compile with: g++ googleCodeProblem.cpp -o google.exe -std=gnu++11

    Time complexity: O(n) performance. 

    Space complexity: The 2 given strings, and 2 maps. 

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std; 

int main()
{
    map<char, int> ourDict;     //bad string
    map<char, int> goodDict;    //good string

    //strings
    // inputString is the string with the extra char
    // good_string is the string with one less char
    string inputString = "acdXfaskjf*dhF&&DGsds&g$2";
    string good_string = "acdXf*askjfdhFDG&sdsg$2";



    //Bad string
    for (int i = 0; i <= inputString.length()-1; i++)
    {
        if(ourDict.find(inputString[i]) == ourDict.end())
           // ourDict[inputString[i]] = ourDict[inputString[i]]++;
           ourDict[inputString[i]] = 1;
        else 
        {
            //ourDict[inputString[i]] = 1;
            //cout << "lol" << ourDict[inputString[i]] << endl;
            int temp_bad = ourDict[inputString[i]] + 1;
            ourDict[inputString[i]] = temp_bad;
           // cout << "lol: " << temp << endl;
        }
    }

    //Good string
    for(int x = 0; x <= good_string.length()-1; x++)
    {
        if(goodDict.find(good_string[x]) == goodDict.end())
            goodDict[good_string[x]] = 1;
        else
        {
            int temp_good = goodDict[good_string[x]] + 1;
            goodDict[good_string[x]] = temp_good;
        }
        
    }

    //Debuging
   /* cout << ourDict['f'] << endl;
    cout << ourDict.size() << endl;
    cout << goodDict.size() << endl;*/

    /*for (std::map<char,int>::iterator it=ourDict.begin(); it!=ourDict.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << '\n';
    }*/

    //Was the extra character found?
    bool wasFound = false;

    //What is the character? 
    char foundVal;

    //if(ourDict.size() >= goodDict.size())
    {
        for (std::map<char,int>::iterator it=ourDict.begin(); it!=ourDict.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << '\n';
            char temp_char = it->first;
            //cout << temp_char << endl; 

            //If if an element in the bad string doens't exist in the good string, that is our extra value!
            if(goodDict.find(it->first) == goodDict.end())
            {
                foundVal = it->first;
                wasFound = true;
                break;
            }

            //If the element does exist in the good string, but the frequency doesn't match, then that is the extra character!
            else
            {
                if(goodDict[it->first] != it->second)
                {
                    cout << it->first << " ===> " << it->second << endl; 
                    foundVal = it->first;
                    wasFound = true;
                    break;
                }
            }
                
        }
    }

    cout << "The extra character is: " << foundVal << endl;






/*
    for(map<char, int>::value_type& x : ourDict)
    {
        cout << x.first << x.second << endl; 
    }*/


}