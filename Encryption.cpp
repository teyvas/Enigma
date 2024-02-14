#include<iostream>
#include<string>
#include<algorithm>
#include <boost/algorithm/string/erase.hpp>
#include<fstream>
std:: string removeSpecialCharacter(std:: string s)
{
    
    std:: string empty = "";
    for (auto ch : s) {
        // if the current character
        // is an alphabet
        if (isalpha(ch))
            empty += ch;
    }
    return(empty);
}


std:: string Ceasar_encrypt(std:: string sentence){
      //std:: string sentence;
      
      int key;
      std:: cout<<"Please, write key (any number) for encrypting your sentence: ";
      //getline(std:: cin, sentence);
      std:: cin>>key;
      char temp;
      std:: string crypt_str;
      for(int i=0; i<sentence.size(); i++){
            if (isupper(sentence[i])){
                  crypt_str += char(int(sentence[i] + key - 65) %26  + 65);
            }
            
            else{
                  crypt_str += char(int(sentence[i] + key - 97) %26  + 97);
            }
            
            
      }
      return(crypt_str);
}

std:: string Ceasar_decrypt(std:: string sentence){
      //std:: string sentence;
      
      int key;
      std:: cout<<"Please, write key, which was esed for encrypting your sentence: ";
      
      std:: cin>>key;
      char temp;
      key=26-key;
      std:: string crypt_str;
      for(int i=0; i<sentence.size(); i++){
            if (isupper(sentence[i])){
                  crypt_str += char(int(sentence[i] + key - 65) %26  + 65);
            }
            
            else{
                  crypt_str += char(int(sentence[i] + key - 97) %26  + 97);
            }
            
            
      }
       return(crypt_str);
}


std:: string Vigenere_encrypt(std:: string sentence){
      std:: cout<<"Please, write key (any word) for encrypting your sentence: ";
      std:: string key;
      std:: cin>>key;
      int i=0;
      std:: string encrypted;

      
      for (int i=0; i<key.size(); i++){
            key[i]=toupper(key[i]);
      }

      for (int i = 0; i<sentence.size(); i++){
            if (sentence.size() == i)
            i = 0;
            if (key.size() == sentence.size())
                  break;
            key.push_back(key[i]);
      }
      
      
      for (int i=0; i<sentence.size(); i++){
            sentence[i]=toupper(sentence[i]);
      }
      

      for (int i=0; i<sentence.size(); i++){
            char w = (sentence[i]+key[i])%26;

            w += 'A';

            encrypted.push_back(w);

      }
      return(encrypted);
}

std:: string Vigenere_decrypt(std:: string sentence){
      
      std:: cout<<"Please, write key, which was used for encrypting your sentence: ";

      std:: string key;

      std:: cin>>key;
      for (int i=0; i<key.size(); i++){
            key[i]=toupper(key[i]);
      }
       
      for (int i = 0; i<sentence.size(); i++){
            if (sentence.size() == i)
            i = 0;
            if (key.size() == sentence.size())
                  break;
            key.push_back(key[i]);
      }
     

      int i=0;

      std:: string decrypted;
      for (int i=0; i<sentence.size(); i++){
            char w = (sentence[i]-key[i]+26)%26;

            w += 'A';

            decrypted.push_back(w);

      }
      return(decrypted);
}


int main(){
      std:: string sentence; 
      std:: fstream my_file;
      my_file.open ("Text_to_decrypt_2vigenere.txt");
      char d_e,ch;
      int method;
      if (!my_file) {
		std:: cout << "No such file";
	}

	else {

      while(true){
		my_file >> ch;
		if (my_file.eof())
			break;

		sentence+= ch;
	}
      }      
      my_file.close();

      sentence = removeSpecialCharacter(sentence);

      std:: cout<<"Do you want encrypt or decrypt sentence?\n";
      std:: cout<<"E/D \n";
      std:: cin>>d_e;
      if(d_e=='E' or d_e=='e'){
            std:: cout<<"Which encrypt you prefer:\n";
            
            std:: cout<<"1 : Ceasar cipher\n";
            std:: cout<<"2 : Vigenère cipher\n";
            std:: cout<<'\n';
            std:: cout<<"Input a number: ";
            std:: cin>>method;
            std:: cout<<std:: endl;
            switch(method){
                  case 1:
                  std:: cout<<Ceasar_encrypt(sentence);
                  break;
                  case 2:
                  std:: cout<<Vigenere_encrypt(sentence);
            }
      }
      else{
            std:: cout<<"Which encrypt you used:\n";
            std:: cout<<"1 : Ceasar cipher\n";
            std:: cout<<"2 : Vigenère cipher\n";
            std:: cout<<'\n';
            std:: cout<<"Input a number: ";
            std:: cin>>method;

            switch(method){
                  case 1:
                  std:: cout<<Ceasar_decrypt(sentence);
                  break;
                  case 2:
                  std:: cout<<Vigenere_decrypt(sentence);
            }
      }
      

}