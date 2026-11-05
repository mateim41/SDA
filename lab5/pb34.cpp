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

std::string ConvertFromPostFixToPreFix(const std::string &expresie)
{
    std::string expresiePostFixed = ConvertEquationPostFixed(expresie);
    StivaDinamic<std::string> *stack = nullptr;

    for (auto &&c : expresiePostFixed)
    {
        if (c != ' ')
        {
            if (!IsOperator(c))
            {
                std::string temp(1, c);
                Push(stack, temp);
            }
            else
            {
                std::string nr2 = Top(stack);
                Pop(stack);

                std::string nr1 = Top(stack);
                Pop(stack);

                std::string exprModif(1, c);
                exprModif += (nr1 + nr2);
                Push(stack, exprModif);
            }
        }
    }
    std::string result = Top(stack);
    Pop(stack);
    return result;
}

int EvaluateExpressionPreFixed(const std::string &expresie)
{
    std::string expresiePrefix = ConvertFromPostFixToPreFix(expresie);
    StivaDinamic<int> *stack = nullptr;

    for (int i = expresiePrefix.length() - 1; i >= 0; i--)
    {
        char c = expresiePrefix[i];
        if (!IsOperator(c))
        {
            int nr = c - '0';
            Push(stack, nr);
        }
        else
        {
            auto nr1 = Top(stack);
            Pop(stack);

            auto nr2 = Top(stack);
            Pop(stack);

            // functia MakeOperation functioneaza doar pentru forma post fixata
            int result = 0;
            switch (c)
            {
            case '+':
                result = nr1 + nr2;
                break;
            case '-':
                result = nr1 - nr2;
                break;
            case '*':
                result = nr1 * nr2;
                break;
            case '/':
                result = nr1 / nr2;
                break;
            default:
                break;
            }
            Push(stack, result);
        }
    }
    int output = Top(stack);
    Pop(stack);
    return output;
}

int main()
{
    // 1+5*(3-2-5+6*2/7)/2*9-2
    std::string expresie = "1+5*(3-2-5+6*2/7)/2*9-2";
    std::cout << EvaluateExpressionPreFixed(expresie) << '\n';

    return 0;
}