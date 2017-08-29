/** HackerRank sample coding challenge.
    1) Given an array and a value, create a function that returns a string "YES" or "NO" depending on if that value was in the array.
    2) Given a lower bound and upper bound, create a function that returns a vector of all the odd numbers between (inclusive) the lower and upper bound. 

    @author Aumit Leon
    @date August 28th, 2017 
**/


#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std; 

string findNumber(vector< int >, int);
vector< int > oddNumbers(int, int);

int main()
{
    //testing the findNu,ber function 
    static const int test[] = {1, 2, 3, 4, 5};
    vector<int> vec (test, test + sizeof(test) / sizeof(test[0]) );
    int m = 12345;
    cout << findNumber(vec, m) << endl;

    cout << endl; 

    //testing the oddNumbers functions
    for(int h = 0; h  < oddNumbers(0, 10).size(); h++)
    {
        cout << oddNumbers(0, 10)[h] << endl;
    }
}

string findNumber(vector < int > arr, int k) {
    bool found = false; 
    for(int i = 0; i <= arr.size(); i++)
    {
        if(arr[i] == k)
        {
            found = true;
            break;
        }
        else
        {
            found = false; 
        }
    }
    
    if(found == true)
        return "YES";
    else 
        return "NO";
}


vector < int > oddNumbers(int l, int r) {
    vector<int> answer;
    for (int x = l; x <= r; x++)
    {
        //if even
        if(x%2 == 0)
        {
            continue;
        }
        //if odd
        else
        {
            answer.push_back(x);
        }
    }
    return answer;
}
    