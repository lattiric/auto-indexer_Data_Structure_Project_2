//
// Created by Rick Lattin on 2/4/21.
//
#include "DSString.h"

#include<iostream>
#include<cstring>

DSString::DSString(){
    data = new char[1];
    data[0] = '\0';
}

DSString::DSString(const char* str){             //copy constructors
    data = new char [strlen(str) + 1];
    strcpy(data, str);
}

DSString::DSString(const DSString& str){
    data = new char [str.getLength() + 1];
    strcpy(data, str.data);
}

DSString::~DSString(){                          //destructor
    delete[] data;
}

//-------------------------------------------------------------------       //DSString Operators


DSString& DSString::operator =(const char* str){
    delete[] data;

    data = new char[strlen(str)+1];
    strcpy(data, str);
    return* this;
}

DSString& DSString::operator =(const DSString& str){
    if(this == &str)
        return *this;

    delete[] data;
    data = new char[strlen(str.data)+1];
    strcpy(data, str.data);
    return* this;
}

DSString DSString::operator+ (const DSString& str){
    DSString temp;
    temp.data = new char[strlen(data)+strlen(str.data)+1];
    strcpy(temp.data, data);
    strcat(temp.data, str.data);
    return temp;
}

bool DSString::operator== (const char* str){
    if(strcmp(data, str) != 0)
        return false;
    return true;
}

bool DSString::operator== (const DSString& str){
    if(strcmp(data, str.data) != 0)
        return false;
    return true;
}

bool DSString::operator!= (const char* str){
    if(strcmp(data, str) == 0)
        return false;
    return true;
}

bool DSString::operator!= (const DSString& str){
    if(strcmp(data, str.data) == 0)
        return false;
    return true;
}

bool DSString::operator> (const DSString& str) const{
    if(strcmp(data, str.data) > 0)
        return true;
    return false;
}

bool DSString::operator< (const DSString& str) const{
    if(strcmp(data, str.data) < 0)
        return true;
    return false;
}

char& DSString::operator[] (const int i){
    return data[i];
}
//--------------------------------------------------------------------      //Other DSString functions (including cout)

int DSString::getLength() const{
    return strlen(data);
}

DSString DSString::trimExtra() {            //trims unnecessary characters from back of a DSString
    for(int i = getLength()-1; i>0; i--)
        if(isalpha(data[i]))
            i = 0;
        else if(data[i] == ' ' || data[i] == '.' || data[i] == ',' || data[i] == '!' || data[i] == '/' || data[i] == '[' || data[i] == ']' || data[i] == '-' || data[i] == ';' || data[i] == '?')
            data[i] = '\0';
    return data;
}

DSString DSString::trimBasic()  {
    for(int i = getLength()-1; i>0; i--)
        if(data[i] == '.' || data[i] == ',' || data[i] == '!' || data[i] == ';' || data[i] == '?')
            data[i] = '\0';
    return data;
}

DSString DSString::substring(int start, int numChars){

    DSString temp;
    temp.data = new char[numChars+1];
    for(int i = 0; i < numChars; i++){
        temp.data[i] = data[i+start];
    }
    temp.data[numChars] = '\0';
    return temp;
}

DSString DSString::makeLower() {            //turns a DSString to all lowercase letters
    for(int i = 0; i<this->getLength(); i++){
        data[i] = tolower(data[i]);
    }
    return data;
}

DSString DSString::makeUpper() {            //turns a DSString to all uppercase letters
    for(int i = 0; i<this->getLength(); i++){
        data[i] = toupper(data[i]);
    }
    return data;
}

char* DSString::c_str() const{              //turns DSString into a char*
    return data;
}

std::ostream& operator<< (std::ostream& out, const DSString& str){
    out << str.data;
    return out;
}

