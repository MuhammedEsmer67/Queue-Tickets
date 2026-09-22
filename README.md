# Queue-Tickets

A general-purpose **queue ticket system** written in C++ using OOP and the STL. It models the number-ticket flow you see in banks, government offices, and fast-food restaurants: clients take a numbered ticket, wait in a first-in-first-out line, and are served in order.

![C++](https://img.shields.io/badge/C%2B%2B-OOP-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-informational)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple)

---

## Features

- Issue tickets with a prefix and an incrementing number (`A1`, `A2`, `A3`, ...)
- Serve the next client in strict FIFO order
- See who is next without removing them from the line
- Print queue statistics: total tickets, served clients, waiting clients
- Print the line in two directions (right to left and left to right)
- Print every waiting ticket with its date, position, and estimated wait time

---

## How It Works

### Classes

**`clsQueueLine`** manages the whole line.

| Member | Type | Purpose |
|---|---|---|
| `_Prefix` | `string` | Letter(s) in front of every ticket number, e.g. `A` for one service counter |
| `_TreatmentTime` | `short` | Average service time per client, in minutes |
| `_TotalTickets` | `int` | How many tickets have been issued so far |
| `_Line` | `queue<clsTicket>` | The waiting tickets, oldest at the front |

**`clsTicket`** is a private nested class that represents one ticket. It stores the prefix, the ticket number, the treatment time, and the date/time of issue. It is created only inside `IssueTicket()`, so outside code can never build a ticket directly.

### Public methods

| Method | What it does |
|---|---|
| `clsQueueLine(Prefix, TreatmentTime)` | Creates a line. Assigns 3 if not `TreatmentTime > 0`. |
| `IssueTicket()` | Increments the ticket counter, creates a `clsTicket`, and pushes it to the back of `_Line`. |
| `ServeNextClient()` | Pops the front ticket. Returns `false` if the line is empty, `true` otherwise. |
| `WhoIsNext()` | Returns the code of the front ticket, or an empty string if nobody is waiting. |
| `PrintInfo()` | Prints total tickets, prefix, served clients, and waiting clients. |
| `PrintTicketsLineRToL()` | Prints the line as `A1 <-- A2 <-- A3`. |
| `PrintTicketsLineLToR()` | Prints the line as `A3 --> A2 --> A1`. |
| `PrintAllTickets()` | Prints every waiting ticket in a formatted box. |

Every method that only reads or prints is `const`. Only `IssueTicket()` and `ServeNextClient()` change the object.

### Line direction

The first ticket issued (for example `A1`) is at the **front** of the queue and is served first.

- `PrintTicketsLineRToL` puts the counter on the left, so the line moves right to left.
- `PrintTicketsLineLToR` puts the counter on the right, so the line moves left to right.

The arrows always point toward the client who will be served next. The names describe the direction the line moves, not the order the codes are printed.

`queue` can only be read from the front, so printing front to back is natural. To print back to front, the codes are pushed onto a `stack` and popped, which reverses the order (FIFO becomes LIFO).

### Wait-time estimate

When a ticket is printed by `PrintAllTickets()`, its wait time is calculated from its **current position** in the line:

```
Waiting Clients = number of tickets ahead of it (its index in the queue)
Serve Time      = Waiting Clients x TreatmentTime   (minutes)
```

The front ticket shows `0` clients and `0` minutes, meaning "next to be served". Because the value is computed at print time, it stays correct after clients are served.

---

## Why `queue`?

A ticket system needs **first in, first out**. `queue` exposes only FIFO operations: push at the back and pop at the front, both O(1). The data structure itself enforces the ordering rule, so the code cannot accidentally serve the wrong client.

- A `stack` is LIFO and would serve the newest client first.
- A `vector` could imitate FIFO with `erase(begin())`, but every serve would shift all elements, which is O(n).
- `queue` is by default a wrapper around `deque`, which gives the O(1) operations at both ends.

---

## Project Structure

```
📁 Queue-Tickets/
├── 📄 QueueTickets.sln
├── 📁 QueueTickets/
│   ├── 📁 Header Files/
│   │   ├── clsChar.h
│   │   ├── clsDate.h
│   │   ├── clsQueueLine.h	— Core queue line logic with nested ticket class
│   │   ├── clsString.h
│   │   └── clsUtility.h
│   └── 📁 Source Files/
│       └── main.cpp        — Test and usage examples
```

`clsDate` and `clsUtility` are helper classes written by me and included in this repository.

## Example Usage

```cpp
#include "clsQueueLine.h"

int main()
{
    clsQueueLine Bank("A", 5);        
    // clsQueueLine Clinic("B", 15);

    Bank.IssueTicket();
    Bank.IssueTicket();
    Bank.IssueTicket();

    Bank.PrintTicketsLineRToL();
    cout << "Next: " << Bank.WhoIsNext() << endl;

    Bank.ServeNextClient();
    Bank.PrintInfo();
}
```

### Sample output

Tickets: A1 <-- A2 <-- A3 <--
Next: A1

                                                ____________________________________

                                                             Queue Info
                                                ____________________________________

                                                        Total Tickets   = 3
                                                        Prefix          = A
                                                        Served Clients  = 1
                                                        Waiting Clients = 2
                                                ____________________________________

---

## Build and run

### Visual Studio 2022 Community

1. Install Visual Studio Community with the **Desktop development with C++** workload.
2. Clone the repo: `git clone https://github.com/MuhammedEsmer67/ATM-System.git`
3. Open the project:
   - If the repo contains a `.sln` file, double-click it.
   - Otherwise: **File > New > Project > Console App (C++)**, then in Solution Explorer right-click **Source Files > Add > Existing Item** and add `main.cpp`; do the same for `clsDblLinkedList.h` under **Header Files**. Remove the auto-generated `.cpp` file.
4. Press **Ctrl + F5** (Start Without Debugging). A console window shows the output.

### PowerShell (g++)

```
g++ -std=c++17 main.cpp -o QueueTickets
.\QueueTickets
```
