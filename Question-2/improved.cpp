/*
 *	Programming Test (2020) - Windcave
 *	QUESTION TWO - Salesman Customers
 *	by Simon Shan | qsha020@aucklanduni.ac.nz
 */

#include <iostream>
using namespace std;

class Customer
{
public:
	int  birthYear;
	bool isCurrentMember;
	int  numberOfPurchases;

	Customer()
	{
		// Test data.
		birthYear = 1963;
		isCurrentMember = false;
		numberOfPurchases = 33;
	}

	void DisplayDetails()
	{
		cout << "Birth Year:          " << birthYear << endl;
		cout << "Current Member:      " << (isCurrentMember ? "Yes" : "No") << endl;
		cout << "Number Of Purchases: " << numberOfPurchases << endl << endl;
	}
};


class Salesman
{

public:
	int id;

	Salesman( int initialID )
	{
		id = initialID;
	}
	Customer BestCustomer()
	{
		return bestCustomer;
	}
	Customer WorstCustomer()
	{
		return worstCustomer;
	}
/********************** simon: addition ***********************/
	int MedianSales()					// CamelCase with new line curly 
	{									// bracket to follow the existing style
		int most  = bestCustomer.numberOfPurchases;
		int least = worstCustomer.numberOfPurchases;
		return (most+least) / 2;
	}
/********************** simon: addition ***********************/
private:
	Customer bestCustomer;
	Customer worstCustomer;
};

class SalesTeam
{
public:
	Salesman salesman1;
	Salesman salesman2;
	
	SalesTeam()
		: salesman1(1000), salesman2(1001)
	{}

	void DisplayTeam()
	{
		cout << "Salesman 1: " << salesman1.id << endl;
		cout << "Salesman 2: " << salesman2.id << endl;
	}
};


void TestSalesmanCustomers()
{
	SalesTeam ourTeam;

	cout << "Salesman median sales = " << ourTeam.salesman1.MedianSales() << endl;
	cout << "Salesman median sales = " << ourTeam.salesman2.MedianSales() << endl;
}

////////////////////////////////////////////////////////////////
////                    MAIN STARTS HERE                    ////
////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
	TestSalesmanCustomers();
	return 0;
}
