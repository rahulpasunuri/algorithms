#include<iostream>
using namespace std;

/*
More details on the look and say sequence can be found here..
http://en.wikipedia.org/wiki/Look-and-say_sequence
*/

int main()
{
	string temp = "1";
	
	for(int i=0; i<10; i++)
	{
		//lets print the first 10 numbersof the sequence only..
		string final;
		int len = temp.length();
		int count=0;
		char currChar;
		for(int i=0; i<len; i++)
		{
			if(count ==0)
			{
				currChar = temp[i];
				count++;				
			}			
			else if(temp[i] == currChar)
			{
				count++;
			}
			else
			{
				char charCount = count+48;
				final = final + charCount+currChar;				
				currChar = temp[i];
				count=1;
			}			
		}
		if(count!=0)
		{
			char charCount = count+48;
			final = final + charCount+currChar;	
		}
		cout<<final<<endl;
		temp = final.c_str();
		final = "";
	}
	
	return 0;
}
