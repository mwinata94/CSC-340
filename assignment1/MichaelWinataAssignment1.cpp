/**********************************************
 * Program name: MichaelWinataAssignment1.cpp *
 * Author      : Michael Winata               *
 **********************************************/

// Global Library(s)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/************************************************
 * The assignment has three problems, and to    *
 * solve those problems, the program is divided *
 * into five parts: one part for each problem,  *
 * one part to navigate through each problem,   *
 * and the last part is to run the navigation.  *
 ************************************************/
 
// Function Headers

// Part 1: Navigation
void menu(void); // manage the navigation process

void menuSayHi(void); // output a basic greeting
void menuDescribeSelf(void); // output list of options
void menuSayFarewell(void); // output a basic farewell

bool menuRunAnOption(void); // determine 
void menuCallReformatDate(void); // navigate to problem #1
void menuCallMaxTime(void); // navigate to problem #2
void menuCallGetTokenFreq(void); // navigate to problem #3

// Part 2: Problem #1
string ReformatDate(string&); // manage problem #1
void rdSetNewDate(string&, string&); // manage the date formatting
int rdGetSize(const string&); // return the size of a string
void rdSetYear(const string&, string&, const int&); // set the year
void rdSetMonth(const string&, string&, const int&); // set the month
void rdSetDay(const string&, string&, const int&); // set the day
void rdSetDate(string&, string&); // set the new format to the string

// Part 3: Problem #2
string MaxTime(int&, int&, int&, int&); // manage problem #2
void mtSetMaxTime(int&, int&, int&, int&, string&); // manage the maximum time formatting
void mtSortDigitsAsc(int&, int&, int&, int&); // sort the four digits in an ascending order
bool mtInputIsValid(const int&, const int&, const int&, const int&); // check whether inputs are valid or not
void mtSetString(const int&, const int&, const int&, const int&, string&); // manage the time string setting
void mtSetString1200AMto1022PM(const int&, const int&, const int&, const int&, string&); // time string setting branch A
void mtSetString0300AMto1133PM(const int&, const int&, const int&, const int&, string&); // time string setting branch B
void mtSetString0400AMto1155PM(const int&, const int&, const int&, const int&, string&); // time string setting branch C
void mtSetString0400AMto1155PMpartA(const int&, const int&, const int&, const int&, string&); // time string setting branch C part 1 of 3
void mtSetString0400AMto1155PMpartB(const int&, const int&, const int&, const int&, string&); // time string setting branch C part 2 of 3
void mtSetString0400AMto1155PMpartC(const int&, const int&, const int&, const int&, string&); // time string setting branch C part 3 of 3
void mtSetString0600AMto1159PM(const int&, const int&, const int&, const int&, string&); // time string setting branch D
void mtSetString0600AMto1159PMpartA(const int&, const int&, const int&, const int&, string&); // time string setting branch D part 1 of 3
void mtSetString0600AMto1159PMpartB(const int&, const int&, const int&, const int&, string&); // time string setting branch D part 2 of 3
void mtSetString0600AMto1159PMpartC(const int&, const int&, const int&, const int&, string&); // time string setting branch D part 3 of 3
void mtSetStringInTheOrderOf(const int&, const int&, const int&, const int&, string&); // set the time string

//Part 4: Problem #3
struct TokenFreq { // a struct model for problem #3
    TokenFreq(const string&, const int&); // a constructor with two parameters, for each member variables
    string token; // member variable #1
    int freq; // member variable #2
};

ostream& operator<<(ostream&, const vector<TokenFreq>&); // cout operator overloading to output the struct model
vector<TokenFreq> getTokenFreq(string&); // manage problem #3
void getLeastFreqLetter(string&); // manage finding the least frequent letters
void gtfFillTokenList(vector<TokenFreq>&, string&); // manage filling the TokenFreq vector
void gtfFillVector(vector<TokenFreq>&, string&, const int&, const int&);  // manage filling a token into the tokenFreq vector 
void gtfGetToken(const string&, const int&, const int&, string&); // get a token from a paragraph
void gtfFillVectorCheckTail(const int&, const string&, vector<TokenFreq>&, int&, int&); // check the tail of the tokenFreq vector
void gtfFillVectorCheckFromHead(const int&, const string&, vector<TokenFreq>&, int&, int&); // check the tokenFreq from the head
void gtfStoreLetters(const string&, int[]); // store letters into an array
void gtfDisplayLeastFreqLetters(const int[]); // manage displaying the least frequent letters
void gtfGetFirstFreq(const int[], int&, int&, int&, string&); // get the first letter frequency
void gtfStoreLeastFreqLetters(const int[], int&, int&, string&); // get the least frequency letters
void gtfDisplayResult(const int[], int&, int&, string&); // display the least frequent letters

