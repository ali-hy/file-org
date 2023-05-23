#include <iostream>
#include <fstream>
#include <string>
#include "CompanyInfo.h"

using namespace std;
typedef int integer;

int main(int argc, char* argv[])
{
    int my_var = 9;
    integer h;
    bool ExitProgram = false;
    char UserChoice;
    ifstream readstream;
    ofstream Writestream;
    string filename;

    // Declare an instance of the CompanyInfo class
    CompanyInfo company;

    while (!ExitProgram)
    {
        cout << endl << "Enter 'I' to enter input company information." << endl;
        cout << "Enter 'R' to read company information from a file and display it." << endl;
        cout << "Enter 'B' to read a company information record from a file with buffering." << endl;
        cout << "Enter 'W' to write the saved record into a file." << endl;
        cout << "Enter 'D' to display the saved record on the screen." << endl;
        cout << "Enter 'E' to exit." << endl;
        cin >> UserChoice;
        string ch;

        switch (UserChoice)
        {
        case 'I':
        case 'i':
            // Take in each field one by one into the declared instance of the CompanyInfo class
            cout << "Enter company fields one by one:\n";
            // company.GetInfoFromUser();
            break;

        case 'R':
        case 'r':
            // Get the user choice for field separators
            // Read the company info from a file and display it
            cout << "Enter file name to read from:\n";
            cin >> filename;
            cout << "Enter 'F' for fixed length\n";
            cout << "Enter 'L' for length indicator\n";
            cout << "Enter 'D' for delimiter\n";
            cin >> ch;
            readstream.open(filename.c_str());

            // Processing file records
            if (readstream.good())
            {
                // Skip the first line that contains the header of the columns
                getline(readstream, filename, '\n');
                if (ch == "F" || ch == "f")
                    readstream >> company;
                else if (ch == "L" || ch == "l")
                {
                    if (company.readLengthIndicatorFields(readstream) == true)
                        cout << "Successful reading";
                    else
                        cout << "Unsuccessful reading";
                }
                else
                {
                    if (company.readDelimFields(readstream) == true)
                        cout << "Successful reading";
                    else
                        cout << "Unsuccessful reading";
                }
                readstream.close();
            }
            break;

        case 'B':
        case 'b':
            // Get the user choice for field separators
            // Read the company info from a file and display it
            cout << "Enter file name to read from:\n";
            cin >> filename;
            // Process file records
            break;

        case 'W':
        case 'w':
            // Get the user choice for field separators
            // Write the company info to a file
            cout << endl << "Enter file name to write to:\n";
            cin >> filename;
            cout << "Enter 'F' for fixed length\n";
            cout << "Enter 'L' for length indicator\n";
            cout << "Enter 'D' for delimiter\n";
            cin >> ch;
            Writestream.open(filename.c_str());
            // Processing file records
            if (Writestream.good())
            {
                // Write the first line that contains the header of the columns
                Writestream << "\"SIC CODE\",\"SIC DESCRIPTION\",\"COMPANY NAME\",\"CONTACT NAME\",\"title\",\"ADDRESS\",\"CITY\",\"STATE\",\"ZIP\",\"PHONE\",\"FAX\",\"EMAIL\",\"WEB SITE\"" << endl;
                if (ch == "F" || ch == "f")
                    Writestream << company;
                else if (ch == "L" || ch == "l")
                {
                    if (company.WriteLengthIndicatorFields(Writestream) == true)
                        cout << "Successful writing";
                    else
                        cout << "Unsuccessful writing";
                }
                else
                {
                    if (company.WriteDelimFields(Writestream, '|') == true)
                        cout << "Successful writing";
                    else
                        cout << "Unsuccessful writing";
                }
                Writestream.close();
            }
            break;

        case 'D':
        case 'd':
            cout << "Company information:" << endl;
            cout << company["CompanyCode"] << endl;
            cout << company["CompanyDescription"] << endl;
            cout << company["CompanyName"] << endl;
            break;

        case 'E':
        case 'e':
            ExitProgram = true;
            break;
        }
    }

    system("pause");
    return 0;
}




/*
#include <cstdlib>
     #include <iostream>

     using namespace std;

     int GetInput()
     {
         int choice;
        cin >> choice;
        return choice;
     }

     void DisplayMainMenu()
     {
     cout << "Main Menu\n";
         cout << "Please make your selection\n";
         cout << "1 - Start game\n";
         cout << "2 - Options\n";
         cout << "3 - Quit\n";
         cout << "Selection: ";
     }

     void DisplayOptionsMenu()
     {
         cout << "Options Menu\n";
         cout << "Please make your selection\n";
         cout << "1 - Difficulty\n";
         cout << "2 - Sound\n";
         cout << "3 - Back\n";
         cout << "Selection: ";
     }

     void Options()
     {
        int choice = 0;
        do
        {
            system("cls");
            DisplayOptionsMenu();
            choice = GetInput();
            switch(choice)
            {
                case 1:
                    cout << "difficulty stuff";
                    break;
                case 2:
                    cout << "sound stuff";
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        } while(choice!=3);
     }

     int main(int argc, char *argv[])
     {
         int choice = 0;

         do
         {
            system("cls");
            DisplayMainMenu();
            choice = GetInput();
            switch(choice) {
                    case 1:
                            cout << "Pew pew!\n";
                            break;
                    case 2:
                            Options();
                            break;
                    case 3:
                            cout << "Goodbye!";
                            break;

                    default:
                            break;
                   }
           } while(choice!=3);
         system("PAUSE");
         return EXIT_SUCCESS;
     }
*/