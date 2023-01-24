#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

const string top = "<!doctype html>\n<html lang=\"en\">\n<head>\n<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU\" crossorigin=\"anonymous\">\n<meta charset=\"utf-8\">\n"
                   "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n<title>Personal Project - Task 3</title>\n</head>\n<body>\n";
const string bottom = "\n</body>\n</html>";

void hero(ofstream &document) {

    string answer;
    document << "<div class=\"px-4 py-2 my-2 text-center\">\n";
    document << "<h1 class=\"display-5 fw-bold\">";

    cout << "Input website name:\n";
    string title;
    getline(cin, title);
    document << title << "</h1>\n";
    document << "<div class=\"col-lg-6 mx-auto\">\n";
    document << "<p class=\"lead mb-4\">";

    cout << "Input website description:\n";
    string description;
    getline(cin, description);
    document << description << "</p>\n";
    document << "<div class=\"d-grid gap-2 d-sm-flex justify-content-sm-center\">\n";

    cout << "Do you want to create main button?:\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    if(answer == "1"){
        document << "<button type=\"button\" class=\"btn btn-primary btn-lg px-4 gap-3\">\n";
        cout << "Input main button text:\n";
        string leftButtonTitle;
        getline(cin, leftButtonTitle);
        document << leftButtonTitle << "</button>\n";
        cout << "Do you want to create secondary button?:\n 1. Yes\n 2. No\n";
        getline(cin, answer);
        if(answer == "1") {
            document << "<button type=\"button\" class=\"btn btn-outline-secondary btn-lg px-4\">\n";
            cout << "Input secondary button text:\n";
            string rightButtonTitle;
            getline(cin, rightButtonTitle);
            document << rightButtonTitle << "</button>\n";
        }
        else{}
    }
    else{}
    document << "</div>\n</div>\n</div>";
}

void navigationBar(ofstream &document) {
    string answer;
    cout << "Do you want to create a navigation bar?:\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    if(answer == "1"){
        document << "<nav class=\"navbar navbar-expand-lg navbar-dark bg-primary\">\n";
        document << "<div class=\"container-fluid\">\n";
        document << "<a class=\"navbar-brand\" href=\"#\">\n";

        string pageTitle;
        cout << "Input website name:\n";
        getline(cin, pageTitle);
        document << pageTitle << "</a>\n";
        document
                << "    <button class=\"navbar-toggler\" type=\"button\" data-bs-toggle=\"collapse\" data-bs-target=\"#navbarNavAltMarkup\" aria-controls=\"navbarNavAltMarkup\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n"
                   "      <span class=\"navbar-toggler-icon\"></span>\n"
                   "    </button>\n";
        document << "<div class=\"collapse navbar-collapse\" id=\"navbarNavAltMarkup\">\n";
        document << "<div class=\"navbar-nav\">\n";
        document << "<a class=\"nav-link active\" aria-current=\"page\" href=\"#\">Home page</a>\n";

        string input = "1";
        string navItem;
        string navItemURL;
        while (input == "1") {

            cout << "1. Create a navigation button."<<endl;
            cout << "2. Exit." <<endl;
            cin >> input;
            cin.ignore();
            if (input == "1") {
                cout << "Input navigation button name:" << endl;
                getline(cin, navItem);
                cout << "Input navigation button URL:" << endl;
                getline(cin, navItemURL);
                document << R"(<a target="blank" class="nav-link" href=")" << navItemURL << "\">" << navItem << "</a>\n";
            }else{
                input = "2";
            }
        }

        document << "</div>\n</div>\n</div>\n";
        document << "</nav>\n";
    }
    else{}
    document << "</div>";
}

void tables(ofstream &document) {
    string answer;
    cout << "Do you want to create a table? (Contains first names, last names and a note)\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    int i = 1;
    if (answer == "1") {
        document << "<div class=\"col-sm-8 col-lg-8 col-md-8 col-xs-12 p-3 mx-auto border border-secondary\">\n";
        document << "<table class=\"table\">\n"
                    "   <thead>\n"
                    "       <tr>\n"
                    "           <th scope = \"col\">#</th>\n"
                    "           <th 2scope = \"col\">First</th>\n"
                    "           <th scope = \"col\">Last</th>\n"
                    "           <th scope = \"col\">Note</th>\n"
                    "       </tr>\n"
                    "   </thead>\n";
        while(answer == "1"){
            string name, lastName, note;
            cout << "Do you want to add information about a person to the table?\n 1. Yes\n 2. No\n";
            getline(cin, answer);
            if(answer == "1"){
                cout << "Name?:\n";
                getline(cin, name);
                cout << "Last Name?:\n";
                getline(cin, lastName);
                cout << "Note?:\n";
                getline(cin, note);
                document << "   <tbody>\n"
                            "       <tr>\n"
                            "           <th scope = \"row\">" << to_string(i) << " </th>\n"
                                                                                 "           <td>" << name << "</td>\n"
                                                                                                              "           <td>" << lastName << "</td>\n"
                                                                                                                                               "           <td>" << note << "</td>\n"
                                                                                                                                                                            "       </tr>\n"
                                                                                                                                                                            "   </tbody>\n";
                i++;
            }
            else {}
        }
        document << "</table>\n";
        document << "</div>";
    }
    else {}
}

