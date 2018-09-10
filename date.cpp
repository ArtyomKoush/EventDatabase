#include "date.h"

#include <string>
#include <algorithm>

using namespace std;

bool IsDashSymbol(char s) {
    return s == '-';
}

Date ParseDate(istream& is) {
    string date_string, year_string, month_string, day_string;
    int year, month, day;

    is >> date_string;

    auto it1 = find_if(date_string.begin(), date_string.end(), IsDashSymbol);
    year_string = {date_string.begin(), it1};

    auto it2 = find_if(++it1, date_string.end(), IsDashSymbol);
    month_string = {it1, it2};
    day_string = {++it2, date_string.end()};

    year = stoi(year_string);
    month = stoi(month_string);
    day = stoi(day_string);

    Date date(year, month, day);

    return date;
}
