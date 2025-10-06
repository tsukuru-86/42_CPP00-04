#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();

    // セッター（空文字チェックは呼び出し側で行う）
    void setFirstName(const std::string& s);
    void setLastName(const std::string& s);
    void setNickname(const std::string& s);
    void setPhoneNumber(const std::string& s);
    void setDarkestSecret(const std::string& s);

    // ゲッター
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;

    // 5項目すべて非空なら true
    bool isComplete() const;
};

#endif
