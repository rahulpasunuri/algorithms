#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*
This is my recursive solution to the word break problem...
http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
*/


bool checkSplit(const string s, const map<string, bool> dict )
{

	if(strcmp(s.c_str(), "") == 0)
	{
		return true;
	}
	int len = s.length();
	
	for(int i=1; i<=len; i++)
	{
		string s1, s2;
		s1 = s.substr(0, i);
		
		if(dict.count(s1) > 0)
		{
			if(checkSplit(s.substr(i), dict))
			{
				return true;
			}	
		}
	}
	return false;
}

int main()
{
	//init the dictionary...
	char a[][100] = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
	
	map<string, bool> dict;
	
	int len = sizeof(a)/100;
	
	for(int i=0; i<len; i++)
	{
		dict[a[i]] = true;
	}
	
	char b[][100] = {"ilikesamsung", "iiiiiiii", "", "ilikelikeimangoiii", "samsungandmango", "samsungandmangok"};
	
	int len2 = sizeof(b)/100;
	for(int i=0; i<len2; i++)
	{
		cout<<b[i]<<" - ";
		if(checkSplit(b[i], dict))
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}	
	
	
	
	return 0;
}
