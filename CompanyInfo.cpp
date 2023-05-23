#include "CompanyInfo.h"
#include <algorithm>
#include <cctype>
#include <windows.h>
#include "vcpkg/packages/jsoncpp_x86-windows/include/json/json.h"


string CompanyInfo::extendStringLength(string in, int requiredSize, char appendChar) {
    while (in.length() < requiredSize)
        in = in.append({ appendChar });
    return in;
}

string CompanyInfo::StringToLower(string myString) {
    const int length = myString.length();
    //std::transform(myString.begin(), myString.end(), myString.begin(), ::tolower);

    for (int i = 0; i < length; ++i) {
        myString[i] = std::tolower(myString[i]);
    }
    return myString;
}

//copy constructor
CompanyInfo::CompanyInfo(const CompanyInfo& P) {
    CompanyCode = P.CompanyCode;
    //@@@continue rest of fields
    CompanyCode = P.CompanyCode;
    CompanyDescription = P.CompanyDescription;
    CompanyName = P.CompanyName;
    ContactName = P.ContactName;
    TitleOfBusiness = P.TitleOfBusiness;
    Address = P.Address;
    City = P.City;
    ZipCode = P.ZipCode;
    Phone = P.Phone;
    Fax = P.Fax;
    Email = P.Email;
    Website = P.Website;
}

CompanyInfo::CompanyInfo(void) {
}

CompanyInfo::~CompanyInfo(void) {
}

CompanyInfo& CompanyInfo::operator=(const CompanyInfo& rhs) {
    //@@@ fill your code here to grap the values of the rhs into the current instance

    return *this;
}

string& CompanyInfo::operator[](const string& columnName) {
    string tempColumnName;
    tempColumnName = StringToLower(columnName);
    if (tempColumnName == "companycode")
        return CompanyCode;
    if (tempColumnName == "companydescription")
        return CompanyDescription;
    if (tempColumnName == "companyname")
        return CompanyName;
}

bool CompanyInfo::operator==(const CompanyInfo& rhs) const {
    //@@@ fill your code here to compare rhs with the current instance
    //and return true if they are equal in every thing otherwise return false
    return true;
}

bool CompanyInfo::GetInfoFromUser() {
    //CompanyCode, CompanyDescription ,CompanyName, ContactName, TitleOfBusiness,
    cout << "Enter CompanyCode" << endl;
    cin >> CompanyCode;
    cout << "Enter CompanyDescription" << endl;
    cin >> CompanyDescription;
    cout << "Enter CompanyName" << endl;
    cin >> CompanyName;
    cout << "Enter ContactName" << endl;
    cin >> ContactName;
    cout << "Enter TitleOfBusiness" << endl;
    cin >> TitleOfBusiness;
    //Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields
    return true;
}

bool CompanyInfo::WriteLengthIndicatorFields(ostream& outStream) {
    if (!outStream)
        return false;
    int fieldLength;
    int RecordLength;
    RecordLength = CompanyCode.length() + CompanyDescription.length() +
        CompanyName.length() + ContactName.length() + TitleOfBusiness.length() + Address.length() +
        City.length() + ZipCode.length() + Phone.length() + Fax.length() + Email.length() +
        Website.length() + 1;

    fieldLength = CompanyCode.length();
    outStream << RecordLength << "R";
    outStream << fieldLength;
    outStream << CompanyCode;

    fieldLength = CompanyDescription.length();
    outStream << fieldLength;
    outStream << CompanyDescription;

    fieldLength = CompanyName.length();
    outStream << fieldLength;
    outStream << CompanyName;

    fieldLength = ContactName.length();
    outStream << fieldLength;
    outStream << ContactName;

    fieldLength = TitleOfBusiness.length();
    outStream << fieldLength;
    outStream << TitleOfBusiness;

    fieldLength = Address.length();
    outStream << fieldLength;
    outStream << Address;

    fieldLength = City.length();
    outStream << fieldLength;
    outStream << City;

    fieldLength = ZipCode.length();
    outStream << fieldLength;
    outStream << ZipCode;

    fieldLength = Phone.length();
    outStream << fieldLength;
    outStream << Phone;

    fieldLength = Fax.length();
    outStream << fieldLength;
    outStream << Fax;

    fieldLength = Email.length();
    outStream << fieldLength;
    outStream << Email;

    fieldLength = Website.length();
    outStream << fieldLength;
    outStream << Website;

    // Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields DONE
    outStream << endl;
    return true;
}

bool CompanyInfo::readLengthIndicatorFields(istream& inStream) {
    if (!inStream) return false;
    int fieldLength;
    int RecordLength;
    char buf[1000], Temp[10];
    inStream >> RecordLength;
    inStream.ignore();
    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    CompanyCode = buf;
    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    CompanyDescription = buf;
    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    CompanyName = buf;
    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    ContactName = buf;
    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    TitleOfBusiness = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    Address = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    City = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    ZipCode = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    Phone = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    Fax = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    Email = buf;

    inStream >> fieldLength;
    inStream.get(buf, fieldLength + 1);
    Website = buf;
    // Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields

    return true;

    //Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields

    return true;
}

