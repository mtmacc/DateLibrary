#pragma once
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MyOwnStringLib
{
private:
	string _Value;
public:
	MyOwnStringLib();
	MyOwnStringLib(string value);
	void setString(string value);
	string getString();
	__declspec(property(get = getString, put = setString))string Value; // Fixed line
	static int CounterLetter(string str, char s);
	int CounterLetter(char s);
	static string ReverseWord(string str);
	string ReverseWord();
	static string toUpper(string str);
	string toUpper();
	static string toLower(string str);
	string toLower();
	static string trim(string str,string direction,char ch);
	string trim(string direction, char ch);
	static vector<string> split(string str, string delimiter);
	static bool isEmpty(string str);
	bool isEmpty();
	static bool equals(string str1,string str2);
	bool equals(string str2);
	static int findSubstring(string str,string sub);
	int findSubstring(string sub);
	static string ToLowwerString(string str);
	string ToLowwerString();
	static string VAsString(vector<string> names, string sep);
	static string ReplaceWordInStr(string word, string in, string out, bool matchCase);
	string ReplaceWordInStr(string in, string out, bool matchCase);
	static string ReverseStr(string str,string sep);
	string ReverseStr(string sep);
	static int WordsCounter(string str, char sep);
	int WordsCounter(char sep);
	static string UpperFirstLetterOfEachWord(string S1);
	string UpperFirstLetterOfEachWord();
	
};
