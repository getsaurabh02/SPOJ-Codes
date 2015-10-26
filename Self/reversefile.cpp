#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
void print_reversed_string(string my_string);
int main()
{
    /*const string my_string("To be or not to be");*/               
    fstream my_string;
    my_string.open("abcd.txt", fstream::in);   
    print_reversed_string(my_string);
    my_string.close();
}
void print_reversed_string(string my_string)
{
    cout << "Original text:" << "  ";   
    string s(my_string.begin(), my_string.end());
    string::iterator pos;   
    for (pos = s.begin(); pos != s.end(); ++pos)
        {
        cout << *pos;
        }
    cout << endl;
    reverse (s.begin(), s.end());
    cout << "Reversed text: " << s << endl;
}
