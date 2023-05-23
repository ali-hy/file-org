#ifndef CompanyInfoCollection_H
#define CompanyInfoCollection_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>
#include "CompanyInfo.h"
#include "vcpkg/packages/jsoncpp_x86-windows/include/json/json.h"

using namespace std;

int cmp(const string& a, const string& b);

class recordOffset_Company {
public:
    string companyNameKey;
    int offsetWithinStream;

    //Write delimited fields
    bool WriteDelimFields(ostream&, char);

    //read delimited fields
    bool readDelimFields(istream&);

    //an overloaded operator==; that compares key value
    //with a given target value for a single record
    inline bool operator==(const recordOffset_Company& rhs) const {
        return cmp(companyNameKey, rhs.companyNameKey) == 0;
    }
};

class Index_Company {
private:
    vector<recordOffset_Company> RecordOffsetArray;
public:
    //Write Collection of recordOffset_Company records
    bool writeRecordOffsets(ostream&, char);

    //read Collection of recordOffset_Company records
    bool readRecordOffsets(istream&);

    //search for collection of Record offsets given a record Key
    vector<recordOffset_Company> searchByKey(const string& CompanyName_key);

    bool readRecordOffsets(ostream&, char);
};

class RecordIndex_SicCode {
public:
    string SicCode_key;
    int offsetWithinStream;

    //read delimited fields
    bool WriteDelimFields(ostream&, char);

    //read delimited fields
    bool readDelimFields(istream&);

    //an overloaded operator==; that compares key value
    //with a given target value for a single record
    bool operator==(const RecordIndex_SicCode& rhs) const {
        return cmp(SicCode_key, rhs.SicCode_key) == 0;
    }
};

class Index_SicCode {
private:
    vector<RecordIndex_SicCode> RecordOffsetArray;
public:
    //Write Collection of RecordIndex_SicCode records
    bool writeRecordOffsets(ostream&, char);

    //Read Collection of RecordIndex_SicCode records
    bool readRecordOffsets(istream&);

    //search for collection of Record offset given a record Unique Key
    RecordIndex_SicCode searchKey(string SicCode_key);
};

class CompanyInfoCollection {
private:
    static const char recordDelim = '\n';
    vector<CompanyInfo> records;
    Index_Company c_Index;
    Index_SicCode sicCode_Index;
    fstream fileStream;
public:
    //read delimited fields
    bool writeDelimRecords(ostream& myStream, char delim);

    //read delimited fields
    bool readDelimRecords(istream&);

    //search for collection of Record offsets given a record Key
    vector<CompanyInfo> searchByKey(string& companyNameKey);
};

#endif
