

#include <iostream>
#include <set>

using namespace std;


int main() 
{
	set<int> mySet;
	mySet.clear();

	int a,b,c,d,summ = 0;
	cin>>a>>b>>c>>d;
	if(a>b){
		swap(a,b);
	}
	if(c>d){
		swap(c,d);
	}
	for(int i = a; i <= b; i++){
		for(int j = c; j <= d;j++){		
			if(!mySet.count(i*j)){
				summ++;
				mySet.insert(i*j);
			} 
		}	
	}
	cout<<summ<<endl;

	return 0;
}