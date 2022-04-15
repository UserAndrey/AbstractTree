#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
using namespace std;
// Представление математического выражения в виде дерева
class Exp
{
public:
    Exp() {}
    virtual ~Exp() {}
    virtual void release() {}
    virtual string print() { return ""; }
    static float calculate(string &exp);
    static float calculate(const QString,&exp);
private:
    static Exp* strToExp(string& str); // Построитель абстрактного дерева из строки
};
// Конечный элемент абстрактного дерева
class Term : public Exp
{
public:
    Term(string v) : val(v) {}
    void release() {}

    string print();
private:
    string val;
};
// Узел абстрактного дерева
class Node : public Exp
{
public:
   Node(char op, Exp* left, Exp* right) : op(op), l_exp(left), r_exp(right) {}

    ~Node() {}
    void release();
    string print();
private:
    char op; // Возможные значения +, -, *, /
    Exp* l_exp;
    Exp* r_exp;
};