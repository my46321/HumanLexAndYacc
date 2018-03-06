#include <iostream>
#include <string>
#include <fstream>
using namespace std;



bool isDigit(char c){
	if(c>='0' && c<='9'){
		return true;
	}
	return false;
}
bool isLetter(char c){
	if(c>='a' && c<='z'){
		return true;
	}
	else if(c>='A' && c<='Z'){
		return true;
	}else{
		return false;
	}
}
string result="";
void output(int state,string val){
	string token="";
	if(state==13)
	{
		token="(int,"+val+")";
		cout<<token<<endl;
		result+=(token+", ");
	}else if(state==16){
		token="(for,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==1 || state==2 || state==7 || state==8){
		token="("+val+","+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==3){
		token="(;,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==4){
		token="(=,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==5){
		token="(+,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==6){
		token="(<,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==17){
		token="(integer,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}else if(state==9){
		token="(variable,"+val+")";
		cout<<token<<endl;
			result+=(token+", ");
	}
}


void lexicalAnalyze(string txt){
	int state=0;
	string val="";
	int i=0;
	while(i<txt.length())
	{
	switch(state)
	{
	case 0:
		if(txt[i]=='('){
			state=1;
			val="(";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]==')'){
			state=2;
			val=")";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]==';'){
			state=3;
			val=";";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]=='='){
			state=4;
			val="=";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]=='+'){
			state=5;
			val="+";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]=='<'){
			state=6;
			val="<";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]=='{'){
			state=7;
			val="{";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(txt[i]=='}'){
			state=8;
			val="}";
			output(state,val);
			state=0;
			val="";
			i++;
		}
		else if(isDigit(txt[i])){
			state=17;
			val+=txt[i++];
		}
		else if(isLetter(txt[i])){
			if(txt[i]=='i'){
				state=11;
				val+="i";
				i++;
			}else if(txt[i]=='f'){
				state=14;
				val+="f";
				i++;
			}else{
				state=9;
				val+=txt[i++];
			}
		}
		else if(txt[i]==' '){
			i++;
		}
		else{
			cout<<"wrong input"<<endl;
			i++;
		}
		break;
	case 17:
		if(isDigit(txt[i]))
		{
			state=17;
			val+=txt[i++];
		}else{
			output(17,val);
			state=0;
			val="";
		}
		break;
	case 9:
		if(isDigit(txt[i]) || isLetter(txt[i])){
			state=9;
			val+=txt[i++];
		}else{
			output(9,val);
			state=0;
			val="";
		}
		break;
	case 11:
		if(txt[i]=='n'){
			state=12;
			val+='n';
			i++;
		}
		else{
			state=9;
		}
		break;
	case 12:
		if(txt[i]=='t'){
			state=13;
			val+='t';
			i++;
		}
		else{
			state=9;
		}
		break;
	case 13:
		if(!isDigit(txt[i]) && !isLetter(txt[i])){
			output(13,val);
			state=0;
			val="";
		}else{
			state=9;
		}
		break;
	case 14:
		if(txt[i]=='o'){
			state=15;
			val+='o';
			i++;
		}
		else{
			state=9;
		}
		break;
	case 15:
		if(txt[i]=='r'){
			state=16;
			val+='r';
			i++;
		}
		else{
			state=9;
		}
		break;
	case 16:
		if(!isDigit(txt[i]) && !isLetter(txt[i])){
			output(16,val);
			state=0;
			val="";
		}else{
			state=9;
		}
		break;
	}
	}
}

void main()
{
	ifstream inputFile("LexicalInput.txt");
	ofstream outputFile("SyntaxInput.txt");
	//string int_="int int1=2;for(;int1<5;){int1=int1+2;}";
	string int_=" ";
	if(!inputFile.is_open()){
		cout<<"未成功打开文件"<<endl;
	}
	while(getline(inputFile,int_)){	
	}
	int_+=" ";
	lexicalAnalyze(int_);
	outputFile<<result<<endl;
	system("pause");
	inputFile.close();
	outputFile.close();
}