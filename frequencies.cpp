#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int arr[128];
	for(int i=0; i<128;i++){
		arr[i]=0;
	}
	char c;
	// if not end of file, we keep count and put into arr lsit
	while((c=fgetc(stdin))!=EOF){
		//cout<<c;
		//parse
		int j=c;
		arr[j]+=1;
	}
	//cout<<"1o: "<<arr[10]<<endl;
	// out put
	for(int i=0; i<128; i++){
		if(arr[i]!=0){
			cout<<i<<"\t"<<arr[i]<<endl;
		}
	}
	return 0;
}
