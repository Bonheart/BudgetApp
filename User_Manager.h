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
    int logged_users_id();
    bool check_if_user_exists();
    int get_new_users_id();


public:

    User_Manager(string users_file_name): users_file(users_file_name){};
    void user_registration();
    void user_login();
    void logged_user_password_changing();
    void user_logout();
    int get_logged_users_id();
    bool check_if_user_is_logged();



};


#endif // USER_MANAGER_H
