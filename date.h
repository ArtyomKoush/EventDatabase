#pragma once

#include <sstream>
#include <set>
#include <tuple>
#include <iomanip>

using namespace std;

class Date {
public:
    Date(const int& y, const int& m, const int& d) : year(y), month(m), day(d) {}
    const int year;
    const int month;
    const int day;
};

Date ParseDate(istream&);

inline ostream& operator << (ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << '-' << setw(2) << date.month << '-' << setw(2) << date.day;

    return os;
}

inline ostream& operator << (ostream& os, const pair<Date, string>& pair) {
    os << pair.first << " " << pair.second;

    return os;
}

inline bool operator==(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) == tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator!=(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) != tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator>(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) > tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator<(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) < tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator>=(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) >= tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator<=(const Date& lhs, const Date& rhs) {
    return tie(lhs.year, lhs.month, lhs.day) <= tie(rhs.year, rhs.month, rhs.day);
}

// Test
void TestDateOutput();
void TestParseDate();