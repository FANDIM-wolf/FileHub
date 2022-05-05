#ifndef TOKEN_H
#define TOKEN_H

#endif // TOKEN_H

#include "add_user_in_db.h";

QString get_random_symbol_of_alphabet(){
    QString alphabet[69] ={"Q" ,"W", "E" ,"R" , "T" , "Y" , "U" ,"I" ,"O" ,"P" ,"A" ,"S" ,"D" ,"F","G","H","J","K","L" ,"Z" ,"X" ,"C","V","B","N" ,"M","q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h" ,"j","k","l","z","x","c","v","b","n","m","!","@","$" ,"%"};
    int random_value = qrand()%69;
    return alphabet[random_value];
}

QString get_random_token(){

    QString  token;
    for(int i=0 ; i<= 10 ;i++){
        token += get_random_symbol_of_alphabet();
    }
    return token;
}
