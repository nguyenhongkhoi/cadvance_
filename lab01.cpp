#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct CallStat
{
    int count = 0;
    int total_duration = 0;
};

bool isValidPhone(const string &phone)
{
    if (phone.length() != 10)
        return false;
    for (char c : phone)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

int timeToSeconds(const string &time_str)
{
    int h = (time_str[0] - '0') * 10 + (time_str[1] - '0');
    int m = (time_str[3] - '0') * 10 + (time_str[4] - '0');
    int s = (time_str[6] - '0') * 10 + (time_str[7] - '0');
    return h * 3600 + m * 60 + s;
}

int main()
{

    unordered_map<string, CallStat> stats;
    int total_calls = 0;
    bool all_valid = true;

    string type;

    while (cin >> type && type != "#")
    {
        string from_number, to_number, date, from_time, end_time;
        cin >> from_number >> to_number >> date >> from_time >> end_time;

        total_calls++;

        if (all_valid)
        {
            if (!isValidPhone(from_number) || !isValidPhone(to_number))
            {
                all_valid = false;
            }
        }

        int duration = timeToSeconds(end_time) - timeToSeconds(from_time);
        stats[from_number].count++;
        stats[from_number].total_duration += duration;
    }

    while (cin >> type && type != "#")
    {
        if (type == "?check_phone_number")
        {
            cout << (all_valid ? 1 : 0) << "\n";
        }
        else if (type == "?number_total_calls")
        {
            cout << total_calls << "\n";
        }
        else if (type == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            auto it = stats.find(phone);
            cout << (it != stats.end() ? it->second.count : 0) << "\n";
        }
        else if (type == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            auto it = stats.find(phone);
            cout << (it != stats.end() ? it->second.total_duration : 0) << "\n";
        }
    }

    return 0;
}