#include <iostream>
#include <string>
#include <fstream>

struct statement {

	std::string name = "Unknow";
	std::string surname = "Unknow";
	std::string date_of_issue = "00:00:00";
	int sum = 0;

};

void recording_data_in_a_register(statement& person) {

	std::cout << "Enter name: ";
	std::cin >> person.name;

	std::cout << "Enter surname: ";
	std::cin >> person.surname;
	

	std::cout << "Enter date_of_issue: ";
	std::cin >> person.date_of_issue;

	std::cout << "Enter sum: ";
	std::cin >> person.sum;

	std::ofstream out_cash_payment_statement("statement.txt", std::ios::app);

	out_cash_payment_statement << person.name << " " << person.surname << " " << person.date_of_issue << " " << person.sum << std::endl;

	out_cash_payment_statement.close();

}

void reading_data_from_the_registry(statement& person) {
		
	std::ifstream in_cash_payment_statement("statement.txt");
	
	int count = 0;
	while (!in_cash_payment_statement.eof()) {			
		
		person.name = "";

		in_cash_payment_statement >> person.name >> person.surname >> person.date_of_issue >> person.sum;		

		if (person.name == "") {

			break;

		}

		std::cout << person.name << " " << person.surname << " " << person.date_of_issue << " " << person.sum << std::endl;

		++count;
	}
	
	in_cash_payment_statement.close();
}

int main() {

	statement person;
	std::string command;

	do {

		std::cout << "To read the statement, enter \"list\", to write, enter \"add\": ";
		std::cin >> command;

	} while(command != "list" && command != "add");

	if (command == "list") {

		reading_data_from_the_registry(person);
		
	}
	else if (command == "add") {		

		recording_data_in_a_register(person);
		
	}	
}