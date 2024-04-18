#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int n;
	string word;
 	cout<<"how many word : ";
	cin>>n;
	cout<<"type a word : "<<endl;

	for(int i=1; i<=n; i++)
	{
    cin>>word;
		if(word.size()>=10){
			cout<<word[0]<<word.size()-2<<word[word.size()-1];
		}else{
			cout<<word;
		}
	cout<<endl;
	}
}
