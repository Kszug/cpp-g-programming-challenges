#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main(){
    setlocale(LC_ALL, "");
    std::wstring s;
    std::vector<wchar_t> v;
    std::unordered_map<wchar_t, int> um;
    
    std::getline(std::wcin, s);
    for(int i = 0; i < s.size(); i++){
        if(um.find(s[i]) == um.end()) {
            v.push_back(s[i]);
            um.insert({s[i], 1});
        }
        else {
            um.at(s[i])++;
        }
    }

    for(int i = 0; i < v.size(); i++)
        std::wcout << v[i] << ": " << um.at(v[i]) << '\n';

}
