# Queue Ticket System — C++

A console-based queue ticket system built in C++ using OOP and STL, simulating a real-world client service queue with ticket issuance, waiting time estimation, and client serving.

![C++](https://img.shields.io/badge/C%2B%2B-OOP-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-informational)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple)

---

## Description

This project models a service queue line where clients receive numbered tickets with a prefix, issue date/time, waiting client count, and estimated serve time. It demonstrates practical use of `std::queue` and `std::stack` from the C++ STL alongside object-oriented design with nested classes.

---

## Features

- Issue tickets with a custom prefix and auto-incremented number
- Display ticket details: ticket code, date/time, waiting clients, estimated serve time
- Print queue direction left-to-right and right-to-left
- Display all tickets in the queue
- Serve the next client (dequeue)
- Check who is next in line
- Display full queue info: total tickets, served clients, waiting clients

---

## Project Structure

```
📁 Queue-Tickets/
├── 📄 QueueTickets.sln
├── 📁 QueueTickets/
│   ├── 📁 Header Files/
│   │   ├── clsDate.h       — Date and time utilities
│   │   └── clsQueueLine.h  — Core queue line logic with nested ticket class
│   └── 📁 Source Files/
│       └── main.cpp        — Test and usage examples
```

---

## How to Use

```cpp
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
}
```

---

## Technologies

- Language: C++
- Paradigm: Object-Oriented Programming (OOP)
- STL: `std::queue`, `std::stack`
- IDE: Visual Studio 2022
- Platform: Windows

---

## Topics

`cpp` `oop` `data-structures` `queue` `stack` `stl` `visual-studio-2022`
