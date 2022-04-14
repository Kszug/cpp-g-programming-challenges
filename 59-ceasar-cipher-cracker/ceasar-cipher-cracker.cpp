#include <iostream>
#include <string>

int main(){
    std::string message;
    std::cin >> message;
    for(int i = 1; i < 25; i++){
        for(int j = 0; j < message.size(); j++){
            if(message[j] != ' '){
                std::cout << char(((message[j] - 'A' + 1 + i) % 26) + 'A');
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
