#include <bits/stdc++.h>
using namespace std;

const int a = 19;
const int b = 6;
string msg = "";
string cipher_text = "";

string EncryptedMessage(string msg){
    for (int i = 0; i < msg.length(); i++){
        if(msg[i] = ' '){
            cipher_text = cipher_text + (char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        }
        else{
            cipher_text += msg[i];
        }
    }
    return cipher_text;
}

string DecryptedMessage(string cipher_text){
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i<26; i++){
        flag = (a * i) % 26;
        if (flag == 1){
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher_text.length(); i++){
        if(cipher_text[i]!=' '){
            msg = msg + (char)(((a_inv * ((cipher_text[i]+'A' - b)) % 26)) + 'A');
        }
        else{
            msg += cipher_text[i];
        }
        return msg;
    }
}

int main(void){
    cout << "Please input your message:" << endl;
    cin >> msg;
    string cipherMessage = EncryptedMessage(msg);
    cout << "Encrypted Message is: " << cipherMessage << endl;
    cout << "Decrypted Message is:" << DecryptedMessage(cipherMessage);
    return 0;
}