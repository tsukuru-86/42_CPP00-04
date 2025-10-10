#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "アドレスの出力:" << std::endl;
	std::cout << "文字列変数のアドレス: " << &str << std::endl;
	std::cout << "ポインタの保持するアドレス: " << stringPTR << std::endl;
	std::cout << "参照のアドレス" << &stringREF << std::endl;
	
	std::cout << "\n値の出力:" << std::endl;
    std::cout << "文字列変数の値: " << str << std::endl;
    std::cout << "ポインタを使用した値: " << *stringPTR << std::endl;
    std::cout << "参照を使用した値: " << stringREF << std::endl;

    return 0;
}