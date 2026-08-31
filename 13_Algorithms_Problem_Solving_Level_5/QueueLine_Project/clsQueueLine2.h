#include <iostream>
#include "clsDate.h"
#include "clsMyQueueArr.h"

using namespace std;

class clsQueueLine
{
private:
    string _Prefix;
    int _TotalTickets;
    int _ServedClients;
    int _WaitingClients;
    int _DurationForEachClient;

    class Ticket
    {
    public:
        string TicketNumber;
        clsDate TicketDate;
        int WaitingClients;
        int TimeToServe;
    };
    clsMyQueueArr<Ticket> _TicketsQueue;

public:
    clsQueueLine(string Prefix, int DurationForEachClient)
    {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _ServedClients = 0;
        _WaitingClients = 0;
        _DurationForEachClient = DurationForEachClient;
    }

    void IssueTicket()
    {
        Ticket newTicket;
        _TotalTickets++;
        newTicket.TicketNumber = _Prefix + to_string(_TotalTickets);
        newTicket.TicketDate = clsDate::GetSystemDate();
        newTicket.TimeToServe = _DurationForEachClient * _WaitingClients;
        newTicket.WaitingClients = _WaitingClients;
        _WaitingClients++;
        _TicketsQueue.push(newTicket);
    }

    bool ServeNextClient()
    {
        if (_TicketsQueue.IsEmpty())
            return false;
        _TicketsQueue.pop();
        _ServedClients++;
        _WaitingClients--;
        return true;
    }

    
};
