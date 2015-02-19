
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() 
{
	set<char> allNumbers;
	set<char> input;

	for(char i = '0' ; i <= '9'; i++)
		allNumbers.insert(i);
	
	string str;	
	getline(cin,str);
	

	for(int i = 0; i < str.length(); i++)
		input.insert(str[i]);

	set<char> result; 	
						
	for(set<char>::iterator it = allNumbers.begin(); it != allNumbers.end(); it++)
		if(!(input.count(*it) && allNumbers.count(*it)) )
			result.insert(*it);
	
	cout<<result.size()<<endl;
	
	set<char>::iterator eit = --result.end();

	for(set<char>::iterator it = result.begin(); it != result.end(); it++)
		if(it != eit)
			cout<<*it<<" ";
		else
			cout<<*it;

	cout<<endl;
	
	return 0;
}
