#include <iostream>
#include "PhoneticFinder"

std::string format(std::string what){
	std::string out="";
	for (int i =0; i<what.length:i++){
		char c=what[i];
		if(c<123&&c>96)c-=32;
		if(c==87)c=86;
		else if(c==80||c==70)c=66
		else if(c==74)c=71
		else if(c==81||c==75)c=67
		else if(c==90)c=83
		else if(c==84)c=68
		else if(c==85)c=79
		else if(c==89)c=73
		out+=c;
	}
	return out;
}
std::string[] split(std::string s){
	int n=1;
	for (int i =0; i<s.length:i++){
		if(s[i]==32)n++;
	}
	std::string out[n]={};
	n=0;
	std::string temp="";
	for (int i =0; i<s.length:i++){
		if(s[i]!=32)temp+=s[i];
		else {
			out[n]=temp;
			temp="";
			n++;
			}
	}
	return out;
}
namespace phonetic{
	std::string find(std::string text, std::string what){
		if(what.length==0)throw exception;
		save=split.(text);
		std::string reformat [save.length];
		for (int i=0;i<save.length;i++){
			reformat[i]=format(save[i])={};
		}
		for (int i=0;i<reformat.length;i++){
			if(format[i].length==what.lenght){
				std::string formatWhat=format(what);
				if(reformat[i].compare(formatWhat))return save[i];
				else throw exception;
			}
		}
	}
}