#include <iostream>

using namespace std;

int sum (int, int, int = 0); // works with 2 args too
// set default value to all right part of the arg. (int, int = 0, int): error. But (int, int = 0, int = 0) works fine.

inline void inline_func(); // inline: during declaration

class Account {
	private:
	int balance; // instance member variable
	static float roi; // static member var

	public:

	void set_balance (int b) { balance = b; }
	static void set_roi (float r) { roi = r; } // static to access roi (it's private right now)

	// Constructor overloading
	Account () { cout << "Constructor invoked.\n"; } // 1. default constructor
	Account (int x) {} // 2. Parameterized constructor
	Account (int x, int y) {}
	Account (Account &a) { // 3. Copy constructor
		balance = a.balance;
	}

	// Destr.
	~Account() {} // default by compiler
	
};

float Account::roi = 3.5; // roi gets memory after definition

int main() {
	void fun(); // func declaration ( / prototype). It can only be called in this block now.
	cout << "In main.\n";
	fun(); // func call

	int a = 5, b = 6;
	int s = sum(a, b); // ACTUAL args
	cout << "sum: " << s << endl;

	inline_func();

	// static:
	Account::set_roi(2.6);
	Account a1(2), a2 = Account (4,5), a3(a1);
}

// func definition = implementation
void fun() {
	cout << "In fun.\n";
}

int sum (int x, int y, int z) { // FORMAL args
	/**
	 * Formal args: 3 types
	 * 1. Ordinary (p, q) = copies of the values of actual args (a, b) => function call by value
	 * 2. Pointer (*p, *q) = addresses of actual args (&a, &b) => function call by address
	 * 3. Reference (&p, &q) = references of actual args (a, b) => function call by reference
	 */
	return (x + y + z);
}

void inline_func() {
	cout << "Inline function.\n";
}