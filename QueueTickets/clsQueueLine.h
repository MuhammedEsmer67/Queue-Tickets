#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "clsDate.h"
#include "clsUtility.h"
using namespace std;

class clsQueueLine
{
private:

	string _Prefix;
	short _TreatmentTime;
	int _TotalTickets;

	class clsTicket
	{
	private:

		string _Prefix;
		short _TreatmentTime;
		short _TicketNO;
		string _Date;
		short _WaitingClients;

	public:

		clsTicket(string Prefix, short TreatmentTime, short TicketNO, short WaitingClients)
		{
			_Prefix = Prefix;
			_TreatmentTime = TreatmentTime;
			_TicketNO = TicketNO;
			_Date = clsDate::GetSystemDateTime();
			_WaitingClients = WaitingClients;
		}

		short getTicketNO() { return _TicketNO; }

		string GetTicketCode() { return _Prefix + to_string(_TicketNO); }

		short GetServeTime() { return _WaitingClients * _TreatmentTime; }

		void PrintTicket()
		{
			cout << clsUtility::Tabs(6) << "                  " << _Prefix << _TicketNO << endl << endl;
			cout << clsUtility::Tabs(6) << "         " << _Date << endl;
			cout << clsUtility::Tabs(6) << "         Waiting Clients = " << _WaitingClients << endl;
			cout << clsUtility::Tabs(6) << "            Serve Time in\n";
			cout << clsUtility::Tabs(6) << "             " << GetServeTime() << " Minutes.\n";
		}

	};

	short _GetServedClients() { return _TotalTickets - _Line.size(); }

	queue <clsTicket> _Line;

public:

	clsQueueLine(string Prefix, short TreatmentTime)
	{
		_Prefix = Prefix;
		_TreatmentTime = TreatmentTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TreatmentTime, _TotalTickets, _Line.size());

		_Line.push(Ticket);
	}

	void PrintInfo()
	{
		cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";
		cout << clsUtility::Tabs(6) << "             Queue Info";
		cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";

		cout << clsUtility::Tabs(7) << "Total Tickets   = " << _TotalTickets << endl;
		cout << clsUtility::Tabs(7) << "Prefix          = " << _Prefix << endl;
		cout << clsUtility::Tabs(7) << "Served Clients  = " << _GetServedClients() << endl;
		cout << clsUtility::Tabs(7) << "Waiting Clients = " << _Line.size();

		cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";
	}

	void PrintTicketsLineRToL()
	{
		if (_Line.empty())
		{
			cout << "Tickets: No Tickets.\n";
			return;
		}

		queue <clsTicket> Line = _Line;
		string TicketCode = "";

		cout << "Tickets: ";

		for (short i = 1; i <= _Line.size(); i++)
		{
			TicketCode = Line.front().GetTicketCode();
			Line.pop();

			cout << TicketCode << " <-- ";
		}

		cout << endl;
	}

	void PrintTicketsLineLToR()
	{
		if (_Line.empty())
		{
			cout << "Tickets: No Tickets.\n";
			return;
		}

		stack <string> sTicketCodes;
		queue <clsTicket> Line = _Line;
		string TicketCode = "";

		for (short i = 1; i <= _Line.size(); i++)
		{
			TicketCode = Line.front().GetTicketCode();
			sTicketCodes.push(TicketCode);
			Line.pop();
		}

		cout << "Tickets: ";

		for (short i = 1; i <= _Line.size(); i++)
		{
			cout << sTicketCodes.top() << " --> ";
			sTicketCodes.pop();
		}

		cout << endl;
	}

	void PrintAllTickets()
	{
		cout << endl << clsUtility::Tabs(6) << "            ___Tickets___";

		if (_Line.empty())
		{
			cout << endl << clsUtility::Tabs(6) << "No avalaible tickets.\n";
			return;
		}

		queue <clsTicket> Line = _Line;

		for (short i = 1; i <= _Line.size(); i++)
		{
			cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";
			Line.front().PrintTicket();
			cout << clsUtility::Tabs(6) << "____________________________________\n\n";

			Line.pop();
		}
	}

	void ServeNextClient()  
	{ 
		if (_Line.empty())
			return;

		_Line.pop();
	}

	string WhoIsNext()
	{
		if (_Line.empty())
			return "No Clients Left.\n";
		
		return _Line.front().GetTicketCode();
	}

};