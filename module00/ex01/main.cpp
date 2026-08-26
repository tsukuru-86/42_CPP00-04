#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>

static std::string promptNonEmpty(const std::string& label) {
    std::string s;
    while (true) {
        std::cout << label;
        if (!std::getline(std::cin, s)) return "";

        while (!s.empty() && (s[0] == ' ' || s[0] == '\t')) s.erase(0, 1);
        while (!s.empty() && (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t')) s.erase(s.size()-1, 1);

        if (!s.empty()) return s;
        std::cout << "からの入力は不可です。もう一度入力してください\n";
    }
}

static bool isNumber(const std::string& s) {
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    return true;
}

int main() {
    PhoneBook pb;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            break;

        if (cmd == "ADD") {
            Contact c;
            std::string v;

            v = promptNonEmpty("First name: ");     if (v.empty()) break; c.setFirstName(v);
            v = promptNonEmpty("Last name: ");      if (v.empty()) break; c.setLastName(v);
            v = promptNonEmpty("Nickname: ");       if (v.empty()) break; c.setNickname(v);
            v = promptNonEmpty("Phone number: ");   if (v.empty()) break; c.setPhoneNumber(v);
            v = promptNonEmpty("Darkest secret: "); if (v.empty()) break; c.setDarkestSecret(v);

            pb.addContact(c);
            std::cout << "保存しました （現在" << pb.size() << "件)。\n";
        } else if (cmd == "SEARCH") {
            if (pb.size() == 0) {
                std::cout << "データがありません。\n";
            } else {
                pb.printSummary();

                std::cout << "表示するインデックスを入力してください: ";
                std::string indexStr;
                if (!std::getline(std::cin, indexStr))
                    break;

                if (!isNumber(indexStr)) {
                    std::cout << "数字で入力してください。\n";
                    continue;
                }

                if (indexStr.size() != 1) {
                    std::cout << "有効範囲は 1 ~ " << pb.size() << "です。\n";
                    continue;
                }

                int idx = indexStr[0] - '0';
                if (!pb.printDetailByIndex(idx))
                    std::cout << "有効範囲は 1 ~ " << pb.size() << "です。\n";
            }
        } else if (cmd == "EXIT") {
            break;
        } else {
            std::cout << "無効なコマンドです\n";
        }
    }
    return 0;
}
