#include <iostream>
#include <fstream>

int main(){
    std::string passwordChoice;
    std::string usernameChoice;
    std::string typedUsername;
    std::string typedPassword;
    
    std::string filename = "credentials.txt";
    std::ifstream file(filename);
    std::string line;
    
    if (file.is_open()) {
        getline(file, usernameChoice);
        getline(file, passwordChoice);
        file.close();
    }

    if (passwordChoice.empty()){
        std::cout << "What would you like your username to be?: ";
        std::cin >> usernameChoice;
        
        std::cout << "\nWhat would you like your password to be?: ";
        std::cin >> passwordChoice;
        std::cout << "\n\nWelcome, " << usernameChoice;
        std::ofstream outFile(filename);
        outFile << usernameChoice << "\n" << passwordChoice;
        outFile.close();
        std::cout << "\n\n";
    }
    
    std::cout << "Please enter your username: ";
    std::cin >> typedUsername;
    
    std::cout << "\nPlease enter your password: ";
    std::cin >> typedPassword;
    
    if (typedUsername == usernameChoice && typedPassword == passwordChoice){
        std::cout << "\n\nWelcome, " << usernameChoice;
    } else{
        std::cout << "\n\nInvalid username or password";
    }
    
    return 0;
}
