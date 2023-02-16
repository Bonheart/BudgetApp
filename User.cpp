#include "User.h"

void User::set_users_id(int new_id){

    if(new_id > 0){

        users_id = new_id;
    }
}

void User::set_users_name(string new_name){


    users_name = new_name;

}
void User::set_users_surname(string new_surname){


    users_surname = new_surname;

}
void User::set_users_login(string new_login){


    users_login = new_login;

}
void User::set_users_password(string new_password){


    users_password = new_password;

}

int User::get_users_id(){


    return users_id;

}

string User::get_users_name(){


    return users_name;

}

string User::get_users_surname(){


    return users_surname;

}

string User::get_users_login(){


    return users_login;

}

string User::get_users_password(){


    return users_password;

}
