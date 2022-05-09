#ifndef GENERATE_CODE_H
#define GENERATE_CODE_H
#include "mainwindow.h"

bool is_in_data_base(int generated_code){
    QSqlQuery query;
     query.exec("SELECT * FROM dates");
     while (query.next()) {
            int gotten_id_from_data_base = query.value(0).toInt();
            if(generated_code == gotten_id_from_data_base){
                return true; // yes it already has code in data base
            }

        }
     return  false; //code was not found.
}

//simple function to generate code
int get_code_for_row(){

    int generated_code  = qrand()%23423543;
    if(is_in_data_base(generated_code) == false){
        return  generated_code;
    }
    else{
        get_code_for_row();
    }


}


#endif // GENERATE_CODE_H
