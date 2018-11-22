#include "expression.h"

/* Function:                          ***************************************************
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 *
 * *************************************************************************************/
expression::expression()
{
    this->ifix = "";
    this->last = false;
}

/* Function:                          ***************************************************
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 *
 * *************************************************************************************/
void expression::convertToPostfix()
{
    stack<char> __charStack__;
    __charStack__.push('$');
    this->pfix = "\0";

    for(size_t i = 0; i < this->ifix.size() - 1; i++)
    {
        switch(this->ifix[i])
        {
            case '(':
            {
                __charStack__.push(this->ifix[i]);
                break;
            }
            case ')':
            {
                while(__charStack__.top() != '(')
                {
                    this->pfix += __charStack__.top();
                    __charStack__.pop();
                }
                __charStack__.pop();
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':
            {
                while(this->precedence(__charStack__.top(), this->ifix[i]))
                {
                    this->pfix += __charStack__.top();
                    __charStack__.pop();
                }
                __charStack__.push(this->ifix[i]);
                break;
            }
            default:
                this->pfix += this->ifix[i];
        }
    }
    while(__charStack__.top() != '$')
    {
        this->pfix += __charStack__.top();
        __charStack__.pop();
    }
}

/* Function:                          ***************************************************
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 *
 * *************************************************************************************/
bool expression::precedence(char s, char c) const
{
    if(s == '*' || s == '/') return true;
    if(s == '(' || s == '$') return false;
    return (c == '+' || c == '-');
}

/* Function:                          ***************************************************
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 *
 * *************************************************************************************/
std::istream& operator>>(std::istream& is, expression& exp)
{
    char __sym__;
    exp.ifix = "\0";
    do
    {
        is >> __sym__;
        exp.ifix += __sym__;
    }
    while(__sym__ != ';' && __sym__ != '.');

    if(__sym__ == '.')
        exp.last = true;
    exp.convertToPostfix();
    return is;
}

/* Function:                          ***************************************************
 *
 * Description:
 *
 * Preconditions:
 *
 * Postconditions:
 *
 * *************************************************************************************/
std::ostream& operator<<(std::ostream& os, const expression& exp)
{
    os << "Infix:   " << exp.ifix << std::endl;
    os << "Postfix: " << exp.pfix << std::endl;
    return os;
}
