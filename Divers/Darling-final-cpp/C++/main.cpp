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

typedef vector<contactType> contactListType;
contactType search_contact_in_file(string fileName, string name, string phone);
int delete_contact_in_file(string fileName, string name, string phone);

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

int add_new_contact_to_file(string fileName, contactType contact)
{
    contactType contactFound;
    contactFound = search_contact_in_file(fileName, contact.name, contact.phone);
    if(contactFound.name != "") {
        cout << "There is already this contact in file" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;
        return 1;
    }

    if(contact.name == "") {
        cout << "Contact name must not be empty" << endl;
        return 2;
    }

    fstream contactFile(contactFileName, ios::app);
    if(contactFile.good()) {
        contactFile << contact.name << separator;
        contactFile << contact.phone << separator;
        contactFile << contact.email << separator;
        contactFile << contact.address << "\n";
    }
    contactFile.close();
    return 0;
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
    return 0;
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
    } else {
        cout << "Found contact" << endl;
        cout << convert_contact_type_to_string(contactFound) << endl;
        cout << "Do you want to edit this contact [y/n]: ";
        char answer; 
        cin >> answer;
        if (answer == 'y') {
            delete_contact_in_file(fileName, contactFound.name, "");
            contactType newContact = contactFound;
            cout << "Please enter new information" << endl;
            cout << "Phone: ";
            cin >> newContact.phone; 
            add_new_contact_to_file(fileName, newContact);
        }
    }
    return 0;
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
    return 0;
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
    cout << "************ Add some contact to file" << endl;
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
    edit_contact_in_file(contactFileName, "Mon heu");
    list_all_contact_in_file(contactFileName);

    return 0;
}

