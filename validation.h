/*
function(s) to define validity of name.
*/
#ifndef VALIDATION_H
#define VALIDATION_H

#endif // VALIDATION_H

#include "add_user_in_db.h";


bool is_name_valid(QString name_for_check){
    int symbols;// hold amount of unacceptable symbols
    for (int i = 0; i < name_for_check.length(); i++){
          if(name_for_check[i] != "&" && name_for_check[i] != "!" && name_for_check[i] !="#" && name_for_check[i] !="@"){
                if(name_for_check[i] != "%" && name_for_check[i] !="*" && name_for_check[i] != "^" && name_for_check[i] != "_"){
                    symbols += 1;
                }

          }
    }
    /*if validation completed successfully*/
    if(symbols == 0){
        return  true;
    }
    else
    {
        return false;
    }
}
