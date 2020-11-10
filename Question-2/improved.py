'''	Programming Test (2020) - Windcave
	QUESTION TWO - Salesman Customers
	by Simon Shan | qsha020@aucklanduni.ac.nz
'''

PURCHASES = lambda customer: customer.num_purchases


class Customer:

	def __init__(self, birth_year, is_current_member,
										num_purchases):
		assert isinstance(birth_year,        int )
		assert isinstance(is_current_member, bool)
		assert isinstance(num_purchases,     int )

		self.birth_year        = birth_year
		self.is_current_member = is_current_member
		self.num_purchases     = num_purchases

	def display_details(self):
		print('Birth Year:         ', self.birth_year)
		print('Current Member:     ', 'Yes' if self.is_current_member else 'No')
		print('Number of Purchases:', self.num_purchases)


class Salesman:

	def __init__(self, initial_ID):
		self.id = initial_ID
		self.customers = []						# stores all customers belonging to this salesman

	def add_customer(self, customer):
		assert isinstance(customer, Customer)	# type checking
		self.customers.append(customer)

	def remove_customer(self, customer):
		try:
			self.customers.remove(customer)
		except ValueError:
			pass								# ignore if customer not found

	def get_best_customer(self):
		'''customer with the most purchases'''
		return max(self.customers, key=PURCHASES)
												# use the specified lambda function as comparison key
	def get_worst_customer(self):
		'''customer with the least purchases'''
		return min(self.customers, key=PURCHASES)

	def get_median_sales(self):
		most  = self.get_best_customer().num_purchases
		least = self.get_worst_customer().num_purchases
		return (most+least) // 2


class SalesTeam:
	''''''

	def __init__(self):
		self.salesmen = []						# stores all salesman belonging to this sales team

	def add_salesman(self, salesman):
		assert isinstance(salesman, Salesman)	# type checking
		self.salesmen.append(salesman)

	def remove_salesman(self, salesman):
		try:
			self.salesmen.remove(salesman)
		except ValueError:
			pass								# ignore if salesman not found

	def display_team(self):
		for salesman in self.salesmen:
			print('Salesman', salesman.id)


def test_salesman_customers():
	toby = Salesman(1000)
	toby.add_customer(Customer(1999, False, 10))
	toby.add_customer(Customer(1999, False, 25))
	toby.add_customer(Customer(1999, False, 30))

	mark = Salesman(1001)
	mark.add_customer(Customer(1999, False, 0))
	mark.add_customer(Customer(1999, False, 1))
	mark.add_customer(Customer(1999, False, 500))

	windcave_sales_team = SalesTeam()
	windcave_sales_team.add_salesman(toby)
	windcave_sales_team.add_salesman(mark)

	print('toby\'s median sales =', toby.get_median_sales())
	print('mark\'s median sales =', mark.get_median_sales())



if __name__ == '__main__':

	test_salesman_customers()
