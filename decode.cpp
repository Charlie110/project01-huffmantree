#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>
using namespace std;


int main(){
	ifstream file;
	string code[128];
	for(int i=0; i<128;i++){
		code[i]="";
	}
	
	file.open("codewords.txt");
	int next;
	string str;
	while(file>>next){
		file>>str;
		code[next]=str;
	}

	char first;
	first=fgetc(stdin);
	int extra_zeros = int(bitset<8>(first).to_ulong());
	int length=0;
	for(int i =0; i<4;i++){
		first=fgetc(stdin);
		length+= bitset<8>(first).to_ulong() * pow(256,(3-i));
	}
	//length=length/8;
	//cout<<"length："<<length*8;	
	//cout<<"extra zeros"<<extra_zeros;
	string leftover="";
	string subcode="";
	
	int count = 0;
	char byte;
	// a character has 8 bits
	while(count<=length){
		byte=fgetc(stdin);	
		//cout<<"number of times"<<count<<endl;
		count++;
		string nums="";
		nums=bitset<8>(byte).to_string();
		subcode="";
		if(count==length){
			nums=nums.substr(0,8-extra_zeros);
			nums=leftover+nums;
			string tm=nums;
			while(nums.length()!=0){
				
				for(int i=0; i<tm.length();i++){
					subcode+=tm[i];
					for(int j=0;j<128;j++){
						if(subcode==code[j]&&subcode!=""){
						//	cout<<"subcode: "<<subcode<<endl;
							cout<<static_cast<char>(j);
							nums.erase(0,subcode.length());
							if(nums.length()==0)
								return 0;
							subcode="";
							
						}	
					}	
				}	
		
			}	
		}
		else{
			nums=leftover+nums;
		//	cout<<"nums inside else: "<<nums<<endl;
			int size=nums.length();
			string tmp=nums;
			
			for(int i=0; i<size;i++){
				subcode+=nums[i];
				//cout<<"subcode: "<<subcode<<endl;
				for(int j=0; j<128; j++){
					if(subcode==code[j]&&subcode!=""){
					//	cout<<"matched subcode: "<<subcode<<endl;
						cout<<static_cast<char>(j);
						tmp.erase(0,subcode.length());
						leftover=tmp;
						subcode="";
						}					
				}
				
				
			}
			//cout<<"leftover"<<leftover<<" see \n";		
				
		}
		
	}
	
	return 0;
}
