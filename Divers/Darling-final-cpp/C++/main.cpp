#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string contactFileName = "contacts.csv";

struct contactType {
    string name;
    string phone;
    string email;
    string address;
};

typedef vector<contactType> contactListType;

void print_vector(vector<string> v)
{
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}

int add_new_contact_to_file(string fileName, contactType contact)
{
    fstream contactFile(contactFileName, ios::app);

    if(contactFile.good()) {
        contactFile << contact.name << ",";
        contactFile << contact.phone << ",";
        contactFile << contact.email << ",";
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
            while(getline(lineStringStream, word, ',')) {
                wordsInLine.push_back(word);
            }
            print_vector(wordsInLine);
            cout << '\n';
        }
    }
    contactFile.close();
    return 0;
}

int search_contact_in_file(string fileName, string name, string phone)
{
    fstream contactFile(contactFileName, ios::in);

    string lineRaw, word;
    vector<string> wordsInLine;

    if(contactFile.good()) {
        while(getline(contactFile, lineRaw)) {
            wordsInLine.clear();
            std::stringstream lineStringStream(lineRaw);
            while(getline(lineStringStream, word, ',')) {
                wordsInLine.push_back(word);
            }
            if((wordsInLine[0] == name) && (wordsInLine[1] == phone)) {
                print_vector(wordsInLine);
                cout << '\n';
            }
        }
    }
    contactFile.close();
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
            while(getline(lineStringStream, word, ',')) {
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
    contactType contact = {.name = "My heo", .phone = "01216760247", .email = "giftchanh@gmail.com", .address = "1 Che Lan Vien"};

    cout << "************ Add some contact to file" << endl;
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Ha My";
    add_new_contact_to_file(contactFileName, contact);
    contact.name = "Gift";
    add_new_contact_to_file(contactFileName, contact);
    cout << "************ List all contact" << endl;
    list_all_contact_in_file(contactFileName);
    cout << "************ Search contact in file" << endl;
    search_contact_in_file(contactFileName, "My heo", "01216760247");
    cout << "************ Delete contact in file" << endl;
    delete_contact_in_file(contactFileName, "My heo", "01216760247");
    list_all_contact_in_file(contactFileName);

    return 0;
}

