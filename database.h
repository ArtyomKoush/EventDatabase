#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

#include "date.h"

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& os) const;

    template <typename Predicate>
    int RemoveIf(const Predicate& predicate) {
        int result = 0;
        vector<Date> entries_to_delete = {};

        for(auto& entry : entries) {
            vector<string> new_events = {};

            for (const string& event : entry.second) {
                if (predicate(entry.first, event)) {
                    result++;
                    entries_set[entry.first].erase(event);
                } else {
                    new_events.push_back(event);
                }
            }

            if(new_events.size() == 0) {
                entries_to_delete.push_back(entry.first);
            } else {
                entry.second = new_events;
            }
        }

        for (const auto& date : entries_to_delete) {
            entries.erase(date);
            entries_set.erase(date);
        }

        return result;
    }

    template <typename Predicate>
    vector<pair<Date, string>> FindIf(const Predicate& predicate) const {
        vector<pair<Date, string>> result = {};

        for(const auto& entry : entries) {
            for (const string& event : entry.second) {
                if (predicate(entry.first, event)) {
                    result.push_back(make_pair(entry.first, event));
                }
            }
        }

        return result;
    };

    pair<Date, string> Last(const Date& date) const;

private:
    map<Date, vector<string>> entries;
    map<Date, set<string>> entries_set;
};

// Tests
void TestDatabaseAddAndPrint();
void TestDatabaseFind();
void TestDatabaseRemove();
void TestDatabaseLast();