#include <iostream>
#include <memory>
using namespace std;

class BankCell {
private:
	int balance;
public:	
	BankCell() {
		this->balance = 0;
		std::cout << "BankCell create\n";
	}
	~BankCell() {
		std::cout << "BankCell delete\n";
	}
	int get_balance() {
		return this->balance;
	}
	void add_coin(const int sum) {
		std::cout << sum << balance << '\n';
		balance += sum;
		std::cout << "Human add money\n";
	}
	void get_coin(const int sum) {
		if (balance - sum < 0) {
			std::cout << "BankCell don't enought money\n";
		}
		else {
			balance -= sum;
			std::cout << "Human get coin\n";
		}
	}	
};

class Human {
public:
	Human(std::shared_ptr<BankCell> ptr_cell){
		std::shared_ptr<BankCell> ptr_owner(ptr_cell);
		std::cout << "Owner get key\n";
	}
	~Human(){
		std::cout << "Human died\n";
	}
	void add_money(int sum) {
		(*ptr_owner).add_coin(sum);
	}
	void get_money(int sum) {
		(*ptr_owner).get_coin(sum);
	}
	void balance() {
		(*ptr_owner).get_balance();
	}
private:
	std::shared_ptr<BankCell> ptr_owner;
};

int main() {
	BankCell* Cell = new BankCell();
	std::shared_ptr<BankCell> ptr_cell(Cell);
	std::unique_ptr<Human> Owner1 = std::make_unique<Human>(ptr_cell);
	std::unique_ptr<Human> Owner2 = std::make_unique<Human>(ptr_cell);

	(*Owner2).balance();
	(*Owner1).add_money(150);
	(*Owner2).add_money(300);
	(*Owner1).get_money(100);
	(*Owner1).balance();
	(*Owner2).get_money(400);
	(*Owner2).balance();

}