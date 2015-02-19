#include "stdafx.h"






#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
typedef unsigned long long ULONG;

bool youCan ( ULONG n, ULONG s,ULONG k){
	ULONG summa = 0;

	if(s <= k && k != 1)
		return false;

	if(!s || !n || !k)
		return false;

	for(ULONG i = 1; i <= n; i++){
		summa += i;
		if(i == k && summa > s)
			return false;	
	}

	summa = 0;
	for(ULONG i = n,j = 0; j < k; i--,j++){
		summa += i;
	}

	return summa >= s;
}

template<typename T>
void fiil_up( T & out ,ULONG n, ULONG s, ULONG k){	
		ULONG summ = 1;
		ULONG number = 1;
		ULONG prevN = n;
		ULONG first = 1;
		string str(n,'0');
		vector<ULONG> vect;
		vect.reserve(1);
		vect.resize(1);
		bool needErase = true;

		if(k == 1){
			str[s-1] = '1';
			out<<str<<endl;
			return;
		}

		while(summ != s && number != k){
			vect[0] = first;

			for(ULONG last = prevN; last != first; last--){
				if(summ + last <= s && number <= k){
					summ += last; 
					++number;
					vect.push_back(last);
				}

				if(summ == s && number == k) break;
			}

			needErase = true;

			if(prevN == first){
				first++;
				prevN = n + 1;
				vect.clear();
				vect.push_back(first);
				needErase = false;
			}

			if(summ != s || number != k){
				prevN--;				
				number = 1;
				summ = first;
				if(!vect.empty() && needErase)
					vect.erase(vect.end()-1,vect.end());
			}
		}

		
		for(int i  = 0; i < vect.size(); i++){
			str[vect[i] - 1 ] = '1';
			cout<<vect[i]<<endl;
		}
		
		out<<str<<endl;
}

int main() 
{
	
	ULONG t;
	cin>>t;

	stringstream out;

	for(ULONG i = 0; i < t; i++){

		vector<ULONG> vect;
		vect.reserve(3);
		for(int  j = 0; j < 3; j++){
			ULONG x;
			cin>>x;
			vect.push_back(x);
		}

		//read done
		if(!youCan(vect[0],vect[1],vect[2])){
			out<<"NO"<<endl;
			continue;
		} else {
			out<<"YES"<<endl;
			fiil_up(out,vect[0],vect[1],vect[2]);
		}

	}

	string result;

	do{
		out>>result;
		if(out.eof()) break;
		cout<<result<<endl;	
	}while(1);

	return 0;
}