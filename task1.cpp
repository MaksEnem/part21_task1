#include <iostream>
#include <string>
#include <fstream>

struct statement {

	std::string name = "Unknow";
	std::string surname = "Unknow";
	std::string date_of_issue = "DD.MM.YYYY";
	int sum = 0;

};

void recording_data_in_a_register(statement& person) {

	int validation_day;
	int validation_day_month;
	int validation_day_year;


	std::cout << "Enter name: ";
	std::cin >> person.name;

	std::cout << "Enter surname: ";
	std::cin >> person.surname;
	
	std::cout << "Enter the date of issue of funds in the format DD.MM.YYYY.: ";
	std::cin >> person.date_of_issue;

	validation_day = std::stoi(person.date_of_issue.substr(0, 2));
	validation_day_month = std::stoi(person.date_of_issue.substr(3, 2));
	validation_day_year = std::stoi(person.date_of_issue.substr(6, 4));

	while ((validation_day < 1 || validation_day > 31) || (validation_day_month < 1 || validation_day_month > 12) || (validation_day_year < 2000 || validation_day_year > 2023)) {

		std::cout << "Incorrect date!\n";
		std::cout << "Enter the date of issue of funds in the format DD.MM.YYYY.: \n";
		std::cin >> person.date_of_issue;

		validation_day = std::stoi(person.date_of_issue.substr(0, 2));
		validation_day_month = std::stoi(person.date_of_issue.substr(3, 2));
		validation_day_year = std::stoi(person.date_of_issue.substr(6, 4));

	}

	std::cout << "Enter sum: ";
	std::cin >> person.sum;


	std::ofstream out_cash_payment_statement("statement.txt", std::ios::app);

	if (out_cash_payment_statement.is_open()) {

		out_cash_payment_statement << person.name << " " << person.surname << " " << person.date_of_issue << " " << person.sum << std::endl;

		out_cash_payment_statement.close();

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}
	
}

void reading_data_from_the_registry(statement& person) {
		
	std::ifstream in_cash_payment_statement("statement.txt");
	
	if (in_cash_payment_statement.is_open()) {

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
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}
	
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