// Part 5: Main Function
int main() {
    menu(); // run the navigation
    return 0;
}

// Function Definitions

void menu() {
    menuSayHi();
    do {
        menuDescribeSelf();
    } while(menuRunAnOption()); // the loop stops depending the user input
    menuSayFarewell();
}

void menuSayHi() {
    cout << "Hi, welcome!\n"; // output a basic greeting
}

void menuDescribeSelf() {
    cout // output the list of menu
        << "\n**********************\n"
        << "*                    *\n"
        << "*        MENU        *\n"
        << "*                    *\n"
        << "*  1.REFORMAT DATE   *\n"
        << "*  2.MAX TIME        *\n"
        << "*  3.WORD VECTOR     *\n"
        << "*  4.CLOSE APP       *\n"
        << "*                    *\n"
        << "**********************\n"
        << "Choose an option: "
    ;
}

void menuSayFarewell() {
    cout << "\nHave a nice day!\n"; // output a basic farewell
}

bool menuRunAnOption() {
    string option; // a variable to store the user input
    getline(cin, option); // get the user input
    if (option == "1")
        menuCallReformatDate();
    else if (option == "2")
        menuCallMaxTime();
    else if (option == "3")
        menuCallGetTokenFreq();
    else if (option == "4")
        return false; // the loop breaker
    else if (option != "4")
        cout << "\nInvalid option :(\n"; // output an error if the user input is invalid
    return true;
}

void menuCallReformatDate() {
    string oldDate; // a variable to store the user input
    cout << "\nEnter date: ";
    getline(cin, oldDate); // get the user input 
    cout << "Calling ReformatDate()\n";
    cout << "Return Value: " << ReformatDate(oldDate) << endl; // output the solution for problem #1
}

void menuCallMaxTime() {
    int A, B, C, D; // variables to store the user inputs
    cout << "\nEnter 1st integer: ";
    cin >> A; // get the user input
    cout << "\nEnter 2nd integer: ";
    cin >> B; // get the user input
    cout << "\nEnter 3rd integer: ";
    cin >> C; // get the user input
    cout << "\nEnter 4th integer: ";
    cin >> D; // get the user input
    cin.ignore(256, '\n'); // to avoid getline() from breaking
    cout << "Calling MaxTime()\n";
    cout << "Return Value: " << MaxTime(A, B, C, D) << endl; // output the solution for problem #2
}

void menuCallGetTokenFreq() {
    string paragraph; // a variable to store the user input
    cout << "\nEnter a paragraph: ";
    getline(cin, paragraph); // get the user input
    cout << "Calling getTokenFreq()\n";
    cout << "Return Value: " << getTokenFreq(paragraph) << endl; // output the solution for problem #3
}

string ReformatDate(string& oldDate) {
    string newDate; // a temporary variable to store the desired output
    rdSetNewDate(oldDate, newDate);
    return oldDate;
}

void rdSetNewDate(string& oldDate, string& newDate) {
    int dateSize = rdGetSize(oldDate); 
    rdSetYear(oldDate, newDate, dateSize); // the year is set first because the desired format has the year first
    rdSetMonth(oldDate, newDate, dateSize); // the month is set second because the desired format has the month second
    rdSetDay(oldDate, newDate, dateSize); // the day is set third because the desired format has the day third
    rdSetDate(oldDate, newDate);
}

int rdGetSize(const string& oldDate) {
    return (oldDate[12] == NULL) ? 11 : 12; // the 'specified' input string is either 11 or 12 characters long
}

void rdSetYear(const string& oldDate, string& newDate, const int& dateSize) {
    newDate += oldDate[dateSize - 3]; // newDate = Y
    newDate += oldDate[dateSize - 2]; // newDate = YY
    newDate += oldDate[dateSize - 1]; // newDate = YYY
    newDate += oldDate[dateSize];     // newDate = YYYY
    newDate += "-";                   // newDate = YYYY-
}

