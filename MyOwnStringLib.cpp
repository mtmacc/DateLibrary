#include "MyOwnStringLib.h"

MyOwnStringLib::MyOwnStringLib()
{
}
MyOwnStringLib::MyOwnStringLib(string value):_Value(value)
{
}
string MyOwnStringLib::getString()
{
	return _Value;
}
void MyOwnStringLib::setString(string value)
{
	_Value = value;
}
int MyOwnStringLib::CounterLetter(string str, char s)
{
    int result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (s == str[i]) {
            result++;
        }
    }
    return result;
}
int MyOwnStringLib::CounterLetter(char s)
{
    return CounterLetter(_Value, s);
}
string MyOwnStringLib::ReverseWord(string str)
{
    string result;
    for (int i = str.length()-1; i>=0;i--)
    {
        result += str.at(i);
    }
    return result;
}
string MyOwnStringLib::ReverseWord()
{
    return ReverseWord(_Value);
}
string MyOwnStringLib::toUpper(string str)
{
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            result += char(str[i] - 32);
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}
string MyOwnStringLib::toUpper()
{
    return toUpper(_Value);
}
string MyOwnStringLib::toLower(string str)
{
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            result += char(str[i] + 32);
        }
        else
        {
            result += str[i];
        }
    }
    return result;
}
string MyOwnStringLib::toLower()
{
    return toLower(_Value);
}
string MyOwnStringLib::trim(string str,string direction,char ch = ' ')
{
    int fristCounter = 0;
    int lastCounter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            fristCounter++;
        }
        else
        {
            break;
        }
    }
    for (int i = str.length()-1; i >=0; i--)
    {
        if (str[i] == ch)
        {
            lastCounter++;
        }
        else
        {
            break;
        }
    }
    if (direction == "right")
    {
        return str.substr(fristCounter, str.length());
        //for (int i = fristCounter; i < str.length(); i++)
        //{
        //    result += str[i];
        //}
    }
    else if(direction == "left")
    {
        return str.substr(0, str.length() - lastCounter);
    }
    else if (direction == "all")
    {   
        return str.substr(fristCounter, str.length() - lastCounter - fristCounter);
    }
    else
    {
        return str;
    }

}
string MyOwnStringLib::trim(string direction, char ch = ' ')
{
    return trim(_Value, direction, ch);
}
vector<string> MyOwnStringLib::split(string str, string delimiter)
{
    short pos = 0;
    string result = "";
    vector <string> vResult;
    while (str.find(delimiter) != std::string::npos)
    {
        pos = str.find(delimiter);
        result = str.substr(0, pos);
        if (!result.empty())
        {
            vResult.push_back(result);
        }
        str.erase(0, pos+delimiter.length());
    }
    if (!str.empty())
    {
        vResult.push_back(str);
    }
    return vResult;
}
bool MyOwnStringLib::isEmpty(string str)
{
    return str.length() == 0;
}
bool MyOwnStringLib::isEmpty()
{
    return isEmpty(_Value);
}
bool MyOwnStringLib::equals(string str1, string str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if(str1[i]!= str2[i]) return false;
        }
    }

    return true;
}
bool MyOwnStringLib::equals(string str2)
{
    return equals(_Value, str2);
}
int MyOwnStringLib::findSubstring(string str, string sub)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool found = true;
        if (str[i] == sub[0])
        {
            for (int l = 0; l < sub.length(); l++)
            {
                if (str[l + i] != sub[l]) {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }

    }
    return -1;
}
int MyOwnStringLib::findSubstring(string sub)
{
    return findSubstring(_Value, sub);
}
string MyOwnStringLib::ToLowwerString(string str)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        result += tolower(str[i]);
    }
    return result;
}
string MyOwnStringLib::ToLowwerString() 
{
    return ToLowwerString(_Value);
}
string MyOwnStringLib::VAsString(vector<string> names, string sep)
{
    string result = "";
    for (int i = 0; i < names.size(); i++)
    {
        result += names.at(i);
        if (i != names.size() - 1)
        {
            result += sep;
        }
    }
    return result;
}
string MyOwnStringLib::ReplaceWordInStr(string word, string in, string out, bool matchCase)
{
    vector <string> splitWord = split(word, " ");
    string result;
    for (string& str : splitWord)
    {
        if (matchCase)
        {
            if (str == out)
            {
                str = in;
            }
        }
        else
        {
            if (ToLowwerString(str) == ToLowwerString(out))
            {
                str = in;
            }
        }
    }
    result = VAsString(splitWord, " ");
    return result;
}
string MyOwnStringLib::ReplaceWordInStr(string in, string out, bool matchCase)
{
    return ReplaceWordInStr(_Value, in, out, matchCase);
}
string MyOwnStringLib::ReverseStr(string str,string sep)
{
    vector<string> splitStr = split(str, " ");
    reverse(splitStr.begin(), splitStr.end());
    string result;
    for (int i = 0; i < splitStr.size(); i++)
    {
        result += splitStr[i];
        if (i != splitStr.size() - 1) {
            result += sep;
        }
    }
    return result;

    //vector<string> vString;
    //string S2 = "";

    //vString = split(str, " ");

    //// declare iterator
    //vector<string>::iterator iter = vString.end();

    //while (iter != vString.begin())
    //{

    //    --iter;

    //    S2 += *iter + " ";

    //}

    //S2 = S2.substr(0, S2.length() - 1); //remove last space.

    //return S2;
}
string MyOwnStringLib::ReverseStr(string sep)
{
    return ReverseStr(_Value, sep);
}
int MyOwnStringLib::WordsCounter(string str, char sep)
{     
    string result = "";
    int counter = 0;
    for (short i = 0; i < str.length(); i++)
    {
        if (str[i] != sep)
        {
            result += str[i];
        }
        else if (str[i] == sep && !result.empty())
        {
            counter++;
            result = "";
        }
    }
    if (!result.empty())
    {
        counter++;
    }      
    return counter;
}
int MyOwnStringLib::WordsCounter(char sep)
{
    return WordsCounter(_Value, sep);
}
string MyOwnStringLib::UpperFirstLetterOfEachWord(string S1)
{
    bool isFristLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (!isspace(S1[i]) && isFristLetter)
        {
            S1[i] = toupper(S1[i]);
        }
        isFristLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}
string MyOwnStringLib::UpperFirstLetterOfEachWord()
{
    return UpperFirstLetterOfEachWord(_Value);
}
