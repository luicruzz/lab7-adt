/*
 * Course: COEN 2220 - Programming 2
 * Name: [Luis Cruz]
 * Lab: Lab 7 - Abstract Data Types
 * Description: ADT contract, implementation, and client code practice
 * Due date: [10/1/26]
 */

#include <iostream>
using namespace std;

/*
 * StudySessionLog ADT
 *
 * Data:
 * Study session durations in minutes for one student.
 *
 * Operations:
 * addSession(minutes): Adds a study session duration and returns true if
 * the session was accepted, or false if another session cannot be accepted.
 *
 * totalMinutes(): Returns the total number of study minutes recorded.
 *
 * longestSession(): Returns the duration of the longest study session.
 * Precondition: At least one study session must be stored.
 *
 * size(): Returns the number of stored study sessions.
 *
 * isEmpty(): Returns true if no study sessions are stored.
 */

class StudySessionLog
{
private:
    static const int CAPACITY = 4;
    int sessionMinutes[CAPACITY];
    int count;

public:
    StudySessionLog()
    {
        count = 0;
    }

    bool addSession(int minutes)
    {
        if (count == CAPACITY)
        {
            return false;
        }

        sessionMinutes[count] = minutes;
        count++;

        return true;
    }

    int totalMinutes() const
    {
        int total = 0;

        for (int i = 0; i < count; i++)
        {
            total += sessionMinutes[i];
        }

        return total;
    }

    int longestSession() const
    {
        int longest = sessionMinutes[0];

        for (int i = 1; i < count; i++)
        {
            if (sessionMinutes[i] > longest)
            {
                longest = sessionMinutes[i];
            }
        }

        return longest;
    }

    int size() const
    {
        return count;
    }

    bool isEmpty() const
    {
        return count == 0;
    }
};


    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudySessionLog object and print whether it starts empty.
    // TODO (Part E): Add four dummy session durations and attempt to add a fifth.
    // TODO (Part E): Print the number of stored sessions and whether the fifth session was accepted.
    // TODO (Part E): Print the total minutes and the longest stored session.
    // TODO (Part E): Print descriptive English labels for all results.
    
    int main()
{
    cout << boolalpha;

    StudySessionLog sessionLog;

    cout << "Log starts empty: "
         << sessionLog.isEmpty() << endl;

    sessionLog.addSession(45);
    sessionLog.addSession(60);
    sessionLog.addSession(35);
    sessionLog.addSession(90);

    bool fifthAccepted = sessionLog.addSession(50);

    cout << "Fifth session accepted: "
         << fifthAccepted << endl;

    cout << "Stored sessions: "
         << sessionLog.size() << endl;

    cout << "Total study minutes: "
         << sessionLog.totalMinutes() << endl;

    cout << "Longest session: "
         << sessionLog.longestSession() << endl;

    return 0;
}