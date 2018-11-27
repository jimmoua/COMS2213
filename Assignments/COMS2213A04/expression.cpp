#include "expression.h"

/* Function: expression::expression() **************************************************
 *
 * Description: The default ctor of the class. Sets ifix to nothing and last to false.
 *
 * Preconditions: An object of the class is instantiated.
 *
 * Postconditions: None.
 *
 * *************************************************************************************/
expression::expression()
{
  this->ifix = '\0';
  this->last = false;
}

/* Function: void expression::convertToPostfix() ****************************************
 *
 * Description: Converts the infix expression to a postfix expression.
 *
 * Preconditions: This function is invoked with the stream insertion operator is used
 *   on an object of the expression class and when the stream has read all the contents
 *   of a file (denoted with a '.').
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

/* Function: bool expression::precedence(char, char) const ******************************
 *
 * Description: Function that returns true if the first argument is '*' or '\', or if the
 *   second argument is '+' or '-'.
 *
 * Preconditions: The function convertToPostfix is invoked, causing this function to be
 *   invoked as well.
 *
 * Postconditions: This function does not modify anything, but its returned value is used
 *   to determine how the infix will be converted to postfix.
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
