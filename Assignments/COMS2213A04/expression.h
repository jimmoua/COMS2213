#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <cstddef>
#include <iostream>
#include <string>
#include "stack.h"

class expression
{
    public:
        expression();
        friend std::istream& operator>>(std::istream&, expression&);
        friend std::ostream& operator<<(std::ostream&, const expression&);
        bool last;
    private:
        void convertToPostfix();
        bool precedence(char, char) const;

        std::string ifix; // Normal string
        std::string pfix; // Parse ifix string → into pfix
};

#endif
