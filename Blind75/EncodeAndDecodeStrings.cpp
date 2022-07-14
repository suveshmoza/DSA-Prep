#include<iostream>
#include<vector>
using namespace std;

string encode(vector<string>str){
    string encodedString="";
    for(int i=0;i<str.size();i++){
        encodedString=encodedString+to_string(str[i].size())+"#"+str[i];
    }
    return encodedString;
}

int getHashIndex(char X,int start,string str){
    int index=-1;
    for(int i=start;i<str.length();i++){
        if(str[i]==X){
            index=i;
            break;
        }
    }
    return index;
}

void printArr(vector<string>res){
    for(auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;
}

void decode(string str){
    vector<string>decodedString;
    int i=0,n=str.size();
    while(i<n){
        int hashIndex=getHashIndex('#',i,str);
        int len=stoi(str.substr(i,hashIndex-i));
        i=hashIndex+1;
        decodedString.push_back(str.substr(i,len));
        i+=len;
    }
    printArr(decodedString);
}


int main(){
    vector<string>v={"ironman", "superman", "batman", "captainamerica"};
    string encodedString=encode(v);
    cout<<"Encoded String : "<<encodedString<<endl;
    decode(encodedString);
}