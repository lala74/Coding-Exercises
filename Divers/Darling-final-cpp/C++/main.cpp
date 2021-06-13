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

// Menu functions
void start_menu();
void menu_add_new_contact();
void menu_list_all_contacts();
void menu_search_for_contact();
void menu_edit_contact();
void menu_delete_contact();
void menu_clean_contact_list();

// Main functions
returnType add_new_contact_to_file(string fileName, contactType contact);
returnType list_all_contact_in_file(string fileName);
contactType search_contact_in_file(string fileName, string name, string phone);
returnType delete_contact_in_file(string fileName, string name, bool silent);
returnType edit_contact_in_file(string fileName, string name);
returnType clean_contact_in_file(string fileName, uint* contactDeletedNumber);

// Some small function
char get_choice(string getChoiceString, vector<char> options);
contactType convert_vector_to_contact_type(vector<string> v);
string convert_vector_to_string(vector<string> v);
string convert_contact_type_to_string(contactType contact);
bool is_vector_has_empty_element(vector<string> v);

// Edit function
ostream& bold_on(ostream& os);
ostream& bold_off(ostream& os);
void clean_stdin(void);
void wait_for_enter();
void clear_screen();

int main()
{
    while(1) {
        start_menu();
    }
    return 0;
}

/*****************************************************/
/* Menu functions */
/*****************************************************/
/*
 * Print all contact list's feature and execute the user's choice
 */
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
    cout << "[6] Clean contact list (deleted all contacts with at least one empty field)" << endl;
    cout << "[q] Quit" << endl;
    cout << "==============================" << endl;

    char choice;
    choice = get_choice("Enter the choice: ", {'1', '2', '3', '4', '5', '6', 'q'});

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
    } else if(choice == '6') {
        clear_screen();
        menu_clean_contact_list();
    } else if(choice == 'q') {
        cout << "Exit !!" << endl;
        exit(0);
    }
}

/*
 * Get all necessary inputs from user like name, phone, email, address and call add_new_contact_to_file function
 * Check the return to see whether the contact is added succesfullyt
 */
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

/*
 * Print the necessary text and call list_all_contact_in_file function
 */
void menu_list_all_contacts()
{
    cout << bold_on << "CONTACT LIST" << bold_off << endl;
    cout << "------------------------------" << endl;
    list_all_contact_in_file(contactFileName);
    wait_for_enter();
}

/*
 * Get search name or phone from user and call search_contact_in_file function
 * Check the return and print out contact if found
 */
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

/*
 * Get edit name from user and call edit_contact_in_file function
 * Check the return to see whether the contact is edited
 */
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

/*
 * Get delete name from user and call delete_contact_in_file function
 * Check the return to see whether the contact is deleted
 */
void menu_delete_contact()
{
    string name, phone;

    cout << "Type name to delete" << endl;
    cout << "Press leave empty [Enter] if a field does not important" << endl;
    cout << "Please type name: ";
    getline(cin, name);

    returnType status = delete_contact_in_file(contactFileName, name, false);
    if(status == OK) {
        cout << "Contact deleted !!" << endl;
    } else {
        cout << "Contact not deleted !!" << endl;
    }
    wait_for_enter();
}

/*
 * Print out all the necessary text
 * Print the contact after clean (remove all contact with at least one empty field)
 * Print number of deleted contact
 */
void menu_clean_contact_list()
{
    uint contactDeletedNumber = 0;

    if(clean_contact_in_file(contactFileName, &contactDeletedNumber) == OK) {
        cout << bold_on << "CONTACT AFTER CLEAN" << bold_off << endl;
        cout << "------------------------------" << endl;
        list_all_contact_in_file(contactFileName);
        cout << "------------------------------" << endl;
        cout << "Delete " << bold_on << contactDeletedNumber << bold_off << " empty contact(s)" << endl;
    } else {
        cout << "Contact can not clean, strange error" << endl;
    }

    wait_for_enter();
}

/*****************************************************/
/* Main functions */
/*****************************************************/
/*
 * Search contact list to see whether this contact is already existed (base on name)
 * If not, add this contact to file
 */
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

/*
 * Print out all the contact in file
 */
returnType list_all_contact_in_file(string fileName)
{
    fstream contactFile(contactFileName, ios::in);
    string lineRaw, word;
    vector<string> wordsInLine;

    if(contactFile.good()) {
        // If the contact file is ok
        while(getline(contactFile, lineRaw)) {  // read line in contact file
            wordsInLine.clear();                // remove the previous contact elements
            stringstream lineStringStream(lineRaw);
            while(getline(
                lineStringStream, word, separator)) {  // separate all field in a line by a separator and loop to store field to string variable
                wordsInLine.push_back(word);           // store all field to a string vector
            }
            cout << convert_vector_to_string(wordsInLine);  // convert this vector to a more readable string name:xxx   phone:xxx ...
            cout << '\n';
        }
    }
    contactFile.close();
    return OK;
}

/*
 * Read all line of file to search for contact
 * The process is like list_all_contact_in_file
 */
contactType search_contact_in_file(string fileName, string name, string phone)
{
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;
    contactType contactFound;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            if((wordsInLine[0] == name) || (wordsInLine[1] == phone)) {  // Check if this contact matches user expectation
                contactFound = convert_vector_to_contact_type(wordsInLine);
                break;
            }
        }
    }
    contactFile.close();
    return contactFound;  // if contact not found, this variable's fields are null
}

