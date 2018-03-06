#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

string output(queue <int>order){
	string result=" ";
	while(!order.empty())
	{
		int temp=order.front();
		if(temp==1){
		   result+="S->D;E\n";
		}else if(temp==2){
			result+="E->for(T){E}\n";
		}else if(temp==3){
		 result+="E->X\n";
		}else if(temp==4){
		 result+="T->;X;\n";
		}else if(temp==5){
		 result+="D->int X\n";
		}else if(temp==6){
		 result+="X->variable X'\n";
		}else if(temp==7){
		 result+="X'->=X\"\n";
		}else if(temp==8){
		 result+="X'-><X\"\n";
		}else if(temp==9){
		 result+="X'->+X\"\n";
		}else if(temp==10){
		 result+="X\"->integer\n";
		}else if(temp==11){
		 result+="X\"->X";
		}
		order.pop();
	}
	return result;
}
string LL1(stack <string>s1,stack <string>s2,vector <vector<string>>cfgV)
{
	queue <int>order;
	vector<string> temp;
	while(s1.top()!="$"){
	if(s1.top()==s2.top()){
		s1.pop();
		s2.pop();
		continue;
	}
	else if(s1.top()=="variable"){
		if(s2.top()=="X\""){
			s2.pop();
			temp=cfgV[10];
			cout<<11<<endl;
			order.push(11);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}else if(s2.top()=="X"){
			s2.pop();
			temp=cfgV[5];
			cout<<6<<endl;
			order.push(6);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}else if(s2.top()=="E"){
			s2.pop();
			temp=cfgV[2];
			cout<<3<<endl;
			order.push(3);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="integer"){
		if(s2.top()=="X\""){
			s2.pop();
			temp=cfgV[9];
			cout<<10<<endl;
			order.push(10);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="for"){
		if(s2.top()=="E"){
			s2.pop();
			temp=cfgV[1];
			cout<<2<<endl;
			order.push(2);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="int"){
		if(s2.top()=="D"){
			s2.pop();
			temp=cfgV[4];
			cout<<5<<endl;
			order.push(5);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}else if(s2.top()=="S"){
			s2.pop();
			temp=cfgV[0];
			cout<<1<<endl;
			order.push(1);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="+"){
		if(s2.top()=="X'"){
			s2.pop();
			temp=cfgV[8];
			cout<<9<<endl;
			order.push(9);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()==";"){
		if(s2.top()=="T"){
			s2.pop();
			temp=cfgV[3];
			cout<<4<<endl;
			order.push(4);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="<"){
		if(s2.top()=="X'"){
			s2.pop();
			temp=cfgV[7];
			cout<<8<<endl;
			order.push(8);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else if(s1.top()=="="){
		if(s2.top()=="X'"){
			s2.pop();
			temp=cfgV[6];
			cout<<7<<endl;
			order.push(7);
			for(int i=temp.size()-1;i>=0;i--){
				s2.push(temp[i]);
			}
			temp.clear();
			continue;
		}
	}
	else{
		cout<<"don't match this grammar"<<endl;
		return "don't match this grammar";
		break;
	}
	}
	if(s2.top()=="$"){
		cout<<"match"<<endl;
	}
	return output(order);
}
void main()
{
	ifstream inputFile("SyntaxInput.txt");
	ofstream outputFile("ResultOutput.txt");
	string stemp=" ";
	string s=" ";
	if(!inputFile.is_open()){
		cout<<"未成功打开文件"<<endl;
	}
	while(getline(inputFile,stemp)){	
		s+=stemp;
	}
	s+=" ";
	stack <string>s1;
	stack <string>s2;
	s1.push("$");
	s2.push("$");
	s2.push("S");
	int i=0;
	vector <string>v;
	vector <vector<string>>cfgV;
	vector <string>cfgTemp;
	cfgTemp.push_back("D");
	cfgTemp.push_back(";");
	cfgTemp.push_back("E");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("for");
	cfgTemp.push_back("(");
	cfgTemp.push_back("T");
	cfgTemp.push_back(")");
	cfgTemp.push_back("{");
	cfgTemp.push_back("E");
	cfgTemp.push_back("}");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("X");
	cfgTemp.push_back(";");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back(";");
	cfgTemp.push_back("X");
	cfgTemp.push_back(";");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("int");
	cfgTemp.push_back("X");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("variable");
	cfgTemp.push_back("X'");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("=");
	cfgTemp.push_back("X\"");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("<");
	cfgTemp.push_back("X\"");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("+");
	cfgTemp.push_back("X\"");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("integer");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	cfgTemp.push_back("X");
	cfgV.push_back(cfgTemp);
	cfgTemp.clear();
	string temp;
	while(i<s.length()){
		if(i==0)
		{	
			if(s[i]=='('){
				temp="";
				while(s[++i]!=','){
					temp+=s[i];
				}
				v.push_back(temp);
			}else{
				i++;
			}
		}else{
			if(s[i]=='(' && s[i-1]!='(' && s[i-1]!=','){
				temp="";
				while(s[++i]!=','){
					temp+=s[i];
				}
				v.push_back(temp);
			}
			else{
				i++;
			}
		}
	}
	i=v.size()-1;
	for(;i>=0;i--){
		s1.push(v[i]);
	}
	//按照表扫描栈
	outputFile<<LL1(s1,s2,cfgV);

	system("pause");
	inputFile.close();
	outputFile.close();
}