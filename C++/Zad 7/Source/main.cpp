#include "Integer.h"
#include <string>
#include <iostream>

using namespace calculations;

std::string word_logic(bool r)
{
    return (r ? "true" : "false");
}

int main() {

    std::cout << "Constructing and printing" << std::endl;
    Integer default_constructor;
    Integer from_int = 2324;
    Integer from_string = "-87129487912847912847918274219487";
    Integer copy_constructor = from_int;
    std::cout << "Result:" << default_constructor << " " << from_int << " " << from_string << " " << copy_constructor << std::endl;

    std::cout << std::endl << "Get sign" << std::endl;
    Integer signed_num = -10;
    std::cout << signed_num << " sign is " << signed_num.get_sign() << std::endl;

    std::cout << std::endl << "Comparing" << std::endl;
    Integer comp_a = 1241;
    Integer comp_b = "18723987129837192837918124";
    Integer comp_c = 123;
    Integer comp_d = -123;
    Integer comp_e = "19999999999999999999999999999999";
    Integer comp_f = comp_e;
    std::cout << comp_a << " == " << comp_b << " -> " << word_logic(comp_a == comp_b) << std::endl;
    std::cout << comp_e << " == " << comp_f << " -> " << word_logic(comp_e == comp_f) << std::endl;
    std::cout << comp_d << " > " << comp_e << " -> " << word_logic(comp_d > comp_e) << std::endl;
    std::cout << comp_e << " <= " << comp_f << " -> " << word_logic(comp_e <= comp_f) << std::endl;
    std::cout << comp_c << " != " << comp_d << " -> " << word_logic(comp_c != comp_d) << std::endl;

    std::cout << std::endl << "Arithmetic" << std::endl;
    Integer arith_a = "-19817298312937441233423424";
    Integer arith_b = "712938719287971323";
    Integer arith_c = "618726837618376187716";
    Integer arith_d = "1000000000000000000000";
    Integer arith_e = "999999999999999999999";
    Integer arith_f = "9999";
    std::cout << arith_a << " + " << arith_b << " -> " << arith_a + arith_b << std::endl;
    std::cout << arith_b << " - " << arith_c << " -> " << arith_b - arith_c << std::endl;
    std::cout << arith_e << " - " << arith_d << " -> " << arith_e - arith_d << std::endl;
    std::cout << arith_d << " * " << arith_f << " -> " << arith_d * arith_f << std::endl;
    std::cout << arith_a << " / " << arith_b << " -> " << arith_a / arith_b << std::endl;
    std::cout << arith_a << " % " << arith_b << " -> " << arith_a % arith_b << std::endl;
    std::cout << "++" << arith_e << " -> " ; std::cout << ++arith_e << std::endl;
    std::cout << "--" << arith_f << " -> " ; std::cout << --arith_f << std::endl;

    std::cout << std::endl << "Exceptions" << std::endl;
    Integer exc_a = 10;
    Integer exc_b = 0;

    std::cout << exc_a << " / " << exc_b << " -> " << "Exception!" << std::endl;
    try {
        exc_a / exc_b;
    }
    catch (const div0& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::string very_bad_String = "something 123";

    std::cout << "Ill-formated string in constructor " << "Integer(\"" + very_bad_String + "\")" + " -> " << "Exception!" << std::endl;
    try {
        Integer very_bad(very_bad_String.c_str());
    }
    catch (const bad_string& ex)
    {
        std::cout << ex.what() << std::endl;
    }


    std::cout << std::endl << "Factorial: 100!" << std::endl;
    std::cout << Integer::factorial(100) << std::endl;
    return 0;
}
