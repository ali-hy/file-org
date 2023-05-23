#ifndef CompanyInfo_H
#define CompanyInfo_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CompanyInfo {
private:
    //declare all data members
    string CompanyCode, CompanyDescription, CompanyName, ContactName, TitleOfBusiness, Address, City, ZipCode, Phone, Fax, Email, WebSite;

public:
    CompanyInfo(void);

    ~CompanyInfo(void);

    //copy constructor
    CompanyInfo(const CompanyInfo&);

    //build set and get for each data member --- NOT needed for this program
    //Assignment operator overloading
    CompanyInfo& operator=(const CompanyInfo& rhs);

    //Comparison operator
    bool operator==(const CompanyInfo& rhs) const;

    //function for getting data from user by asking for field by field
    bool GetInfoFromUser();

    //overload extraction operator for reading from files
    friend istream& operator>>(istream& inStream, CompanyInfo& p);

    //overload insertion operator for writing on files/screen
    friend ostream& operator<<(ostream& outStream, CompanyInfo& p);

    //write delimited fields
    bool WriteDelimFields(ostream&,
        char delim = '|', char recordDelim = '\n');

    //read delimited fields
    bool readDelimFields(istream&,
        char fieldDelim = '|', char recordDelim = '\n');

    //write Length Indicator Fields
    bool WriteLengthIndicatorFields(ostream&);

    //read Length Indicator Fields
    bool readLengthIndicatorFields(istream&);


    //read Fixed length Fields
    bool readFixedLengthFields(istream& inStream, char extender, char recordDelim);

    //Write Fixed Length Fields
    bool writeFixedLengthFields(ostream& outStream, char extender, char recordDelim);

    //write json Buffered fields - [https://stackoverflow.com/questions/17549906/c-json-serialization]
    bool writeJsonFields(ostream&, char);

    //read json fields- [https://stackoverflow.com/questions/17549906/c-json-serialization]
    bool readJsonFields(istream&);

    //overloading of [] operator
    string& operator[](const string& columnName);

    static string extendStringLength(string in, int requiredSize, char appendChar);

    static string StringToLower(string myString);

    bool writeJsonFields(ostream& outStream);

    const string& getCompanyName() const;
};

#endif
