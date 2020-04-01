#include <iostream>
#include <bits/stdc++.h> 
#include "PhoneticFinder.hpp"
#include <stdexcept>
#include <string>

using namespace std;

string format(string what){
	string out="";
	for (int i =0; i<what.length();i++){
		char c=what[i];
		if(!((c<123&&c>96)||(c>64&&c<91)))throw invalid_argument("illigal input");
		if(c<123&&c>96)c-=32;
		if(c==87)c=86;
		else if(c==80||c==70)c=66;
		else if(c==74)c=71;
		else if(c==81||c==75)c=67;
		else if(c==90)c=83;
		else if(c==84)c=68;
		else if(c==85)c=79;
		else if(c==89)c=73;
		out+=c;
	}
	return out;
}
vector<string> split(string s){
	vector<string> out;
	string temp="";
	for (int i =0; i<s.length();i++){
		if(s[i]!=32)temp+=s[i];
		else {
			out.push_back(temp);
			temp="";
			}
	}
	out.push_back(temp);
	return out;
}
namespace phonetic{
	string find(string text, string what){
		if(what.length()==0)throw invalid_argument("no inputs");
		vector<string> save =split(text);
		vector<string> reformat;
		for (int i=0;i<save.size();i++){
			reformat.push_back(format(save[i]));
		}
		for (int i=0;i<reformat.size();i++){
			if(reformat[i].length()==what.length()){
				string formatWhat=format(what);
				if(reformat[i].compare(formatWhat)==0)return save[i];
			}
		}
		throw invalid_argument("didnt find");
		return "";
	}
}