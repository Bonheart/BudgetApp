#ifndef USERS_FILE_H
#define USERS_FILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "Helpful_Methods.h"

using namespace std;


class Users_File{

public:

    Users_File(string users_file_name){};
    void add_user_to_file(User user);
    vector <User> load_users_from_file();
    void change_password_in_file(int loggedUserId, string newUserPassword);

};


#endif // USERS_FILE_H
