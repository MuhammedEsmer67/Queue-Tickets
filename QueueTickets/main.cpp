#include "clsQueueLine.h"

int main()
{
    clsQueueLine QueueLine("A", 5);

    QueueLine.IssueTicket();
    QueueLine.IssueTicket();
    QueueLine.IssueTicket();

    QueueLine.PrintInfo();
    // Total Tickets   = 3
    // Prefix          = A
    // Served Clients  = 0
    // Waiting Clients = 3

    QueueLine.PrintTicketsLineRToL();
    // Tickets: A1 <-- A2 <-- A3 <--

    QueueLine.PrintTicketsLineLToR();
    // Tickets: A3 --> A2 --> A1 -->

    QueueLine.PrintAllTickets();
    // Prints full ticket details for each client

    cout << "Next: " << QueueLine.WhoIsNext() << endl;
    // Next: A1

    QueueLine.ServeNextClient();

    cout << "Next: " << QueueLine.WhoIsNext() << endl;
    // Next: A2

    QueueLine.PrintInfo();
    // Total Tickets   = 3
    // Served Clients  = 1
    // Waiting Clients = 2

    return 0;
}