void forms(ofstream& document) {
    string answer;
    cout << "Do you want to create a login form?:\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    if(answer == "1"){
        document << "<div class=\"col-sm-8 col-lg-8 col-md-8 col-xs-12 p-3 m-2 mx-auto border border-secondary\">\n"
                    "    <form>\n"
                    "        <div class=\"form-group\">\n"
                    "            <label for=\"exampleInputEmail1\">Email address</label>\n"
                    "            <input type=\"email\" class=\"form-control\" id=\"exampleInputEmail1\" aria-describedby=\"emailHelp\" placeholder=\"Enter email\">\n"\
                    "        </div>\n"
                    "        <div class=\"form-group\">\n"
                    "            <label for=\"exampleInputPassword1\">Password</label>\n"
                    "            <input type=\"password\" class=\"form-control\" id=\"exampleInputPassword1\" placeholder=\"Password\">\n"
                    "        </div>\n"
                    "        <div class=\"form-check\">\n"
                    "            <input type=\"checkbox\" class=\"form-check-input\" id=\"exampleCheck1\">\n"
                    "            <label class=\"form-check-label\" for=\"exampleCheck1\">Remember me</label>\n"
                    "        </div>\n"
                    "        <button type=\"submit\" class=\"btn btn-primary\">Submit</button>\n"
                    "    </form>\n"
                    "</div>";
    }
    else{}
}


void lists(ofstream &document) {
    string answer;
    cout << "Do you want to create a list?:\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    if(answer == "1"){
        document << "<div class=\"col-sm-8 col-lg-8 col-md-8 col-xs-12 p-3 m-2 mx-auto\">\n"
                    "    <ul class=\"list-group\">";
        while(answer == "1") {
            string listInput;
            cout << "Do you want to add a line into the list?\n 1. Yes\n 2. No\n";
            getline(cin, answer);
            if(answer == "1"){
                cout << "Input the line:\n";
                getline(cin, listInput);
                document << R"(<a href="#" class="list-group-item list-group-item-action">)" << listInput << "</a>";
            }
            else{}
        }
        document << "    </ul>\n"
                    "</div>";
    }
    else{}
}


void buttons(ofstream &document) {
    string answer;
    cout << "Do you want to create a button group?:\n 1. Yes\n 2. No\n";
    getline(cin, answer);
    if(answer == "1"){
        document << "<div class=\"text-center m-2 mx-auto\">\n"
                    "    <div class=\"btn-group\" role=\"group\" aria-label=\"Basic example\">\n";
        cout << "Name of the first button:\n";
        getline(cin, answer);
        document << R"(        <button type="button" class="btn btn-secondary">)" << answer << "</button>\n";
        cout << "Name of the second button:\n";
        getline(cin, answer);
        document << R"(        <button type="button" class="btn btn-secondary">)" << answer << "</button>\n";
        cout << "Name of the third button:\n";
        getline(cin, answer);
        document << R"(        <button type="button" class="btn btn-secondary">)" << answer << "</button>\n";
        document << "    </div>\n"
                    "</div>";
    }
    else{}
}

void removeFile(bool isNeedToRemove, const string &filename) {
    if (isNeedToRemove)
        remove(filename.c_str());
}


int main() {

    SetConsoleOutputCP(CP_UTF8);
    ofstream file;

    removeFile(true, "index.html");

    file.open("index.html", ios::app);
    file << top;

    navigationBar(file);
    hero(file);
    buttons(file);
    forms(file);
    lists(file);
    tables(file);

    file << bottom;
    file.close();

    ShellExecute(nullptr, "open", "index.html", nullptr, nullptr, SW_SHOWNORMAL);

    return 0;
}