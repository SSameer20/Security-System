#include <iostream>
#include <string>

// using namespace std;
class User
{
private:
    std::string email;
    std::string password;
    std::string username;
    std::string key = "MySecretK3y";
    int shift = 51;
    std::string encrypt(const std::string &str)
    {
        std::string result;
        
        int keyIndex = 0;
        for (char c : str)
        {

            char base = '#';
            int shift = (key[keyIndex % key.length()] - base) % 26;
            result += (c - base + shift) + base;
            keyIndex++;
        }
        return result;
    }

    std::string decrypt(const std::string &str)
    {
        std::string result;
        int keyIndex = 0;
        for (char c : str)
        {
             char base = '#';
                int shift = (key[keyIndex % key.length()] - base) % 26;
                result += (c - base - shift + 26) % 26 + base;
                keyIndex++;
            
            
        }
        return result;
    }

public:
    void Register()
    {
        std::string test_email;
        std::string test_password;
        std::string test_confirmPassword;
        std::string test_username;

        std::cout << "==============================================\n";
        std::cout << "===                                        ===\n";
        std::cout << "===               Registration             ===\n";
        std::cout << "===                                        ===\n";
        std::cout << "==============================================\n"
                  << std::endl;
        std::cout << "Please Enter your Details Details \n";
        std::cout << "Enter your Email \n";
        std::cin >> test_email;
        std::cout << "Enter your Username \n";
        std::cin >> test_username;
        std::cout << "Enter your Password \n";
        std::cin >> test_password;
        std::cout << "Re-Enter your Password \n";
        std::cin >> test_confirmPassword;
        if (test_password == test_confirmPassword)
        {
            email = test_email;
            password = encrypt(test_password);
            username = test_username;
            // std::cout << email<<std::endl;
            // std::cout << password << std::endl;
            // std::cout << decrypt(password) << std::endl;

            // std::cout << username<<std::endl;
        }
        else
        {
            std::cout << "Password Dont match";
        }
    }
};

class Security
{
private:
public:
    void company()
    {
        std::cout << "\n\n"
                  << std::endl;
        std::cout << ".            ######  ##      ######  ##   ##   ######  ######  ##     ##            .\n";
        std::cout << ".            ##      ##      ##  ##  ##   ##      ##   ##      ## ##  ##            .\n";
        std::cout << ".            ##      ##      ##  ##  ##   ##     ##    ######  ##  ## ##            .\n";
        std::cout << ".            ##      ##      ##  ##  ##   ##   ##      ##      ##   ####            .\n";
        std::cout << ".            ######  ######  ######  #######  ######   ######  ##     ##            .\n";
        std::cout << "\n\n\n"
                  << std::endl;
    }
    void starter()
    {
        // company();
        std::cout << "============================================================================================\n";
        std::cout << "============================================================================================\n";
        std::cout << "===                                                                                      ===\n";
        std::cout << "===                             Welcome To Security System                               ===\n";
        std::cout << "===                                                                                      ===\n";
        std::cout << "============================================================================================\n";
        std::cout << "============================================================================================\n"
                  << std::endl;
        int flag = 0;
        
        menu(flag);

    }

    void complete()
    {

        std::cout << "==============================================\n";
        std::cout << "===                                        ===\n";
        std::cout << "===                                        ===\n";
        std::cout << "===  Thanks for Using our Security System  ===\n";
        std::cout << "===                                        ===\n";
        std::cout << "===                                        ===\n";
        std::cout << "==============================================\n"
                  << std::endl;
    }

    void menu(int &flag)
    {

        std::cout << "Select an option to continue \n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login \n";
        std::cout << "0. To Exit \n";
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        User user;
        user.Register();
    }
};

int main()
{
    Security security;
    security.starter();
    return 0;
}