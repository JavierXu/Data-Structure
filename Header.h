


#pragma once
class Flight
{
	friend ostream;
public:
	string date;
	int time;
	string origin;
	string destination;

public:
	Flight(string& origininfo, string& destinationinfo, string& dateinfo, int& timeinfo)
	{
		date = dateinfo;
		time = timeinfo;
		origin = origininfo;
		destination = destinationinfo;
	}

	Flight()
	{
		date = "exist";
		time = 2333;
		origin = "flight";
		destination = "doesnot";
	}

	bool operator < (const Flight&target) const
	{
		return (time < target.time);
	}

	bool operator < (const int&target) const
	{
		return (time < target);
	}

	bool operator == (const int&target) const
	{
		return (time == target);
	}

	bool operator != (const Flight&target) const
	{
		return (time != target.time);
	}

	bool operator > (const int&target) const
	{
		return (time > target);
	}

	bool operator > (const Flight&target) const
	{
		return (time > target.time);
	}


	friend ostream &operator << (ostream&output, const Flight&target)
	{
		cout << '('<<target.origin << ","<< target.destination << "," << target.date << "," << target.time/100<<':'<<target.time%100<<')';
		return output;
	}
};
