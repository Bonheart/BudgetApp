#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Helpful_Methods.h"
#include "Users_file.h"


using namespace std;

class User_Manager{

    Users_File users_file;
    vector <User> users;
    User insert_new_users_data();
    int logged_users_id;
    bool check_if_user_exists();
    int get_new_users_id();


public:

    User_Manager(string users_file_name) : users_file(users_file_name){

        logged_users_id = 0;
        users = users_file.load_users_from_file(); // in constructors body i can set users as vector which will be loaded via object users_file and its method load_users_from_file()

    };
    void user_registration();
    int user_login();
    void user_logout();
    int get_new_id_for_user();
    bool check_if_user_is_logged();
    int get_logged_users_id();
    void change_users_password();



};


#endif // USER_MANAGER_H
