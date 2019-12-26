#include <iostream>
#include "parser/parser.hpp"

using namespace std;

int main(void)
{
    Parser m_parser = Parser("./tests/Makefile/basic");

    cout << m_parser.p_vars["VAR0"] << endl;

    return 0;
}
