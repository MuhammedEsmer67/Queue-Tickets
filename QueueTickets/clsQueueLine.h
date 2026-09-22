#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include "clsDate.h"
#include "clsUtility.h"

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
		int _TicketNO;
		string _Date;

	public:

		clsTicket(string Prefix, short TreatmentTime, int TicketNO)
		{
			_Prefix = Prefix;
			_TreatmentTime = TreatmentTime;
			_TicketNO = TicketNO;
			_Date = clsDate::GetSystemDateTime();
		}

		const string GetTicketCode() const { return _Prefix + to_string(_TicketNO); }

		short GetServeTime(short Position) const { return Position * _TreatmentTime; }

		void PrintTicket(short Position) const
		{
			cout << clsUtility::Tabs(6) << "                  " << _Prefix << _TicketNO << endl << endl;
			cout << clsUtility::Tabs(6) << "         " << _Date << endl;
			cout << clsUtility::Tabs(6) << "         Waiting Clients = " << Position << endl;
			cout << clsUtility::Tabs(6) << "            Serve Time in\n";
			cout << clsUtility::Tabs(6) << "             " << GetServeTime(Position) << " Minutes.\n";
		}

	};

	int _GetServedClients() const { return _TotalTickets - static_cast<int>(_Line.size()); }

	queue <clsTicket> _Line;

public:

	clsQueueLine(string Prefix, short TreatmentTime)
	{
		_Prefix = Prefix;
		_TreatmentTime = (TreatmentTime > 0) ? TreatmentTime : 3;
		_TotalTickets = 0;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TreatmentTime, _TotalTickets);

		_Line.push(Ticket);
	}

	void PrintInfo() const
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

	void PrintTicketsLineRToL() const
	{
		if (_Line.empty())
		{
			cout << "Tickets: No Tickets.\n";
			return;
		}

		queue <clsTicket> Line = _Line;
		string TicketCode = "";

		cout << "Tickets: ";

		while(!Line.empty())
		{
			TicketCode = Line.front().GetTicketCode();
			Line.pop();

			cout << TicketCode << " <-- ";
		}

		cout << endl;
	}

	void PrintTicketsLineLToR() const
	{
		if (_Line.empty())
		{
			cout << "Tickets: No Tickets.\n";
			return;
		}

		stack <string> sTicketCodes;
		queue <clsTicket> Line = _Line;
		string TicketCode = "";

		while (!Line.empty())
		{
			TicketCode = Line.front().GetTicketCode();
			sTicketCodes.push(TicketCode);
			Line.pop();
		}

		cout << "Tickets: ";

		while (!sTicketCodes.empty())
		{
			cout << sTicketCodes.top() << " --> ";
			sTicketCodes.pop();
		}

		cout << endl;
	}

	void PrintAllTickets() const
	{
		if (_Line.empty())
		{
			cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";
			cout << clsUtility::Tabs(6) << "       No available tickets.\n";
			cout << clsUtility::Tabs(6) << "____________________________________\n\n";
			return;
		}

		cout << endl << clsUtility::Tabs(6) << "            ___Tickets___";

		queue <clsTicket> Line = _Line;
		short Position = 0;

		while (!Line.empty())
		{
			cout << endl << clsUtility::Tabs(6) << "____________________________________\n\n";
			Line.front().PrintTicket(Position++);
			cout << clsUtility::Tabs(6) << "____________________________________\n\n";

			Line.pop();
		}
	}

	bool ServeNextClient()  
	{ 
		if (_Line.empty())
			return false;

		_Line.pop();
		return true;
	}

	string WhoIsNext() const
	{
		if (_Line.empty())
			return "";
		
		return _Line.front().GetTicketCode();
	}

};