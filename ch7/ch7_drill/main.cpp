/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
    This program implements a calculator and does simple arithmetic (+,-,*,/), remainder (%), as well as
    using variables.

    It implements the following grammar:

    Calculate:
        Print
        Quit
        Statement
        Calculate Statement

    Print:
        ";"

    Quit:
        "exit"

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression

    Expression:
        Term
        Expression "+" Term
        Expression "-" Term

    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary

    Primary:
        "(" Expression ")"
        "-" Primary
        "+" Primary
        "sqrt" "(" Expression ")"
        Number
        "pow" "(" Primary "," Primary ")"
        Name

    Name:
        Letter Character

    Character:
        Letter
        Digit
        Character Character

    Number:
        Floating-point literal

*/

#include "../../std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }                  // Token for representing operators
    Token(char ch, double val) :kind(ch), value(val) { }    // Token for representing values of variables
    Token(char ch, string s) :kind(ch), name(s) { }         // Token for representing names of variables
};

class Token_stream {
public:
    Token_stream() :full(0), buffer(0) { }
    Token get();
    void unget(Token t) { buffer = t; full = true; }
    void ignore(char c);
private:
    bool full;
    Token buffer;
};

const char let = 'L';               // Used as a declaration token
const char quit = 'q';              // Quits the calculator if entered by the user
const char print = ';';             // Prints out the result of the computation when entered by a user
const char number = '8';            // Used to represent a number token
const char name = 'a';              // Used to represent the name of a variable as a token
const char root = 'r';              // Used to represent the square root function
const char power = 't';             // Used to represent the power-function
const char equality = '=';          // Used to represent the equality sign as a token for the declaration of variables
const string declkey = "#";         // Keyword for initializing the declaration of variable
const string sqrtkey = "sqrt";      // Keyword for taking the square root of a number
const string powkey = "pow";        // Keyword for raising one number to the power of the other
const string quitkey = "exit";      // Keyword for quitting the calculator

Token Token_stream::get()
// Reads a character from cin and returns the corresponding token
{
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
        // Operator tokens
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case print:
        case quit:
        case equality:
        case root:
        case power:
            return Token(ch);
        // Number tokens
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {	cin.unget();
            double val;
            cin >> val;
            return Token(number, val);
        }
        default:
            // String tokens, for declaring and accessing variables
            if (isalpha(ch) || ch == '#') {
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;    // Names and keywords may consist of letters and digits
                cin.unget();
                if (s == declkey) return Token(let);
                if (s == sqrtkey) return Token(root);
                if (s == powkey) return Token(power);
                if (s == quitkey) return Token(quit);
                return Token(name, s);
            }
            error("Bad token");
    }
}

void Token_stream::ignore(char c)
// Find the next permittable character and flush out the buffer
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch {};
    while (cin >> ch)
        if (ch == c) return;
}

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;     // Table of variables

double get_value(string s)
// Retrieve the value of the variable
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ", s);
}

void set_value(string s, double d)
// Set the value of the variable
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
// Check wether there is a variable with that name
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

Token_stream ts;

double expression();        // We declare expression here, since we need it for primary

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        // For expressions in parantheses
        {	double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case '-':
            // For negative numbers
            return - primary();
        case '+':
            // If someone insists on putting a plus in front of a number
            return primary();
        case number:
            return t.value;
        case root:
        // Compute the square root of an expression
        // Should have the form "sqrt" "(" Expression ")"
        {   t = ts.get();
            if (t.kind != '(') error("'(' expected");
            double d = expression();
            if (d < 0) error("Square root of a negative number");   // Only non-negative numbers are allowed
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return sqrt(d);
        }
        case power:
        // Raise the first number to the power of the second
        // Should have the form "pow" "(" Number "," Number ")"
        {   t = ts.get();
            if (t.kind != '(') error("'(' expected");
            double base = primary();
            char comma {};
            cin >> comma;
            if (comma != ',') error("',' expected");    // Check that we have a comma between the two numbers
            double exponent = primary();
            exponent = narrow_cast<int>(exponent);  // Only integer-valued exponents are allowed
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return pow(base, exponent);
        }
        case name:
            // Retrieve the value of the variable
            return get_value(t.name);
        default:
            error("primary expected");
    }
}

double term()
{
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
            {	double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                break;
            }
            case '%':
            // Computes the floating-point remainder
            {   double d = primary();
                if (d == 0) error("divide by zero");
                left = fmod(left, d);
                break;
            }
            default:
                ts.unget(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default:
                ts.unget(t);
                return left;
        }
    }
}

double declaration()
{
    // Assume we have seen a let
    // Should have the form: "let" name "=" expression
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");          // Check that we have a name
    string var_name = t.name;       // Will be used for the variable name
    if (is_declared(var_name)) error(var_name, " declared twice");      // Check that the variable is new

    Token t2 = ts.get();
    if (t2.kind != equality) error("= missing in declaration of ", var_name);       // Check that after the name comes an equality sign

    double d = expression();        // Get the value of the variable
    names.push_back(Variable(var_name, d));     // Add the variable to the variable list
    return d;       // Return the value of the variable
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
            // For declaring new variables
            return declaration();
        default:
            // For computations
            ts.unget(t);
            return expression();
    }
}

void clean_up_mess()
// Flushes the input stream until we see a specific character
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
// Performs the calculations and handles less-critical errors
{
    while (true)
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t = ts.get();
            if (t.kind == quit) return;
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch (runtime_error& e) {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()
// Starts the calculation loop and handles critical errors
{
    try {
        names.push_back(Variable{"k", 1e3});
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        keep_window_open("~~");
        return 2;
    }
}