#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include <iostream>
#include <string>
using namespace std;

class CheckInput
{
public:
    virtual bool IsNumber(string &choice);
    virtual bool IsNumber(string &choice1, string &choice2);
    virtual bool IsAlphabet(char choice);
};

#endif