void rdSetMonth(const string& oldDate, string& newDate, const int& dateSize) {
    int month = oldDate[dateSize - 5] + oldDate[dateSize - 6] + oldDate[dateSize - 7]; // the sum of first three characters of a capitalized month is unique
    int monthList [2][12] = {{281,269,288,291,295,301,299,285,296,294,307,268},{1,2,3,4,5,6,7,8,9,10,11,12}}; // an array which matches the unique sum to the order of the month
    for (int i(0),j(0); i < 12 && j < 1; i++)
        if (month == monthList[j][i])
            if (i < 9) // if the order of the month is less than 10
                ((newDate += "0") += char(monthList[++j][i] + 48)) += "-";      // newDate = YYYY-0M-
            else
                ((newDate += "1") += char(monthList[++j][i] % 10 + 48)) += "-"; // newDate = YYYY-1M-
}

void rdSetDay(const string& oldDate, string& newDate, const int& dateSize) {
    newDate += (dateSize == 12) ? oldDate[dateSize - 12] : '0'; // under 'constrained' input, if the day is above 9, then the string would be 12 chars long, else 11.
    newDate += oldDate[dateSize - 11]; // newDate = YYYY-*M-*D
}

void rdSetDate(string& oldDate, string& newDate) {
    oldDate = newDate; // set the new format string
}

string MaxTime(int& A, int& B, int& C, int& D) {
    string maxTime; // a temporary variable to store the maximum time string
    mtSetMaxTime(A, B, C, D, maxTime);
    return maxTime;
}

void mtSetMaxTime(int& A, int& B, int& C, int& D, string& maxTime) {
    mtSortDigitsAsc(A, B, C, D); // sort the digit first to make the validation and setting faster
    if (mtInputIsValid(A, B, C, D)) { // if input is valid
        mtSetString(A, B, C, D, maxTime); // then set the string
    } else { // else
        maxTime = "NOT POSSIBLE"; // output is NOT POSSIBLE
    }
}

void mtSortDigitsAsc(int& A, int& B, int& C, int& D) {
    int digit[10] = {0}; // an array of size ten to complement each digit
    int* result[4] = {&A, &B, &C, &D}; // an array of pointer to store user inputs
    for (int i = 0; i < 4; i++)
        digit[*result[i]]++; // store the input counts into the array
    for (int i(0), j(0); i < 10 && j < 4; i++) // loop from 0 to 9 digits, and store each occurrence
        while(digit[i]-- != 0)
            *result[j++] = i;
}

bool mtInputIsValid(const int& A, const int& B, const int& C, const int& D) {
    if (A > 2) // if all inputs are above 2
        return false; // then inputs are invalid
    else if (B > 5) // if the second smallest input is higher than 5
        return false; // then inputs are invalid
    else if (A == 2 && (B > 3 || C > 5)) // if the smallest input is 2 and the second smallest input is larger than 3 or the third smallest input is larger than 5
        return false; // then inputs are invalid
    return true; // else inputs are valid
}

void mtSetString(const int& A, const int& B, const int& C, const int&D, string& maxTime) { // this setting algorithm is a linear if-else, like a tree with o(n) complexity
    if (D < 3)
        mtSetString1200AMto1022PM(A, B, C, D, maxTime); // branch A
    else if (D == 3)
        mtSetString0300AMto1133PM(A, B, C, D, maxTime); // branch B
    else if (D < 6)
        mtSetString0400AMto1155PM(A, B, C, D, maxTime); // branch C
    else
        mtSetString0600AMto1159PM(A, B, C, D, maxTime); // branch D
    return;
}

void mtSetString1200AMto1022PM(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    mtSetStringInTheOrderOf(D, C, B, A, maxTime);
}

void mtSetString0300AMto1133PM(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (C == 3)
        if (B == 3)
            mtSetStringInTheOrderOf(B, D, C, A, maxTime);
        else
            mtSetStringInTheOrderOf(A, D, C, B, maxTime);
    else
        mtSetStringInTheOrderOf(C, D, B, A, maxTime);
}

void mtSetString0400AMto1155PM(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (C > 3)
        mtSetString0400AMto1155PMpartA(A, B, C, D, maxTime);
    else if (C == 3)
        mtSetString0400AMto1155PMpartB(A, B, C, D, maxTime);
    else
        mtSetString0400AMto1155PMpartC(A, B, C, D, maxTime);
}

