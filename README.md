# EventDatabase

This is a course project for the C++ Yellow Belt course (https://www.coursera.org/learn/c-plus-plus-yellow).

The main task of this project was to implement database that works with pairs (**_date_**, **_event_**) and can perform operations like adding new records, printing existing records, searching for a specific record, deliting existing record.

# Programm interface

**Add _date event_**

Adds new pair (**_date, event_**) into the database. On the same date, many different events can occur. The same events that occurred on the same day won't be saved twice.

**_date_** field should have format «_Year-Month-Day_». After the date there must necessarily be a space separating it from the event. Examples of the correct dates: **2017-11-07, 0-2-31**.

The rest of the line in the **Add** command sets the event. Event name can contain spaces, but can't contain quote character (").

Example: **Add 2017-11-07 big sport event**

**Del _condition_**

Delets all records from the database that satisfy the **_condition_** and output the amount **_N_** of deleted records in format «**Removed _N_ entries**». If there's no condition the whole database will be cleared.

Example:

Input
```
Add 2017-06-01 1st of June
Add 2017-07-08 8th of July
Add 2017-07-08 Someone's birthday
Del date == 2017-07-08
```

Output
```
Removed 2 entries
```
**Print**

Outputs all pairs (_date, event_) that are currently stored in the database. Pairs will be printed one by one per line. They will be sorted by date in ascending order. Events within a single date will be printed in the order of the addition (except already deleted ones and attempts to add duplicates). All dates will be printed in the format **YYYY--MM--DD**.

Example:

Input
```
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-1-1 New Year
Add 2017-1-1 New Year
Print
```

Output
```
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
```

**Find _condition_**

Outputs all pairs (_date, event_) that are currently stored in the database and satisfy the **_condition_**. The output format is similar to the **Print** command. A search with an empty condition is equivalent to the **Print** command. At the end programm will ouput string **Found _N_ entries** where **_N_** is the amount of found pairs.

Example:

Input
```
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-01-01 New Year
Find event != "working day"
Add 2017-05-09 Holiday
```

Output
```
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
Found 3 entries
```

**Last _date_**

Outputs the last of the events that happened to the date **_date_**. If the **_date_** is the erliest of all dates that are currently stored in the database than «**No entries**» line will be printed.

Example:

Input
```
Add 2017-01-01 New Year
Add 2017-03-08 Holiday
Add 2017-01-01 Holiday
Add 2017-01-01 Birthday
Last 2016-12-31
Last 2017-01-01
Last 2017-06-01
```

Output
```
No entries
2017-01-01 Birthday
2017-03-08 Holiday
```

# Conditions in commands

The conditions in the **Find** and **Del** commands impose certain restrictions on dates and events, for example:

- **Find date < 2017-11-06** — find all the events that happened before November 6, 2017;
- **Del event != "holiday"** — delete all the events from the database except «**holiday**»;
- **Find date >= 2017-01-01 AND date < 2017-07-01 AND event == "sport event"** — find all the «sport event» events that took place in the first half of the 2017;
- **Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")** - delete all the «**holiday**» and «**sport event**» events that happened before 2017.

In commands of both types, the conditions can be empty: all events occur under such conditions.

