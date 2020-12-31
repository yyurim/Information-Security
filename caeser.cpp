//
//  main.cpp
//  CaeserCipher
//
//  Created by 윤유림 on 20/09/2019.
//  Copyright © 2019 윤유림. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string CaeserCipherDecryption(string cipherText);

int main() {
    string cipherText = "RGNEIDVGPEWNXHXCITGTHIXCV";
    
    cout << CaeserCipherDecryption(cipherText) << "\n";
    
    return 0;
}

string CaeserCipherDecryption(string cipherText){
    string plainText = cipherText;
    
    for(int testkey = 0; testkey < 26 ; testkey++){
        string temp = cipherText;
        
        for(int pos = 0; pos < temp.length() ; pos++){
            if(temp[pos] - testkey >= 'A' && temp[pos] - testkey <= 'Z')
                temp[pos] = temp[pos] - testkey;
            else
                temp[pos] = temp[pos] - testkey + 26;
        }
        
        cout << (char)('A' + testkey) << " : " << temp << "\n";
    }
    
    cout << "select the key : ";
    
    char key;
    cin >> key;
    key -= 'A';
    
    for(int pos = 0; pos < cipherText.length() ; pos++){
        if(cipherText[pos] - key >= 'A' && cipherText[pos] - key <= 'Z')
            plainText[pos] = cipherText[pos] - key;
        else
            plainText[pos] = cipherText[pos] - key + 26;
    }

    
    return plainText;
}
