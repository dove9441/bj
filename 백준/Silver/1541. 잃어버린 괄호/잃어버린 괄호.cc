#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(void){
    string str;
    cin >> str;
    int sum = 0;
    bool flag = false;
    string temp = "";
    for(int i=0; i<=str.length(); i++){

        if(str[i] == '-' || str[i]=='+' || i == str.length()){
            if (!temp.empty()) {
                int num = stoi(temp);
                sum += (flag ? -num : num);
                temp.clear();
            }
            if (i < str.length() && str[i]=='-') {
                flag = true;
            }
        }else{
            string t = string(1, str[i]);
            temp.append(t);
        }

    }

    cout << sum << '\n';

}
