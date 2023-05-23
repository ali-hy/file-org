#include "CompanyInfoCollection.h"
#include <iostream>
#include <string>
#include <sstream>

int cmp(const string& a, const string& b) {
    for (int i = 0; i < a.length() && i < b.length(); i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        else if (a[i] > b[i]) {
            return 1;
        }
    }
    if (a.length() < b.length()) {
        return -1;
    }
    else if (a.length() > b.length()) {
        return 1;
    }
    return 0;
}

/************************recordOffset_Company methods*********************/
//Writes delimited fields
bool recordOffset_Company::WriteDelimFields(ostream&, char) {
}

//read delimited fields
bool recordOffset_Company::readDelimFields(istream&) {
}

/************************ Index_Company methods *********************/
//Write Collection of recordOffset_Company records
bool Index_Company::writeRecordOffsets(ostream&, char) {}

//read delimited recordOffset_Company records
bool Index_Company::readRecordOffsets(ostream&, char) {
}

//search for collection of Record offsets given a record Key
vector<recordOffset_Company> Index_Company::searchByKey(const string& CompanyName_key) {
}


/************************CompanyInfoCollection methods*********************/
//read delimited fields, use buffering/caching while reading records
bool CompanyInfoCollection::readDelimRecords(istream& inStream) {
    //@@@read from the file 5 MB into a string
    const int _5mb = 5 * 1024 * 1024;
    char buff[_5mb];
    inStream.read(buff, _5mb);
    string str(buff);

    //@@@make sure not to stop at the middle of a record, How??
    if (!inStream.eof()) {
        int startPos = inStream.tellg();
        int i;
        for (i = (int)str.length() - 1; str[i] != recordDelim; i--) {
            if (i < 0) return false;
        }
        str.erase(i);
        inStream.seekg(startPos + i);
    }

    //@@@ copy the data from string to string stream and destroy the string variable
    stringstream dataStream(str);

    //@@@ Loop get record by record and construct an instance of the companyInfo
    //then add to the vector of companyInfo
    while (!dataStream.eof()) {
        CompanyInfo company;
        if (!company.readDelimFields(dataStream))
            break;
        records.push_back(company);
    }

    return true;
}

bool CompanyInfoCollection::writeDelimRecords(ostream& myStream, char delim) {
    stringstream ss;
    const int bufferSize = 50 * 1024 * 1024;
    char buf[bufferSize];
    //write first line that contains header of the columns
    myStream
        << R"( "SIC CODE","SIC DESCRIPTION","COMPANY NAME","CONTACT NAME","title","ADDRESS","CITY","STATE","ZIP","PHONE","FAX","EMAIL","WEB SITE")"
        << endl;
    for (int i = 0; i < records.size(); i++) {
        while (ss.tellg() < bufferSize) {
            records[i].WriteDelimFields(ss, delim);
            i++;
        }
        ss >> buf;
        myStream << buf;
    }
    return true;
}

//get the full information of specific records given a key value for them
vector<CompanyInfo> CompanyInfoCollection::searchByKey(string& companyNameKey) {
    vector<CompanyInfo> result;
    //check within the records first before reading from the disk
    //@@@
    for (const auto& companyInfo : records) {
        if (companyNameKey == companyInfo.getCompanyName()) {
            result.push_back(companyInfo);
        }
    }

    //if not found in records
    //then call Index_Company::searchKey(string companyNameKey)
    //@@@
    if (!result.empty()) {
        return result;
    }

    auto offsets = c_Index.searchByKey(companyNameKey);

    return result;
}
