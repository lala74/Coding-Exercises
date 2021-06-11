#include <stdio.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string contactFileName = "contacts.csv";
const char separator = ';';

struct contactType {
    string name;
    string phone;
    string email;
    string address;
};

enum returnType {
    OK = 0,
    CONTACT_EXISTED = 1,
    INVALID_INPUT = 2,
    CONTACT_NOT_FOUND = 3,
    CONTACT_NOT_DELETED = 4,
    CONTACT_NOT_EDITED = 5,
};

// Main function
returnType add_new_contact_to_file(string fileName, contactType contact);
returnType list_all_contact_in_file(string fileName);
contactType search_contact_in_file(string fileName, string name, string phone);
returnType delete_contact_in_file(string fileName, string name, string phone, bool silent);
returnType edit_contact_in_file(string fileName, string name);

// Some small function
contactType convert_vector_to_contact_type(vector<string> v);
string convert_vector_to_string(vector<string> v);
string convert_contact_type_to_string(contactType contact);

// Edit function
std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

void clean_stdin(void)
{
    int c;
    do {
        c = cin.get();
    } while(c != '\n' && c != EOF);
}

// Menu function
char get_choice(string getChoiceString, vector<char> options)
{
    char choice;
    bool ok = false;
    while(!ok) {
        cout << getChoiceString;
        cin >> choice;
        if(find(options.begin(), options.end(), choice) != options.end()) {
            ok = true;
        } else {
            cout << "Wrong choice" << endl;
            ok = false;
        }
    }
    clean_stdin();
    return choice;
}

void wait_for_enter()
{
    cout << '\n';
    cout << "Press Enter to continue" << endl;
    cin.get();
}

void menu_add_new_contact()
{
    contactType contact;

    cout << "Please type name: ";
    getline(cin, contact.name);
    cout << "Please type phone: ";
    getline(cin, contact.phone);
    cout << "Please type email : ";
    getline(cin, contact.email);
    cout << "Please type address: ";
    getline(cin, contact.address);

    returnType status = add_new_contact_to_file(contactFileName, contact);

    if(status == OK) {
        cout << "Contact added !!" << endl;
    } else {
        cout << "Contact is not added" << endl;
    }
    wait_for_enter();
}

void menu_list_all_contacts()
{
    cout << bold_on << "CONTACT LIST" << bold_off << endl;
    cout << "------------------------------" << endl;
    list_all_contact_in_file(contactFileName);
    wait_for_enter();
}

void menu_search_for_contact()
{
    string name, phone;

    cout << "Type name or phone number to search" << endl;
    cout << "Press leave empty [Enter] if a field does not important" << endl;
    cout << "Please type name: ";
    getline(cin, name);
    cout << "Please type phone: ";
    getline(cin, phone);

    cout << '\n';
    contactType contactFound = search_contact_in_file(contactFileName, name, phone);
    if(contactFound.name == "") {
        cout << "Contact not found !!" << endl;
    } else {
        cout << bold_on << "Found contact" << bold_off << endl;
        cout << "------------------------------" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;
    }
    wait_for_enter();
}

void menu_edit_contact()
{
    string name;

    cout << "Type contact's name to edit" << endl;
    cout << "Please type name: ";
    getline(cin, name);

    returnType status = edit_contact_in_file(contactFileName, name);
    if(status == OK) {
        cout << "Contact edited !!" << endl;
    } else {
        cout << "Contact not edited !!" << endl;
    }
    wait_for_enter();
}

void menu_delete_contact()
{
    string name, phone;

    cout << "Type name or phone number to delete" << endl;
    cout << "Press leave empty [Enter] if a field does not important" << endl;
    cout << "Please type name: ";
    getline(cin, name);
    cout << "Please type phone: ";
    getline(cin, phone);

    returnType status = delete_contact_in_file(contactFileName, name, phone, false);
    if(status == OK) {
        cout << "Contact deleted !!" << endl;
    } else {
        cout << "Contact not deleted !!" << endl;
    }
    wait_for_enter();
}

void clear_screen()
{
    cout << string(20, '\n');
}

void start_menu()
{
    cout << string(3, '\n');
    cout << bold_on << "MAIN MENU" << bold_off << endl;
    cout << "==============================" << endl;
    cout << "[1] Add a new contact" << endl;
    cout << "[2] List all contacts" << endl;
    cout << "[3] Search for contact" << endl;
    cout << "[4] Edit a contact" << endl;
    cout << "[5] Delete a contact" << endl;
    cout << "[q] Quit" << endl;
    cout << "==============================" << endl;

    bool ok = false;
    vector<char> options = {'1', '2', '3', '4', '5', 'q'};
    char choice;

    choice = get_choice("Enter the choice: ", options);

    if(choice == '1') {
        clear_screen();
        menu_add_new_contact();
    } else if(choice == '2') {
        clear_screen();
        menu_list_all_contacts();
    } else if(choice == '3') {
        clear_screen();
        menu_search_for_contact();
    } else if(choice == '4') {
        clear_screen();
        menu_edit_contact();
    } else if(choice == '5') {
        clear_screen();
        menu_delete_contact();
    } else if(choice == 'q') {
        cout << "Exit !!" << endl;
        exit(0);
    }
}

