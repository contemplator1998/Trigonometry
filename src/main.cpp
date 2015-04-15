#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

const int NUM_OF_TESTS = 10;

map<string,string> data;


string deleteWhiteSpaces(string& in) {
    string res;
    for(size_t i = 0; i < in.size(); i++)
        if (in[i] != ' ' && in[i] != '\t')
            res += in[i];
    return res;
}

string addWhiteSpaces(string& in) {
    string res;
    for(size_t i = 0; i < in.size(); i++)
        if (in[i] == '+' ||
                in[i] == '-' ||
                in[i] == '*' ||
                in[i] == '/') {
            res += ' ';
            res += in[i];
            res += ' ';
        }
        else
            res += in[i];
    return res;
}

pair<string,string> parse(string& in) {
    pair<string,string> res;
    bool was = false;
    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] == '=')
            was = true;
        else if (!was)
            res.first += in[i];
        else
            res.second += in[i];
    }
    return res;
}

void readData() {
    ifstream f_data("data");
    string line;
    cout << "Loading data";
    while(getline(f_data, line)) {
        pair<string,string> res = parse(line);
        res.first = deleteWhiteSpaces(res.first);
        res.second = deleteWhiteSpaces(res.second);
        data[res.first] = res.second;
        cout << ".";
    }
    cout << " OK" << endl;
}

pair<string,string> getRandom() {
    int ind = rand() % data.size();
    ind = (ind + rand()) % data.size();
    map<string,string>::iterator it = data.begin();
    for (int i = 0; i < ind; i++, it++);
    return *it;
}

void practice() {
    cin.get();
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        pair<string,string> cur = getRandom();
        cout << addWhiteSpaces(cur.first) << " = " << addWhiteSpaces(cur.second);
        cin.get();
    }
}

char ask(string question, pair<char,char> answers) {
    cout << question << " ";
    char responce;
    while(true) {
        cin >> responce;
        if (tolower(responce) != answers.first &&
                tolower(responce) != answers.second) {
            cout << "Excuse me? Please try again." << endl;
        } else {
            responce = tolower(responce);
            break;
        }
    }
    return responce;
}

void test() {
    cin.get();
    int right = 0;
    for (int i = 0; i < NUM_OF_TESTS; i++) {
        pair<string,string> cur = getRandom();
        cout << addWhiteSpaces(cur.first) << " = ";
        string responce;
        getline(cin, responce);
        responce = deleteWhiteSpaces(responce);
        if (responce != cur.second)
            cout << "[NO, RIGHT = " << addWhiteSpaces(cur.second) << "]" << endl;
        else right++;
    }
    cout << "Your score: " << (int)(right / (double)NUM_OF_TESTS * 100.0) << endl;
}

int main() {
    srand(time(0));
    cout << "Hello, Contemplator!" << endl;
    readData();
    while(true) {

        if (ask("Do you want to practice(p/P) or to be tested(t/T)?",
                pair<char,char>('p','t')) == 'p') {
            practice();
        } else {
            test();
        }

        if (ask("Do you want to finish?(y/n)",
                pair<char,char>('y','n')) == 'y')
            break;
    }
    return 0;
}
