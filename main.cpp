/*Assignment: Create a program which can test the validity of propositional logic. 
Remember, a propositional logical statement is invalid should you find any combination
of input where the PROPOSITIONAL statements are ALL true, while the CONCLUSION statement is false.
Propositional Statements:
If someone has a rocket, that implies they’re an astronaut.
If someone is an astronaut, that implies they’re highly trained.
If someone is highly trained, that implies they’re educated.
Conclusion Statement:
A person is educated, that implies they have a rocket.
Your output should declare the statement to either be valid or invalid. If it’s invalid, it needs 
to state which combination of inputs yielded the statement invalid. MAKE SURE IT POINTS OUT EVERY TIME 
THE STATEMENT IS INVALID IF IT IS INDEED INVALID.
*/

#include <iostream>
#include <iomanip>

using namespace std;

bool Implies(bool a, bool b);

//Logic table for the variables
int Rocket[16] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 };
int Astronaut[16] = { 0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1 };
int Trained[16] = { 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1 };
int Educated[16] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};

//Propositional Statements
bool RA[16];	//If someone has a rocket, that implies they’re an astronaut.
bool AT[16];	//If someone is an astronaut, that implies they’re highly trained.
bool TE[16];	//If someone is highly trained, that implies they’re educated.

//Conclusion Statement 
bool ER[16];	//A person is educated, that implies they have a rocket.


int main() {

	//Test if the propositional and conclusion statements are true and false 
	//Set bool array for the 4 statements 
	for (int i = 0; i < 16; i++) {

		//If someone has a rocket, that implies they’re an astronaut.
		if (Implies(Rocket[i], Astronaut[i]) == true) {				

			RA[i] = true;
		}
		else {

			RA[i] = false;
		}

		//If someone is an astronaut, that implies they’re highly trained.
		if (Implies(Astronaut[i], Trained[i]) == true) {			

			AT[i] = true;
		}
		else {

			AT[i] = false;
		}

		//If someone is highly trained, that implies they’re educated.
		if (Implies(Trained[i], Educated[i]) == true) {				

			TE[i] = true;
		}
		else {

			TE[i] = false;
		}

		//A person is educated, that implies they have a rocket.
		if (Implies(Educated[i], Rocket[i]) == true) {				

			ER[i] = true;
		}
		else {

			ER[i] = false;
		}

	}
	cout << "This program tests the validity of the following propositonal logic statement" << endl;
	cout << "and displays when it is valid or invalid: "<< endl << endl;
	cout << "Proposition:" << endl;
	cout << "If someone has a rocket, that implies they are an astronaut." << endl;
	cout << "If someone is an astronaut, that implies they are highly trained." << endl;
	cout << "If someone is highly trained, that implies they are educated." << endl << endl;
	cout << "Conclusion:" << endl;
	cout << "A person is educated, that implies they have a rocket." << endl << endl;

	//Display the truth table 
	cout << setw(8) << "Rocket" << setw(12) << "Astronaut" << setw(10) << "Trained" << setw(12) << "Educated" << setw(10) << "R -> A" 
		<< setw(11) << "A -> T" << setw(11) << "T -> E" << setw(11) << "E -> R" << setw(10) << "Result" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 16; i++) {

		cout << setw(5) << Rocket[i] << " " << setw(10) << Astronaut[i] << " " << setw(10) << Trained[i] << " " << setw(10) << Educated[i] 
			<< " " << setw(10) << RA[i] << " " << setw(10) << AT[i] << " " << setw(10) << TE[i] << " " << setw(10) << ER[i];
	
		//Display invalid if the PROPOSITIONAL statements are ALL true, while the 
		//CONCLUSION statement is false. 
		if (RA[i] && AT[i] && TE[i] == true && ER[i] == false) {

			cout << setw(13) << "Inalid" << endl;
		}

		//Return Valid if true 
		else {

			cout << setw(13) << "Valid" << endl;
		}

		cout << "-----------------------------------------------------------------------------------------------" << endl;
	}

}

/*bool Implies takes two variables and returns true (1) or false (0)*/
bool Implies(bool a, bool b) {

	return !(a && !b);
}