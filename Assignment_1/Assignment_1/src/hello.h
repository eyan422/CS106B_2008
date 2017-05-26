// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stat
{
    float min;
    float max;
    float average;
    float sum;
};

stat GetScoresAndStat(string filename)
{
    stat result;
    int count = 0;
    string str;
    result.min = 0;
    result.max = 0;
    result.sum=0;
    result.average = 0;
    int number;

    ifstream infile;
    infile.open(filename.data());   //将文件流对象与文件连接起来
    //assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    while(getline(infile,str))
    {
        count++;
        cout << str << endl;
        number = atoi( str.c_str() );

        if (!isdigit(number))
        {
            continue;
        }

        result.sum += number;
        result.average = result.sum/count;

        if(count == 1)
        {
            result.max = number;
            result.min = number;
        }
        else
        {
            if (number > result.max)
            {
                result.max = number;
            }
            else if (number < result.min)
            {
                result.min = number;
            }
        }

    }
    infile.close();             //关闭文件输入流

    return result;
}

string CensorString1(string text, string remove)
{
    string result;
    cout << "CensorString1" << endl;
    cout << "text is: " << text << endl;
    cout << "remove is: " << remove << endl;

    cout << "text length is: " << text.length() << endl;

    for(unsigned int i = 0; i < (unsigned)text.length(); i++)
    {
        cout << "text[i] is : " << text.substr(i,1) << endl;
        //if ( !stringContains(remove, text.substr(i,1)) )
        if( remove.find(text[i]) == string::npos )
        {
            result.append(text.substr(i,1));
        }
        else
        {
            continue;
        }
    }

    cout << "result is :" << result << endl;

    return result;
}

void CensorString2(string &text, string remove)
{
    string result; cout << "CensorString2" << endl;
    cout << "text is: " << text << endl;
    cout << "remove is: " << remove << endl;

    cout << "text length is: " << text.length() << endl;


    for(unsigned int i = 0; i < text.length(); i++)
    {
        cout << "text[i] is : " << text.substr(i,1) << endl;
        //if ( !stringContains(remove, text.substr(i,1)) )
        if( remove.find(text[i]) == string::npos )
        {
            result.append(text.substr(i,1));
        }
        else
        {
            text.erase(i,1);
        }
    }

    cout << "text is :" << text << endl;
}

void CountLetters(string filename)
{
    int result[26];
    string ret;
    int count = 0;
    string str;
    ifstream infile;
    infile.open(filename.data());   //将文件流对象与文件连接起来
    //assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    for(unsigned int i = 0; i < 26; i++)
    {
        result[i] = 0;
    }

    while(getline(infile,str))
    {
        count++;
        //cout << str << endl;

        for(unsigned int i = 0; i < str.length(); i++)
        {
            if( !isalpha(str[i]) )
            {
                continue;
            }
            else
            {
                cout << toUpperCase(charToString(str[i])) << endl;
                //ret.append( toUpperCase(charToString(str[i])) );
                cout << (int)(stringToChar(toUpperCase(charToString(str[i])))-'A') << endl;
                result[(int)(stringToChar(toUpperCase(charToString(str[i])))-'A')]++;
            }
        }

    }

    for(unsigned int i = 0; i < 26; i++)
    {
        cout << (char)('a'+i) << ":" << result[i] << endl;
    }

    infile.close();             //关闭文件输入流
}