void mtSetString0400AMto1155PMpartA(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (A == 2)
        mtSetStringInTheOrderOf(A, B, D, C, maxTime);
    else if (B == 2)
        mtSetStringInTheOrderOf(B, A, D, C, maxTime);
    else if (B < 2)
        mtSetStringInTheOrderOf(B, D, C, A, maxTime);
    else
        mtSetStringInTheOrderOf(A, D, C, B, maxTime);
}

void mtSetString0400AMto1155PMpartB(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (A == 2)
        mtSetStringInTheOrderOf(A, C, D, B, maxTime);
    else if (B == 2)
        mtSetStringInTheOrderOf(B, C, D, A, maxTime);
    else if (B < 2)
        mtSetStringInTheOrderOf(B, D, C, A, maxTime);
    else
        mtSetStringInTheOrderOf(A, D, C, B, maxTime);
}

void mtSetString0400AMto1155PMpartC(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (C == 2)
        mtSetStringInTheOrderOf(C,B, D, A, maxTime);
    else
        mtSetStringInTheOrderOf(C, D, B, A, maxTime);
}

void mtSetString0600AMto1159PM(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (A == 2)
        mtSetString0600AMto1159PMpartA(A, B, C, D, maxTime);
    else if (B == 2)
        mtSetString0600AMto1159PMpartB(A, B, C, D, maxTime);
    else
        mtSetString0600AMto1159PMpartC(A, B, C, D, maxTime);
}

void mtSetString0600AMto1159PMpartA(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (C > 3)
        mtSetStringInTheOrderOf(A, B, C, D, maxTime);
    else
        mtSetStringInTheOrderOf(A, C, B, D, maxTime);
}

void mtSetString0600AMto1159PMpartB(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (C > 5)
        mtSetStringInTheOrderOf(A, D, B, C, maxTime);
    else if (C > 3)
        mtSetStringInTheOrderOf(B, A, C, D, maxTime);
    else
        mtSetStringInTheOrderOf(B, C, A, D, maxTime);
}

void mtSetString0600AMto1159PMpartC(const int& A, const int& B, const int& C, const int&D, string& maxTime) {
    if (B > 2)
        mtSetStringInTheOrderOf(A, D, B, C, maxTime);
    else if (C > 5)
        mtSetStringInTheOrderOf(B, D, A, C, maxTime);
    else if (C > 2)
        mtSetStringInTheOrderOf(B, D, C, A, maxTime);
    else
        mtSetStringInTheOrderOf(C, B, A, D, maxTime);
}

void mtSetStringInTheOrderOf(const int& h1, const int& h2, const int& m1, const int& m2, string& maxTime) {
    maxTime += char(h1 + 48); // maxTime = H
    maxTime += char(h2 + 48); // maxTime = HH
    maxTime += ':';           // maxTime = HH:
    maxTime += char(m1 + 48); // maxTime = HH:M
    maxTime += char(m2 + 48); // maxTime = HH:MM
}

TokenFreq::TokenFreq(const string& s, const int& i) {
    token = s;
    freq = i;
}

ostream& operator<<(ostream& os, const vector<TokenFreq>& v) {
    cout << "\nToken List: {  "; // output opening bracket
    int v_size = v.size(); // store the size of the vector
    for (int i = 0; i < v_size; i++) // loop through each element
        cout << "\n    " << v.at(i).token << " : " << v.at(i).freq << ","; // output each element member variables
    cout << "\b \n}\n"; // remove last comma, and output closing bracket
    return os;
}

vector<TokenFreq> getTokenFreq(string& s) {
    vector<TokenFreq> tokenList;
    gtfFillTokenList(tokenList, s);
    getLeastFreqLetter(s);
    return tokenList;
}

void gtfFillTokenList(vector<TokenFreq>& t, string& s) {
    int wordBeginning(-1), wordEnding(0); // beginning of the word has an offset of -1 to detect the first word
    for(int i = 0; s[i] != 0; i++) // loop through the paragraph
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.') { // if a delimiter is detected
            if (wordBeginning < wordEnding) // token is detected if word ending has a higher position than word beginning
                gtfFillVector(t, s, wordBeginning, wordEnding); // register token
            wordBeginning = i; // set beginning on the delimiter position
        } else {
            wordEnding = i; // set ending on the non-delimiter position
        }
    if (wordBeginning < wordEnding) // check if the last token has not been registered
        gtfFillVector(t, s, wordBeginning, wordEnding); // register last token
}

