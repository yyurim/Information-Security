//
//  main.cpp
//  VigenereCipher
//
//  Created by 윤유림 on 20/09/2019.
//  Copyright © 2019 윤유림. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string VigenereCipherDecryption(string cipherTxt);

int main() {
    string cipherText = "BSIHCJJHLNBOTFJFHFTBPJQRWWQD";

    cout << "Ciphertext : " << cipherText << endl << endl;
    
    cout << "****** Decrypting with Vigenere Cipher ******" << endl;
    cout << "  key   :        decrypted text        " << endl;
    cout << VigenereCipherDecryption(cipherText) << endl;
    return 0;
}

string VigenereCipherDecryption(string cipherText){
    string plainText = cipherText;
    string temp1 = cipherText;
    char keyword[3] = {'A', 'A', 'A'};
    
    // the plaintext starts with 'W', so key[0] = 1 - 22 + 26 = 5
    keyword[0] = 'F'-'A';
    
    // decrypt first one in every three alphabet in ciphertext
    for(int modPos0 = 0; modPos0 < cipherText.length() ; modPos0 += 3){
        if(temp1[modPos0] - keyword[0] >= 'A' && temp1[modPos0] - keyword[0] <= 'Z')
            cipherText[modPos0] = cipherText[modPos0] - keyword[0];
        else
            cipherText[modPos0] = cipherText[modPos0] - keyword[0] + 26;
    }
    
    plainText = cipherText;
    
    // decrypt the keyword
    // iterate for second alphabet of the keyword
    for(int i = 0; i < 26 ; i++){
        string temp2 = cipherText;
        
        // iterate for second one in every three alphabet in ciphertext
        for(int modPos1 = 1; modPos1 < temp2.length() ; modPos1 += 3){
            if(temp2[modPos1] - i >= 'A' && temp2[modPos1] - i <= 'Z')
                temp2[modPos1] = temp2[modPos1] - i;
            else
                temp2[modPos1] = temp2[modPos1] - i + 26;
        }
        
        // iterate for third alphabet of the keyword
        for(int j = 0; j < 26 ; j++){
            string temp3 = temp2;
            
            // iterate for third one in every three alphabet in ciphertext
            for(int modPos2 = 2; modPos2 < temp3.length() ; modPos2 += 3){
                if(temp3[modPos2] - j >= 'A' && temp3[modPos2] - j <= 'Z')
                    temp3[modPos2] = temp3[modPos2] - j;
                else
                    temp3[modPos2] = temp3[modPos2] - j + 26;
            }
            
            cout << "("<< (char)('A'+keyword[0]) << "," <<(char)('A'+ i)<< "," << (char)('A'+ j) << ") : " << temp3 << endl;
        }
        
        cout << endl;
    }
    
    // find the keyword
    cout << "select the keyword : ";
    cin >> keyword[0] >> keyword[1] >> keyword[2];
    keyword[0] -= 'A';
    keyword[1] -= 'A';
    keyword[2] -= 'A';

    // show the plaintext
    // decrypt second one in every three alphabet in ciphertext with second alphabet of the keyword
    for(int modPos1 = 1; modPos1 < cipherText.length() ; modPos1 += 3){
        if(cipherText[modPos1] - keyword[1] >= 'A' && cipherText[modPos1] - keyword[1] <= 'Z')
            plainText[modPos1] = cipherText[modPos1] - keyword[1];
        else
            plainText[modPos1] = cipherText[modPos1] - keyword[1] + 26;
    }
    
    // decrypt third one in every three alphabet in ciphertext with third alphabet of the keyword
    for(int modPos2 = 2; modPos2 < cipherText.length() ; modPos2 += 3){
        if(cipherText[modPos2] - keyword[2] >= 'A' && cipherText[modPos2] - keyword[2] <= 'Z')
            plainText[modPos2] = cipherText[modPos2] - keyword[2];
        else
            plainText[modPos2] = cipherText[modPos2] - keyword[2] + 26;
    }
    
    return plainText;
}
