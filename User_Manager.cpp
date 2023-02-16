#include "User_Manager.h"
#include "windows.h"


void User_Manager::user_registration() {

    User user = insert_new_users_data();

    users.push_back(user);
    users_file.add_user_to_file(user);

    cout << "Account registered correctly" << endl;

}

User User_Manager::insert_new_users_data() {


    User user;

    user.set_users_id(get_new_id_for_user());

    string users_name;
    cout << "Enter name: ";
    users_name = Helpful_Methods::load_line();
    users_name = Helpful_Methods::change_first_letter_to_big_one(users_name);
    user.set_users_name(users_name);

    string users_surname;
    cout << "Enter surname: ";
    users_surname = Helpful_Methods::load_line();
    users_surname = Helpful_Methods::change_first_letter_to_big_one(users_surname);
    user.set_users_surname(users_surname);

    string users_login;
    //  do {
    cout << "Enter login: ";
    users_login = Helpful_Methods::load_line();
    user.set_users_login(users_login);

    //  } while (czyIstniejeLogin(uzytkownik.pobierz_login()) == true);

    string users_password;
    cout << "Enter password: ";
    users_password = Helpful_Methods::load_line();
    user.set_users_password(users_password);

    return user;


}

int User_Manager::get_new_id_for_user() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().get_users_id() + 1;

}

int User_Manager::user_login() {

    string login = "", password = "";
    unsigned int i = 0;

    cout << endl << "Enter login: ";
    login = Helpful_Methods::load_line();

    while (i < users.size()) {

        if (users[i].get_users_login() == login) {

            for (int attempts_number = 3; attempts_number > 0; attempts_number--) {

                cout << "Enter your password. Attempts left: " << attempts_number << " ";
                password = Helpful_Methods::load_line();

                if (users[i].get_users_password() == password) {

                    cout << endl << "Welcome, " << users[i].get_users_name() <<" "<< users[i].get_users_surname() << endl << endl;
                    Sleep(2000);
                    logged_users_id = users[i].get_users_id();
                    return logged_users_id;
                }
            }

            system("cls");
            cout << "Entered wrong password 3 times. Sorry." << endl;
            Sleep(2000);

            for (int i = 3; i > 0; i--) {
                system ("cls");
                cout << "Exiting in: " << i << endl;
                Sleep(1000);
            }
            exit(0);
        }
        i++;
    }
    cout << "User not found. Try again" << endl << endl;
    system("pause");
    return 0;
}

bool User_Manager::check_if_user_is_logged(){

    if(logged_users_id > 0)
       return true;

    else
        return false;

}


int User_Manager::get_logged_users_id(){

    return logged_users_id;
}

void User_Manager::user_logout(){

    logged_users_id = 0;

}
