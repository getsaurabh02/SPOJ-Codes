#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
using namespace std;
 
void main()
{
  int number_of_testcases;
  scanf("%d",&number_of_testcases);
  
  string str1,str2,str3;
  while(number_of_testcases-- > 0)
    {
      // Reading the input.
      cin >> str1 >> str2 >> str3;
 
      vector< vector<long long> > first( str3.length(), vector<long long>(str1.length(),0));
      vector< vector<long long> > second( str3.length(), vector<long long>(str2.length(),0));
 
 
      for(int i = 0;i < str3.length() ;i++)
	{
	  
	  // character needed is str3[i]
	  if( i == 0)
	    {
	      for(int j = 0 ; j < str1.length() ; j++)
		{
		  if( str1[j] == str3[i])
		    {
		      first[i][j] = 1;
		    }
		}
 
	      for(int j = 0 ; j < str2.length() ; j++)
		{
		  if( str2[j] == str3[i])
		    {
		      second[i][j] = 1;
		    }
		}
	    }
	  else
	    {
	      char prev_char = str3[i-1];
	      
	      for(int j = 0; j < str1.length();j++)
		{
		  if( str1[j] == str3[i])
		    {
		      
		      // adding the prev characters count in the first string.
		      for(int k = 0;k < j;k++)
			{
			  
			  if( str1[k] == prev_char )
			    {
			      first[i][j] += first[i-1][k];
			    }
			}
 
		      // adding the prev characters count in the second string.
		      for(int k = 0;k < str2.length();k++)
			{
			  if( str2[k] == prev_char )
			    {
			      first[i][j] += second[i-1][k];
			    }
			}
		    }
		}
 
	      for(int j = 0; j < str2.length();j++)
		{
		  if( str2[j] == str3[i])
		    {
		      
		      // adding the prev characters count in the first string.
		      for(int k = 0;k < str1.length();k++)
			{
			  
			  if( str1[k] == prev_char )
			    {
			      second[i][j] += first[i-1][k];
			    }
			}
 
		      // adding the prev characters count in the second string.
		      for(int k = 0;k < j;k++)
			{
			  if( str2[k] == prev_char )
			    {
			      second[i][j] += second[i-1][k];
			    }
			}
		    }
		}
	    }
	}
 
      // Summing the last rows of the two matrices.
      int l = str3.length() - 1;
      long long solutions = 0;
 
      for(int i = 0;i < str1.length();i++)
	{
	  solutions = solutions + first[l][i];
	}
 
      for(int i = 0;i < str2.length();i++)
	{
	  solutions = solutions + second[l][i];
	}
	  
      printf("%lld\n",solutions);
      
    } // while
} // main