void gtfFillVector(vector<TokenFreq>& t, string& s, const int& w, const int& e) {
    int t_size = t.size(); // store the size of the vector
    int i(0), j(0); // variables for the for loops
    string token = ""; // a string variable to store the token name
    gtfGetToken(s, w, e, token); // get the token name from the paragraph
    if (token[0] == *"" || token[0] == *" " || token[0] == *"." || token[0] == *",") { // if token is a delimiter
        return; // don't fill the vector
    } else if (t_size == 0) { // if vector is empty
        t.push_back(TokenFreq(token, 1)); // register token immediately
    } else {
        gtfFillVectorCheckTail(t_size, token, t, i, j);
    }
}

void gtfGetToken(const string& s, const int& w, const int& e, string& t) {
    for (int i = w + 1; i <= e; t+=s[i++]); // grab the token name from the paragraph
}

void gtfFillVectorCheckTail(const int& t_size, const string& token, vector<TokenFreq>& t, int& i, int& j) {
    if (t.back().token == token) { // if token name exists
        t.back().freq++; // increment the frequency
    } else if (t.back().token[i] <= token[i]) { // if token name starts with a similar character as vector tail
        for (i = 1; t.back().token[i] == token[i]; i++); // check similarity
        if (t.back().token[i] < token[i]) // if token belongs to the end of the vector
            t.push_back(TokenFreq(token, 1)); // register token as the tail
        else
            gtfFillVectorCheckFromHead(t_size, token, t, i, j); // check from head
    } else {
        gtfFillVectorCheckFromHead(t_size, token, t, i, j); // check from head
    }
}

void gtfFillVectorCheckFromHead(const int& t_size, const string& token, vector<TokenFreq>& t, int& i, int& j) {
    for(i = 0; i < t_size; i++) // start from head
        if (t.at(i).token == token) { // if token exists
            t.at(i).freq++; // increment frequency by one
            i = t_size; // exit loop
        } else {
            for (j = 0; t.at(i).token[j] == token[j]; j++); // check similarity
            if (t.at(i).token[j] > token[j]) { // if token belong to i position
                t.insert(t.begin() + i, TokenFreq(token, 1)); // insert token to i position
                i = t_size; // exit loop
            }
        }
}

void getLeastFreqLetter(string& s) {
    int letters[26] = {0}; // an array of size 26 to store each alphabet frequency
    gtfStoreLetters(s, letters); // store each alphabet frequency
    gtfDisplayLeastFreqLetters(letters); // display the least frequent letters
}

void gtfStoreLetters(const string& s, int l[]) {
    for(int i = 0; s[i] != 0; i++) // loop through the paragraph
        if (s[i] >= 'A' && s[i] <= 'Z') // check if upper case
            l[s[i] - 65]++; // increment corresponding alphabet
        else if (s[i] >= 'a' && s[i] <= 'z') // check if lower case
            l[s[i] - 97]++; // increment corresponding alphabet
}

void gtfDisplayLeastFreqLetters(const int l[]) {
    int smallest(0), i(0), j(0);
    string letters;
    gtfGetFirstFreq(l, smallest, i, j, letters);
    gtfStoreLeastFreqLetters(l, smallest, i, letters);
    gtfDisplayResult(l, smallest, j, letters);
}

void gtfGetFirstFreq(const int l[], int& s, int& i, int& j, string& letters) {
    for (; i < 26 && letters[j] == 0; i++) // loop through 26 elements or until a frequency is received
        if (l[i] != 0) { // if freq is not zero
            s = l[i]; // smallest = freq
            letters = char(i + 97); // letters[j] = char(i + 97)
        }
}

void gtfStoreLeastFreqLetters(const int l[], int& s, int& i, string& letters) {
    for (; i < 26; i++) // loop through 26 elements
        if (l[i] != 0 && l[i] < s) { // if less freq is found
            s = l[i]; // set new freq
            letters = char(i + 97); // reset stack
        } else if (l[i] == s) { // if similar freq is found
            letters += char(i + 97); // push stack
        }
}

void gtfDisplayResult(const int l[], int& s, int& j, string& letters) {
    if (s != 0) { // if least freq is not 0
        cout << "LeastFreqLetters are: "; // display least freq letters
        for (; letters[j] != 0; j++)
            cout << letters[j] << ", ";
        cout << "\b\b \nWith the frequency of: " << s << endl; // remove last comma
    } else {
        cout << "There are no letters detected...\n"; // display no result
    }
}
