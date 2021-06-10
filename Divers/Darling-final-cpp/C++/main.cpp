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
string search_contact_in_file(string fileName, string name, string phone);

contactType convert_vector_to_contact_type(vector<string> v) {
    contactType contact;

    contact.name = v[0];
    contact.phone = v[1];
    contact.email = v[2];
    contact.address = v[3];
    return contact;
}

string convert_vector_to_string(vector<string> v)
{
    contactType contact = convert_vector_to_contact_type(v); 
    stringstream result;

    result << "Name: " << setw(20) << left << contact.name; 
    result << "Phone: " << setw(15) << left << contact.phone; 
    result << "Email: " << setw(30) << left << contact.email; 
    result << "Address: " << setw(50) << left << contact.address; 

    /* for(int i = 0; i < contact.size(); i++) { */
        /* result += contact[i] + ' '; */
    /* } */
    return result.str();
}

int add_new_contact_to_file(string fileName, contactType contact)
{
    string contactFound;
    contactFound = search_contact_in_file(fileName, contact.name, contact.phone);
    if (contactFound != "") {
        cout << "There is already this contact in file" << endl;
        cout << contactFound << endl;
        return 1;
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

string search_contact_in_file(string fileName, string name, string phone)
{
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;
    string contactFound;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            std::stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, separator)) {
                wordsInLine.push_back(word);
            }
            if((wordsInLine[0] == name) || (wordsInLine[1] == phone)) {
                contactFound += convert_vector_to_string(wordsInLine);
            }
        }
    }
    contactFile.close();
    return contactFound;
}

int edit_contact_in_file(string fileName, string name)
{
    string contactFound;
    contactFound = search_contact_in_file(fileName, name, "");
    if(contactFound != "") {
        cout << "There is ";
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
            if((wordsInLine[0] == name) && (wordsInLine[1] == phone)) {
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

int main()
{
    contactType contact;
    cout << "************ Add some contact to file" << endl;
    contact.name = "My heo"; contact.phone = "01216760247"; contact.email = "giftchanh@gmail.com"; contact.address = "1 Che Lan Vien, Taiwan";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Minh Duc"; contact.phone = "0777117497"; contact.email = "laminhduc0704@gmail.com"; contact.address = "1 Che Lan Vien, Vietnam";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "My heo"; contact.phone = "0123345456"; contact.email = "giftchanh@gmail.com"; contact.address = "1 Che Lan Vien, Hue";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Gift"; contact.phone = "01212760422"; contact.email = "lequyhamy@gmail.com"; contact.address = "1 Che Lan Vien, HCM";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Mon"; contact.phone = "01146560247"; contact.email = "giftchanh123@gmail.com"; contact.address = "1 Che Lan Vien, Da Nang";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Mon heu"; contact.phone = "02144567247"; contact.email = "hamylequy123@gmail.com"; contact.address = "1 Che Lan Vien, Da Lat";
    add_new_contact_to_file(contactFileName, contact);

    cout << "************ List all contact" << endl;
    list_all_contact_in_file(contactFileName);

    cout << "************ Search contact in file" << endl;
    cout << search_contact_in_file(contactFileName, "My heo", "01216760247") << endl;

    cout << "************ Delete contact in file" << endl;
    delete_contact_in_file(contactFileName, "My heo", "01216760247");
    list_all_contact_in_file(contactFileName);

    return 0;
}

