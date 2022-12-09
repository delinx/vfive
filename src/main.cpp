#include "types.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
#ifdef UNIT_TEST
    std::cout << "--- UNIT TESTS ---" << std::endl;

    std::cout << "--- UNIT TESTS END ---" << std::endl;
    return 0;
#endif

    std::cout << "Template" << std::endl;
    return 0;
}