/*
 * Edit a contact in file by delete it and add editted contact to file
 */
returnType edit_contact_in_file(string fileName, string name)
{
    contactType contactFound;
    // Search to see whether this contact is existed
    contactFound = search_contact_in_file(fileName, name, "NULL");
    if(contactFound.name == "") {
        cout << "No contact matches your require !!" << endl;
        return CONTACT_NOT_FOUND;
    }

    cout << '\n';
    cout << bold_on << "Found contact" << bold_off << endl;
    cout << "------------------------------" << endl;
    cout << convert_contact_type_to_string(contactFound) << endl;

    char choice;
    choice = get_choice("Do you want to edit this contact [y/n]: ", {'y', 'n'});  // Confirm that user want to edit this contact
    if(choice == 'y') {
        // Delete this contact
        delete_contact_in_file(fileName, contactFound.name, true);

        contactType newContact = contactFound;  // store the deleted contact
        string user_input;
        cout << "\nPlease enter new information" << endl;
        cout << "Press leave empty [Enter] if a field does not important" << endl;
        cout << "Phone: ";
        getline(cin, user_input);
        if(user_input != "") newContact.phone = user_input;  // if a field is empty, it means user doesn't want to change that field

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

returnType clean_contact_in_file(string fileName, uint* contactDeletedNumber)
{
    const string tempFileName = "temp.csv";
    fstream tempFile(tempFileName, ios::out);
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            if(is_vector_has_empty_element(wordsInLine)) {
                ++(*contactDeletedNumber);
                continue;
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

/*
 * Delete a contact in file by read and store all the contact in contact list except that contact
 * Then save all the read contact to a new file
 * Delete the old contact list file
 * Change the new file name to the same as the old one
 */
returnType delete_contact_in_file(string fileName, string name, bool silent)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, name, "NULL");
    if(contactFound.name == "") {
        cout << "No contact matches your name" << endl;
        return CONTACT_NOT_FOUND;
    }

    char choice;
    if(silent) {
        choice = 'y';
    } else {
        cout << '\n';
        cout << bold_on << "Found contact" << bold_off << endl;
        cout << "------------------------------" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;

        choice = get_choice("Do you want to delete this contact [y/n]: ", {'y', 'n'});
    }

    if(choice == 'y') {
        const string tempFileName = "temp.csv";
        fstream tempFile(tempFileName, ios::out);
        fstream contactFile(contactFileName, ios::in);

        string lineRaw, word;
        vector<string> wordsInLine;

        if(contactFile.good()) {
            while(getline(contactFile, lineRaw)) {
                wordsInLine.clear();
                stringstream lineStringStream(lineRaw);
                while(getline(lineStringStream, word, separator)) {
                    wordsInLine.push_back(word);
                }
                if(wordsInLine[0] == name) { // Check whether this contact is the delete contact 
                    continue;  // found the delete contact, skip is
                } else {
                    tempFile << lineRaw << '\n';  // If not, save the contact to new file
                }
            }
        }

        tempFile.close();
        contactFile.close();
        remove(contactFileName.c_str()); // Remove the old contact list
        rename(tempFileName.c_str(), contactFileName.c_str()); // Change new contact name to the same as the old one
    } else {
        return CONTACT_NOT_DELETED;
    }
    return OK;
}

/*****************************************************/
/* Small functions */
/*****************************************************/
/*
 * Get user choice with expectation value
 * If user choice is out of the options, we will keep getting input until user choice is one of the expectation value
 */
char get_choice(string getChoiceString, vector<char> options)
{
    char choice;
    while(true) {
        cout << getChoiceString;
        cin >> choice;
        if(find(options.begin(), options.end(), choice) != options.end()) {
            break;
        } else {
            cout << "Wrong choice" << endl;
        }
        clean_stdin();
    }
    clean_stdin();
    return choice;
}

contactType convert_vector_to_contact_type(vector<string> v)
{
    contactType contact;
    v.resize(4);

    contact.name = v[0];
    contact.phone = v[1];
    contact.email = v[2];
    contact.address = v[3];
    return contact;
}

/*
 * Contact vector to readable string with field
 */
string convert_contact_type_to_string(contactType contact)
{
    stringstream result;

    result << "Name: " << setw(20) << left << contact.name;
    result << "Phone: " << setw(15) << left << contact.phone;
    result << "Email: " << setw(30) << left << contact.email;
    result << "Address: " << setw(50) << left << contact.address;
    return result.str();
}

bool is_vector_has_empty_element(vector<string> v)
{
    v.resize(4);
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == "") {
            return true;
        }
    }
    return false;
}

string convert_vector_to_string(vector<string> v)
{
    return convert_contact_type_to_string(convert_vector_to_contact_type(v));
}

/*****************************************************/
/* Some edit functions */
/*****************************************************/
ostream& bold_on(ostream& os)
{
    return os << "\e[1m";
}

ostream& bold_off(ostream& os)
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

void wait_for_enter()
{
    cout << '\n';
    cout << "Press Enter to continue" << endl;
    cin.get();
}

void clear_screen()
{
    cout << string(20, '\n');
}