bool CompanyInfo::WriteDelimFields(ostream& outStream, char fieldDelim, char recordDelim) {
    if (!outStream) return false;
    outStream << CompanyCode << fieldDelim;
    outStream << CompanyDescription << fieldDelim;
    outStream << CompanyName << fieldDelim;
    outStream << TitleOfBusiness << fieldDelim;
    outStream << Address << fieldDelim;
    outStream << City << fieldDelim;
    outStream << ZipCode << fieldDelim;
    outStream << Phone << fieldDelim;
    outStream << Fax << fieldDelim;
    outStream << Email << fieldDelim;
    outStream << Website << fieldDelim;
    outStream << endl;
    return true;
}

//read delimited fields
bool CompanyInfo::readDelimFields(istream& inStream, char fieldDelim,
    char recordDelim) {
    string temp;
    if (inStream.bad())
        return false;
    CompanyCode = temp;
    getline(inStream, temp, fieldDelim);
    CompanyDescription = temp;
    getline(inStream, temp, fieldDelim);
    CompanyName = temp;
    getline(inStream, temp, fieldDelim);
    TitleOfBusiness = temp;
    getline(inStream, temp, fieldDelim);
    Address = temp;
    getline(inStream, temp, fieldDelim);
    City = temp;
    getline(inStream, temp, fieldDelim);
    ZipCode = temp;
    getline(inStream, temp, fieldDelim);
    Phone = temp;
    getline(inStream, temp, fieldDelim);
    Fax = temp;
    getline(inStream, temp, fieldDelim);
    Email = temp;
    getline(inStream, temp, fieldDelim);
    Website = temp;
    getline(inStream, temp, fieldDelim);

    getline(inStream, temp, recordDelim);
    return true;
}

//read fixed length fields
bool CompanyInfo::readFixedLengthFields(istream& inStream, char extender, char recordDelim) {
    //fixed length fields
    char buf[1000];
    string temp;

    inStream.get(buf, 100);
    temp = buf;
    CompanyCode = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    CompanyDescription = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    CompanyName = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    ContactName = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    TitleOfBusiness = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    Address = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    City = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    ZipCode = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    Phone = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    Fax = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    Email = temp.erase(temp.find(extender));

    inStream.get(buf, 100);
    temp = buf;
    Website = temp.erase(temp.find(extender));


    //Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields
    getline(inStream, temp, recordDelim);
    return true;
}

bool CompanyInfo::writeFixedLengthFields(ostream& outStream, char extender, char recordDelim) {
    //fixed length fields , 100 byte for each field
    string temp;
    temp += extendStringLength(CompanyCode, 100, extender);
    temp += extendStringLength(CompanyDescription, 100, extender);
    temp += extendStringLength(CompanyName, 100, extender);
    temp += extendStringLength(TitleOfBusiness, 100, extender);
    temp += extendStringLength(Address, 100, extender);
    temp += extendStringLength(City, 100, extender);
    temp += extendStringLength(ZipCode, 100, extender);
    temp += extendStringLength(Phone, 100, extender);
    temp += extendStringLength(Fax, 100, extender);
    temp += extendStringLength(Email, 100, extender);
    temp += extendStringLength(Website, 100, extender);
    //Address,City, ZipCode, Phone, Fax, Email, Website;
    //@@@ continue rest of the fields
    outStream << temp << recordDelim;
    return true;
}


//read json fields- [https://stackoverflow.com/questions/17549906/c-json-serialization]
bool CompanyInfo::readJsonFields(istream& inStream) {
    Json::Value json_CompanyInfo;
    inStream >> json_CompanyInfo;
    this->CompanyCode = json_CompanyInfo["CompanyCode"].asString();
    this->CompanyDescription = json_CompanyInfo["CompanyDescription"].asString();
    this->CompanyName = json_CompanyInfo["CompanyName"].asString();
    //@@@ continue rest of the fields
    return true;
}

//Write json fields- [https://stackoverflow.com/questions/17549906/c-json-serialization]
bool CompanyInfo::writeJsonFields(ostream& outStream) {
    const Json::Value json_CompanyInfo = toJson();
    outStream << json_CompanyInfo;
    return true;
}

ostream& operator<<(ostream& outStream, CompanyInfo& p) {
    //write fixed length fields
    p.writeFixedLengthFields(outStream, '|', '\n');
    return outStream;
}

istream& operator>>(istream& inStream, CompanyInfo& p) {
    //read fixed length fields
    p.readFixedLengthFields(inStream, 0, '\n');
    return inStream;
}

const string& CompanyInfo::getCompanyName() const {
    return CompanyName;
}

Json::Value CompanyInfo::toJson()
{
    Json::Value json_CompanyInfo;
    json_CompanyInfo["CompanyCode"] = CompanyCode;
    json_CompanyInfo["CompanyName"] = CompanyName;
    json_CompanyInfo["CompanyDescription"] = CompanyDescription;
    json_CompanyInfo["TitleOfBusiness"] = TitleOfBusiness;
    json_CompanyInfo["Address"] = Address;
    json_CompanyInfo["City"] = City;
    json_CompanyInfo["ZipCode"] = ZipCode;
    json_CompanyInfo["Phone"] = Phone;
    json_CompanyInfo["Fax"] = Fax;
    json_CompanyInfo["Email"] = Email;
    json_CompanyInfo["Website"] = Website;
    return json_CompanyInfo;
};
