// #include <stdio.h> to use printf,
// or better yet, use <iostream> for c++


class Customer
{
public:
	int	birthYear;
	bool	isCurrentMember;							// indents are inconsistant through out
	int	numberOfPurchases;

	Customer()
	{
		// Test data.
		birthYear = 1963;
		isCurrentMember = false;
		numberOfPurchases = 33;
	}

	void DisplayDetails()
	{
		printf( "Birth Year: %ld\r\n", birthYear );		// include <stdio.h> to use printf, or use std::cout
														// type error, format string is not expecting long int

		printf( "Current Member: %s\r\n", isCurrentMember ? "Yes" : "No" );

		printf( "Number Of Purchases: %ld\r\n\r\n", numberOfPurchases );
														// type error, format string is not expecting long int
														// int should suffice, no need for long int
	}
};


class Salesman
{
private:
	Customer	bestCustomer;
	Customer	worstCustomer;

public:													// I'm not sure what the convention for C++ is but
														// I would put public before private, for readability
	int id;

	Salesman( int initialID )
	{
		id = initialID;
	}
	Customer BestCustomer()
	{
		return bestCustomer;
	}
	Customer* WorstCustomer()							// inconsistant to BestCustomer()
	{
		return &worstCustomer;
	}
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
		printf( "Salesman 1: %ld\r\n", salesman1.id );	// what's with the %ld
		printf( "Salesman 2: %ld\r\n", salesman2.id );
	}
};


void TestSalesmanCustomers()
{
	SalesTeam ourTeam;

	int medianSales_1 =
		(ourTeam.salesman1.BestCustomer().numberOfPurchases
		+ ourTeam.salesman1.WorstCustomer()->numberOfPurchases) / 2;
														// inconsistant use of pointer and reference

	int medianSales_2 =
		(ourTeam.salesman2.BestCustomer().numberOfPurchases
			+ ourTeam.salesman2.WorstCustomer()->numberOfPurchases) / 2;
														// same here, and with inconsistant indent
														// also repeatative, I would put this is a medianSales function in Salesman

	printf( "Salesman median sales = %ld\r\n", medianSales_1);
	printf( "Salesman median sales = %ld\r\n", medianSales_2);
}
