#include <algorithm>

#include "database.h"
#include "date.h"

using namespace std;

void Database::Add(const Date &date, const string &event) {
    const auto insert_it = entries_set[date].insert(event);

    if (insert_it.second) {
        entries[date].push_back(event);
    }
}

void Database::Print(ostream &os) const {
    for (const auto& entry : entries) {
        for (const auto& event : entry.second) {
            os << entry.first << " " << event << endl;
        }
    }
}

pair<Date, string> Database::Last(const Date &date) const {
    const auto lower_b = entries.lower_bound(date);

    if (lower_b == entries.begin() && lower_b -> first != date) {
        throw invalid_argument("No entries");
    }

    if (lower_b -> first == date) {
        const auto last_event_it = prev(lower_b -> second.end());
        return make_pair(lower_b -> first, *last_event_it);
    }

    const auto last_entry_it = prev(lower_b);
    const auto last_event_it = prev(last_entry_it -> second.end());

    return make_pair(last_entry_it -> first, *last_event_it);
}