string data[6][4] = {{"My heo", "01216760247", "giftchanh@gmail.com", "1 Che Lan Vien, Taiwan"},
                     {"Minh Duc", "0777117497", "laminhduc0704@gmail.com", "1 Che Lan Vien, Vietnam"},
                     {"Gift", "01212760422", "lequyhamy@gmail.com", "1 Che Lan Vien, HCM"},
                     {"Mon", "01146560247", "giftchanh123@gmail.com", "1 Che Lan Vien, Da Nang"},
                     {"Mon heu", "02144567247", "hamylequy123@gmail.com", "1 Che Lan Vien, Da Lat"},
                     {"My heo", "01216760247", "giftchanh@gmail.com", "1 Che Lan Vien, Taiwan"}};

int main()
{
    contactType contact;
    cout << "************ Init" << endl;
    for(int i = 0; i < 6; i++) {
        contact.name = data[i][0];
        contact.phone = data[i][1];
        contact.email = data[i][2];
        contact.address = data[i][3];
        add_new_contact_to_file(contactFileName, contact);
    }

    while(1) {
        start_menu();
    }
    return 0;
}

returnType add_new_contact_to_file(string fileName, contactType contact)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, contact.name, contact.phone);
    if(contactFound.name != "") {
        cout << "Contact existed" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;
        return CONTACT_EXISTED;
    }

    if(contact.name == "") {
        cout << "Contact name must not be empty" << endl;
        return INVALID_INPUT;
    }

    fstream contactFile(contactFileName, ios::app);
    if(contactFile.good()) {
        contactFile << contact.name << separator;
        contactFile << contact.phone << separator;
        contactFile << contact.email << separator;
        contactFile << contact.address << "\n";
    }
    contactFile.close();
    return OK;
}

returnType list_all_contact_in_file(string fileName)
{
    fstream contactFile(contactFileName, ios::in);
    string lineRaw, word;
    vector<string> wordsInLine;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            std::stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            cout << convert_vector_to_string(wordsInLine);
            cout << '\n';
        }
    }
    contactFile.close();
    return OK;
}

contactType search_contact_in_file(string fileName, string name, string phone)
{
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;
    contactType contactFound;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            std::stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            if((wordsInLine[0] == name) || (wordsInLine[1] == phone)) {
                contactFound = convert_vector_to_contact_type(wordsInLine);
                break;
            }
        }
    }
    contactFile.close();
    return contactFound;
}

returnType edit_contact_in_file(string fileName, string name)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, name, "");
    if(contactFound.name == "") {
        cout << "No contact matches your name" << endl;
        return CONTACT_NOT_FOUND;
    }

    cout << '\n';
    cout << bold_on << "Found contact" << bold_off << endl;
    cout << "------------------------------" << endl;
    cout << convert_contact_type_to_string(contactFound) << endl;

    char choice;
    choice = get_choice("Do you want to edit this contact [y/n]: ", {'y', 'n'});
    if(choice == 'y') {
        delete_contact_in_file(fileName, contactFound.name, "", true);

        contactType newContact = contactFound;
        string user_input;
        cout << "\nPlease enter new information" << endl;
        cout << "Press leave empty [Enter] if a field does not important" << endl;
        cout << "Phone: ";
        getline(cin, user_input);
        if(user_input != "") newContact.phone = user_input;

        cout << "Email: ";
        getline(cin, user_input);
        if(user_input != "") newContact.email = user_input;

        cout << "Address: ";
        getline(cin, user_input);
        if(user_input != "") newContact.address = user_input;

        return add_new_contact_to_file(fileName, newContact);
    } else {
        return CONTACT_NOT_EDITED;
    }
    return OK;
}

returnType delete_contact_in_file(string fileName, string name, string phone, bool silent)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, name, "");
    if(contactFound.name == "") {
        cout << "No contact matches your name" << endl;
        return CONTACT_NOT_FOUND;
    }

    const string tempFileName = "temp.csv";
    fstream tempFile(tempFileName, ios::out);
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            std::stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            if((wordsInLine[0] == name) || (wordsInLine[1] == phone)) {

                if(choice == 'y') {
                    continue;
                } else {
                    return CONTACT_NOT_DELETED;
                }
            } else {
                tempFile << lineRaw << '\n';
            }
        }
    }
    tempFile.close();
    contactFile.close();
    remove(contactFileName.c_str());
    rename(tempFileName.c_str(), contactFileName.c_str());
    return OK;
}

// Smal functions
contactType convert_vector_to_contact_type(vector<string> v)
{
    contactType contact;

    contact.name = v[0];
    contact.phone = v[1];
    contact.email = v[2];
    contact.address = v[3];
    return contact;
}

string convert_contact_type_to_string(contactType contact)
{
    stringstream result;

    result << "Name: " << setw(20) << left << contact.name;
    result << "Phone: " << setw(15) << left << contact.phone;
    result << "Email: " << setw(30) << left << contact.email;
    result << "Address: " << setw(50) << left << contact.address;
    return result.str();
}

string convert_vector_to_string(vector<string> v)
{
    return convert_contact_type_to_string(convert_vector_to_contact_type(v));
}
