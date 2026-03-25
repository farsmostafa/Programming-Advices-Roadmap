#include <iostream>
#include <string>
using namespace std;


int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    
    return number;
}


string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

bool UpperCase(char l){
    return int(l) >= 65 &&  int(l) <= 90; 
}


bool LowerCase(char l){
    return int(l) >= 97 &&  int(l) <= 122; 
}



string EncryptText(string text , int key = 2){
    string encryptedText="";
    key = ( ( key % 26 ) + 26 ) % 26; 
    for (int i = 0; i < text.length(); i++)
    {
        int letter = int(text[i]) + key ;
        if (UpperCase(text[i]))
        {
            letter > 90 ? encryptedText.append(1,char(letter % 90 + 65)) : encryptedText.append(1,char(letter)); 
        }else if (LowerCase(text[i])){
            letter > 122 ? encryptedText.append(1,char(letter % 122 + 97)) : encryptedText.append(1,char(letter)); 
        }else {
            encryptedText.append(1,char(letter));
        }
        
        
        
    }
    return encryptedText;
}


string DecryptText(string text , int key = 2){
    string decryptedText="";
    for (int i = 0; i < text.length(); i++)
    {
        int letter = int(text[i]) - key ;
        if (UpperCase(text[i]))
        {
            letter < 65 ? decryptedText.append(1,char(90 - (65 - letter))) : decryptedText.append(1,char(letter)); 
        }else if (LowerCase(text[i])){
            letter < 97 ? decryptedText.append(1,char(122 - (97 - letter))) : decryptedText.append(1,char(letter)); 
        }else {
        decryptedText.append(1,char(letter));
        }
    }
    return decryptedText;
}




void printResult(string text,int encryptionKey){
    string TextAfterEncryption = EncryptText(text, encryptionKey); 
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "\nText Before Encryption : " << text << endl;
    cout << "Text After Encryption  : " << TextAfterEncryption << endl;
    cout << "Text After Decryption  : " << DecryptText(TextAfterEncryption, encryptionKey) << endl;
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a text and encrypt it, decrtypt it.\n";
    cout <<"\tex  : \n\t\tText Before Encryption : Mohammed\n\t\tText After Encryption  : Oqjcoogf\n\t\tText After Decryption  : Mohammed\n\n";
    int encryptionKey = ReadPositiveNumber("Enter Enctyption Key : ");
    string text = ReadString("Enter string to use in Enctypion & Dectypion Process : ") ;
    printResult(text,encryptionKey);


    return 0;
}
 