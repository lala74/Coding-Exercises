#include <stdio.h>

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

enum returnValue {
    OK = 0,
    CONTACT_EXISTED = 1,
    INVALID_INPUT = 2,
    CONTACT_NOT_FOUND = 3,
};

// Main function
int add_new_contact_to_file(string fileName, contactType contact);
int list_all_contact_in_file(string fileName);
contactType search_contact_in_file(string fileName, string name, string phone);
int delete_contact_in_file(string fileName, string name, string phone);
int edit_contact_in_file(string fileName, string name);

// Menu function
bool verify_choice(char choice, vector<char> options)
{
    if (find(options.begin(), options.end(), choice) != options.end()) {
        return true;
    }
    return false;
}
void print_menu(){
    cout << "\e[1mMAIN MENU\e[0m" << endl;
    cout << "==============================" << endl;
    cout << "[1] Add a new contact" << endl;
    cout << "[2] List all contacts" << endl;
    cout << "[3] Search for contact" << endl;
    cout << "[4] Edit a contact" << endl;
    cout << "[5] Delete a contact" << endl;
    cout << "==============================" << endl;
}
void start_menu()
{
    print_menu();
    bool ok = false;
    while(!ok) {
        cout << "Enter the choice: ";
        char choice;
        vector<char> options = { '1', '2', '3', '4' };
        cin >> choice;
        if (verify_choice(choice, options)) {
            cout << "Right choice" << endl;
            ok = true;
        } else {
            cout << "Wrong choice" << endl;
            ok = false;
        }
    }
}

// Some small function
contactType convert_vector_to_contact_type(vector<string> v);
string convert_vector_to_string(vector<string> v);
string convert_contact_type_to_string(contactType contact);

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

    cout << "************ List all contact" << endl;
    list_all_contact_in_file(contactFileName);

    cout << "************ Search contact in file" << endl;
    cout << convert_contact_type_to_string(search_contact_in_file(contactFileName, "My heo", "01216760247")) << endl;

    cout << "************ Delete contact in file" << endl;
    delete_contact_in_file(contactFileName, "My heo", "01216760247");
    list_all_contact_in_file(contactFileName);

    cout << "************ Edit contact in file" << endl;
    /* edit_contact_in_file(contactFileName, "Mon heu"); */
    /* list_all_contact_in_file(contactFileName); */
    start_menu();

    return 0;
}

int add_new_contact_to_file(string fileName, contactType contact)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, contact.name, contact.phone);
    if(contactFound.name != "") {
        cout << "There is already this contact in file" << endl;
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

int list_all_contact_in_file(string fileName)
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

int edit_contact_in_file(string fileName, string name)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, name, "");
    if(contactFound.name == "") {
        cout << "No number matches your contact" << endl;
        return CONTACT_NOT_FOUND;
    } else {
        cout << "Found contact" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;
        cout << "Do you want to edit this contact [y/n]: ";
        char answer;
        cin >> answer;
        if(answer == 'y') {
            delete_contact_in_file(fileName, contactFound.name, "");
            contactType newContact = contactFound;
            cout << "Please enter new information" << endl;
            cout << "Phone: ";
            cin >> newContact.phone;
            return add_new_contact_to_file(fileName, newContact);
        }
    }
    return OK;
}

int delete_contact_in_file(string fileName, string name, string phone)
{
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
