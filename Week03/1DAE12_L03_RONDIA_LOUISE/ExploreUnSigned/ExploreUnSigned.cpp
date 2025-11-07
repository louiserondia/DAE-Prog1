// Louise Rondia, 1DAE12
// Louise Rondia, 1GD12E ? don't know what i'm supposed to write

#include <iostream>

void ExploreNumberRepresentation();
void ExploreUnsigned();

int main()
{
    ExploreNumberRepresentation();
    ExploreUnsigned();
}

void ExploreNumberRepresentation() {
    const int decimal{ 12 }, hexadecimal(0xc), binary{0b1100};
    std::cout << "Variable value itinialized with decimal value: " << decimal << std::endl;
    std::cout << "Variable value itinialized with hexadecimal value: " << hexadecimal << std::endl;
    std::cout << "Variable value itinialized with binary value: " << binary << std::endl;
}

void ExploreUnsigned() {
    const char minChar{ -128 }, maxChar{ 127 };
    const unsigned char minUnsignedChar{ 0 }, maxUnsignedChar{ 255 };
    const int minInt{ INT32_MIN }, maxInt{ INT32_MAX };
    const unsigned int minUnsignedInt{ 0 }, maxUnsignedInt{ UINT32_MAX };

    std::cout << std::endl;
    std::cout << "minChar: " << minChar << std::endl;
    std::cout << "minUnsignedChar: " << minUnsignedChar << std::endl;
    std::cout << "minInt: " << minInt << std::endl;
    std::cout << "minUnsignedInt: " << minUnsignedInt << std::endl;
    
    std::cout << std::endl;
    std::cout << "maxChar: " << maxChar << std::endl;
    std::cout << "maxUnsignedChar: " << maxUnsignedChar << std::endl;
    std::cout << "maxInt: " << maxInt << std::endl;
    std::cout << "maxUnsignedInt: " << maxUnsignedInt << std::endl;

    std::cout << "--------> Trying to exceed the ranges : " << std::endl;
    
    std::cout << std::endl;
    std::cout << "minChar: " << char(minChar - 1) << std::endl;
    std::cout << "minUnsignedChar: " << unsigned char (minUnsignedChar - 1) << std::endl;
    std::cout << "minInt: " << int(minInt - 1) << std::endl;
    std::cout << "minUnsignedInt: " << unsigned int( minUnsignedInt << - 1) << std::endl;

    std::cout << std::endl;
    std::cout << "maxChar: " << char(maxChar + 1) << std::endl;
    std::cout << "maxUnsignedChar: " << unsigned char(maxUnsignedChar + 1) << std::endl;
    std::cout << "maxInt: " << int(maxInt + 1) << std::endl;
    std::cout << "maxUnsignedInt: " << unsigned int(maxUnsignedInt + 1) << std::endl;
}