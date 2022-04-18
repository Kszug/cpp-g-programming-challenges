#include <iostream>
#include <string>

int main(){
    std::string s, res = "";
    std::getline(std::cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            res += (char) (s[i] - 'a' + 13) % 26 + 'a';
        else if(s[i] >= 'A' && s[i] <= 'Z') 
            res += (char) (s[i] - 'A' + 13) % 26 + 'A';
        else 
            res += s[i];

    }

    std::cout << res;

}
