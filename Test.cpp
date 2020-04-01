#include "doctest.h"
#include "PhoneticFinder.hpp"
#include <iostream>
#include <string>

TEST_CASE("valid text"){
CHECK_THROWS(phonetic::find("test","123"));
CHECK_THROWS(phonetic::find("123","123"));
CHECK_THROWS(phonetic::find("123","test"));
CHECK_THROWS(phonetic::find("test",""));
CHECK_THROWS(phonetic::find("test","  "));
CHECK_THROWS(phonetic::find("test","  "));
CHECK_THROWS(phonetic::find("    ","test"));
CHECK_THROWS(phonetic::find("    ",""));
CHECK_THROWS(phonetic::find("    ","  "));
CHECK_THROWS(phonetic::find("123  456","  "));
}
TEST_CASE("same word length"){
CHECK(phonetic::find("test","test").compare("test")==0);
CHECK_THROWS(phonetic::find("test",""));
CHECK(phonetic::find("reallyLongWord","reallyLongWord").compare("reallyLongWord")==0);
CHECK(phonetic::find("a","a").compare("a")==0);
CHECK(phonetic::find("a b c d e","d").compare("d")==0);
CHECK_THROWS(phonetic::find("test","testt"));
CHECK_THROWS(phonetic::find("testt","test"));
CHECK(phonetic::find("test testt","test").compare("test")==0);
CHECK(phonetic::find("test testt","testt").compare("testt")==0);
CHECK_THROWS(phonetic::find("te st","test"));
}
TEST_CASE("letter change"){
CHECK(phonetic::find("test","dest").compare("test")==0);
CHECK(phonetic::find("test","desd").compare("test")==0);
CHECK(phonetic::find("test","dezd").compare("test")==0);
CHECK(phonetic::find("dest","test").compare("dest")==0);
CHECK(phonetic::find("desd","test").compare("desd")==0);
CHECK(phonetic::find("dezd","test").compare("dezd")==0);
CHECK(phonetic::find("test testt","dezd").compare("test")==0);
CHECK(phonetic::find("test testt","dezdd").compare("testt")==0);

}
TEST_CASE("capital change"){
CHECK(phonetic::find("test","Test").compare("test")==0);
CHECK(phonetic::find("test","TEst").compare("test")==0);
CHECK(phonetic::find("test","TESt").compare("test")==0);
CHECK(phonetic::find("test","TEST").compare("test")==0);
CHECK(phonetic::find("test testt","TEST").compare("test")==0);
CHECK(phonetic::find("test testt","TESTT").compare("testt")==0);
CHECK_THROWS(phonetic::find("test","TESTT"));
CHECK(phonetic::find("TEST","test").compare("TEST")==0);
}
TEST_CASE("capital and letter change"){
CHECK(phonetic::find("test","TEsd").compare("test")==0);
CHECK(phonetic::find("test","DEst").compare("test")==0);
CHECK(phonetic::find("test","DEZD").compare("test")==0);
CHECK(phonetic::find("test testt","DEZD").compare("test")==0);
CHECK(phonetic::find("test testt","DEZDD").compare("testt")==0);
CHECK(phonetic::find("DEZD","test").compare("DEZD")==0);

}
TEST_CASE("multiple of the same word/double meaning"){
CHECK(phonetic::find("test test","test").compare("test")==0);
CHECK(phonetic::find("test dezd","test").compare("test")==0);
CHECK(phonetic::find("test dezd","dezd").compare("dezd")!=0);
CHECK(phonetic::find("test dezd","dezd").compare("test")==0);
CHECK(phonetic::find("test dezd","test").compare("dezd")!=0);

}

TEST_CASE("padding"){
for(int i=0;i<=25;i++){
char c=i+65;
std::string sc="";
sc=sc+c;
char d=i+97;
std::string sd="";
sd=sd+d;
CHECK(phonetic::find(sc,sc).compare(sc)==0);
CHECK(phonetic::find(sc+sc,sc+sc).compare(sc+sc)==0);
CHECK(phonetic::find(sd,sd).compare(sd)==0);
CHECK(phonetic::find(sd+sd,sd+sd).compare(sd+sd)==0);
}
}