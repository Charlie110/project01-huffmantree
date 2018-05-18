#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char* argv[]){
	// get data from codewords file
	string file=argv[1];
	ifstream words;
	words.open(file);

	string code[128];
	for(int i=0; i<128; i++){
		code[i]="";
	}
	int k;
	string str;
	while(words>>k){
		words>>str;
		code[k]=str;
	}
	
	string result="";
	int count=0;
	char c;
	while((c=fgetc(stdin))!=EOF){
		int temp=c;
//		cout<<"this is: "<<c<<" and int form: "<< temp<<" /"<<endl;
		result+=code[temp];
		count++;
	}
//	cout<<"result before: "<< result<<endl;
	int needs=0;
//	cout<<"size before: "<<result.length()<<endl;
	if(result.length()%8==0)
		needs=0;
	else{
		needs = 8 - result.length()%8;}
//	cout<<"extra zeros: "<<needs<<endl;
	for(int i=0; i<needs; i++){
		result+="0";
	}
//	cout<<"result.size: "<<result.length()<<endl;
//	cout<<result<<endl;
	int length=result.length()/8;
	bitset<32> binary=bitset<32>(length);
	string temp=binary.to_string();
	bitset<8> first= bitset<8>(temp.substr(0,8));
	bitset<8> second = bitset<8>(temp.substr(8,8));
	bitset<8> third = bitset<8>(temp.substr(16,8));
	bitset<8> fourth = bitset<8>(temp.substr(24,8));
	
//	cout<<"binary: "<<binary<<" first: "<<first<<" second: "<<second<<" third: "<<third<<" fourth: "<<fourth<<endl;
	bitset<8> add = bitset<8>(needs);
	vector<bitset<8>> bits;
	bits.push_back(add);
	bits.push_back(first);
	bits.push_back(second);
	bits.push_back(third);
	bits.push_back(fourth);
	
		
	while(result.length()!=0){
		string str=result.substr(0,8);
	//	cout<<"while loop: "<<str<<endl;
		result.erase(0,8);
		bitset<8> tmp(str);
		bits.push_back(tmp);
	}


	//output
	for(int i=0; i<bits.size() ;i++){
		cout<<static_cast<char>(bits[i].to_ulong());
//		cout<<bits[i];
	}	
	
	return 0;


}
	
