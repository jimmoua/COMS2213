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
 * Postconditions: Sets the infix strings and places the converted infix string values
 *   into the postfix string.
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

/* Function: std::istream& operator>>(std::istream&, expression& ) **********************
 *
 * Description: This is the insertion operator overload function. It is invoked with we
 *   have the an object of the expression class to the right hand side of the operator.
 *   It will keep reading from a file that contains the infix expression until the end
 *   of the expression has been reached. The end of an expression is denoted with a
 *   semicolon. The end of all the expressions is denoted with a period. This means that
 *   even if there is something present at the end of the file after a period, those
 *   conents will simply be ignored.
 *
 * Preconditions: None.
 *
 * Postconditions: The infix string is modified such that it contains the contents of the
 *   infix expression from the file. Once we get to a period, which denotes the end of
 *   the infix expressions, the Boolean value "last" is set to true.
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

/* Function: std::ostream& operator<<(std::ostream&, const expression) ******************
 *
 * Description: This function will display the infix and postfix string values.
 *
 * Preconditions: An object of the expression class is on the right hand side of the
 *   extraction operator, thus directing the infix and postfix string values to an
 *   output stream.
 *
 * Postconditions: Does not modify anything.
 *
 * *************************************************************************************/
std::ostream& operator<<(std::ostream& os, const expression& exp)
{
  os << "Infix:   " << exp.ifix << std::endl;
  os << "Postfix: " << exp.pfix << std::endl;
  return os;
}
