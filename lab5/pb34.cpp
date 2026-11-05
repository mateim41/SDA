#include <iostream>
#include "LinkedNode.hpp"
#include <cstring>
#include <string>
#include <cctype>
#include <string_view>

bool IsOperator(const char &c)
{
    if (strchr("+-*/()", c))
        return true;
    return false;
}

int Priority(const char &c)
{
    if (c == '(' || c == ')')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return -1;
}

// daca am numere negative  trebuie sa mai modific conditiile putin
// eg: -2 + 3 => 3 - 2
std::string ConvertEquationPostFixed(const std::string &expresie)
{
    std::string convertedEquation = "";
    StivaDinamic<char> *s = nullptr; // pt operanzi

    for (auto &&c : expresie)
    {
        if (!strchr(" ", c))
        {
            if (c == '(')
            {
                Push(s, c);
            }
            else if (!IsOperator(c))
            {
                convertedEquation = convertedEquation + ' ' + c;
            }
            else
            {
                while (!IsEmpty(s) && Priority(c) <= Priority(Top(s)))
                {
                    if (Top(s) != '(')
                        convertedEquation = convertedEquation + ' ' + Top(s);
                    else
                    {
                        Pop(s);
                        break;
                    }
                    Pop(s);
                }
                if (c != ')')
                    Push(s, c);
            }
        }
    }
    while (!IsEmpty(s))
    {
        convertedEquation = convertedEquation + ' ' + Top(s);
        Pop(s);
    }

    return convertedEquation.substr(1);
}

template <typename T>
int MakeOperation(StivaDinamic<T> *&s, const char &c)
{
    int result = 0;
    int nr1 = Top(s);
    Pop(s);

    int nr2 = Top(s);
    Pop(s);
    switch (c)
    {
    case '+':
        result = nr2 + nr1;
        break;
    case '-':
        result = nr2 - nr1;
        break;
    case '*':
        result = nr2 * nr1;
        break;
    case '/':
        result = nr2 / nr1;
        break;
    default:
        break;
    }
    Push(s, result);
    return result;
}

int EvaluateExpressionPostFixed(const std::string &expresie)
{
    std::string modifiedEquation = ConvertEquationPostFixed(expresie);
    StivaDinamic<int> *s = nullptr; // stiva pentru operat
    int result = 0;

    for (auto &&c : modifiedEquation)
    {
        if (!strchr(" ", c))
        {
            if (!IsOperator(c))
            {
                int nr = c - '0';
                Push(s, nr);
            }
            else
            {
                MakeOperation(s, c);
            }
        }
    }
    result = Top(s);
    Pop(s);
    return result;
}

int main()
{
    // 1+5*(-2+3-5+6*2/7)/2*9-2
    std::string expresie = "(2+3)*5-6";
    std::cout << EvaluateExpressionPostFixed(expresie) << "\n";

    return 0;
}