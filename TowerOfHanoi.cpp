#include <iostream>
using namespace std;


//Array implementation of stack
class Stack
{

	int SIZE;

public:
	int *intarr;
	int TOP;

	Stack();
	Stack(int size);

	void push(int elem);
	int pop();

	int getelem();

};

Stack::Stack()
{
	TOP=0;
	SIZE = 5;
	intarr = new int[SIZE];
	cout << "\n\n Stack initialized with space of 5 elements!";
}

Stack::Stack(int size)
{
	intarr = new int[SIZE];
	cout << "\n\n Stack initialized with space of " << SIZE << " elements!";
}

void Stack::push(int elem)
{
	//check for overflow
	if (TOP == SIZE)
	{
		cout << "\n\n Stack Overflow, can't push element now!";
		return;
	}
	intarr[TOP] = elem;
	TOP++;
	cout << "\n\n " << elem << " has pushed to stack!";
}

int Stack::pop()
{
	//check for underflow
	if (TOP == 0)
	{
		cout << "\n\n Stack is Empty, can't pop element now!";
		return -1;
	}
	TOP--;
	return intarr[TOP];

}

int Stack::getelem()
{
	//check for underflow
	if (TOP == 0)
	{
		return -1;
	}
	return intarr[TOP-1];
}

/*
 - Tower of Hanoi simulation contains three stacks(pegs) A,B and C
 - At start, Peg A contains N disks
 - The target is to transfer all N disks from Peg A to Peg C with minimum possible moves
*/

class HanoiTowerSimulation
{
	Stack A, B, C;
	int NumOfDisks,Moves;

public:

	HanoiTowerSimulation(); //By default, we consider 3 disks
	HanoiTowerSimulation(int disks); //Dynamic number of disks

	void setupPegs();
	void viewPegs();
	void moveDisks();
	unsigned int numOfMoves();
	void T(int numOfDisks, Stack *Start, Stack *Aux, Stack *End);
};

HanoiTowerSimulation::HanoiTowerSimulation()
{
	NumOfDisks = 3;
}

HanoiTowerSimulation::HanoiTowerSimulation(int disks)
{
	NumOfDisks = disks;
}

void HanoiTowerSimulation::setupPegs()
{
	for (int i = 0; i < NumOfDisks; i++)
	{
		A.push(i + 1);
	}
}

void HanoiTowerSimulation::viewPegs()
{
	//View of Tower of Hanoi

	system("cls");

	cout << "\n\n\t------------------------------------------------------------------------------";
	cout << "\n\n\n";

	cout << "\t| \t|\t| \t|\t| \t|";
	cout << "\n\t| \t|\t| \t|\t| \t|";
	cout << "\n\t| \t|\t| \t|\t| \t|";
	int m[3] = { 0, 0, 0 }, n[3] = { 0, 0, 0 }, o[3] = { 0, 0, 0 };
	if (HanoiTowerSimulation::A.TOP == NumOfDisks)
	{
		m[0] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 1]; m[1] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 2]; m[2] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 3];
	
	}
	else if (HanoiTowerSimulation::A.TOP == NumOfDisks - 1)
	{
		m[0] = 0; m[1] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 1]; m[2] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 2];
	
	}
	else if (HanoiTowerSimulation::A.TOP == NumOfDisks - 2)
	{
		m[0] =m[0]=0 ;  m[1] = 0; m[2] = HanoiTowerSimulation::A.intarr[HanoiTowerSimulation::A.TOP - 1];
	}

	if (HanoiTowerSimulation::B.TOP == NumOfDisks)
	{
		n[0] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 1]; n[1] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 2]; n[2] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 3];
	
	}
	else if (HanoiTowerSimulation::B.TOP == NumOfDisks - 1)
	{
		n[0] = 0; n[1] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 1]; n[2] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 2];
	
	}
	else if (HanoiTowerSimulation::B.TOP == NumOfDisks - 2)
	{
		n[0] = 0; n[1] = 0; n[2] = HanoiTowerSimulation::B.intarr[HanoiTowerSimulation::B.TOP - 1];
	
	}

	if (HanoiTowerSimulation::C.TOP == NumOfDisks)
	{
		o[0] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 1]; o[1] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 2]; o[2] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 3];
	
	}
	else if (HanoiTowerSimulation::C.TOP == NumOfDisks - 1)
	{
		o[0] = 0; o[1] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 1]; o[2] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 2];
	
	}
	else if (HanoiTowerSimulation::C.TOP == NumOfDisks - 2)
	{
		o[0] = 0; o[1] = 0; o[2] = HanoiTowerSimulation::C.intarr[HanoiTowerSimulation::C.TOP - 1];
	
	}
	for (int i = 0; i < NumOfDisks; i++)
	{
		

		cout << "\n\t|" << m[i] << "\t|\t|" << n[i] << "\t|\t|" << o[i] << "\t|";
		cout << "\n\t| \t|\t| \t|\t| \t|";
	}
	cout << "\n      -------------   -------------   -------------";
	cout << "\n      -------------   -------------   -------------";
}

void HanoiTowerSimulation::T(int numOfDisks, Stack *Start, Stack *Aux, Stack *End)
{
	if (numOfDisks == 1)
	{
		cout << endl;
		cout << "\n Press enter for next move... ";
		system("pause");
		End->push(Start->pop());
		system("cls");
		viewPegs();
		return;
	}

	T(numOfDisks - 1, Start, End, Aux);
	T(1, Start, Aux, End);
	T(numOfDisks - 1, Aux, Start, End);
}

void HanoiTowerSimulation::moveDisks()
{
	//algorithm of Tower of Hanoi minimum moves
	T(NumOfDisks, &A, &B, &C);	
}

unsigned int HanoiTowerSimulation::numOfMoves()
{
	//to determine minimum number of moves this algo will take to solve the problem
	return ((1<<NumOfDisks)-1);
}

int main()
{
	HanoiTowerSimulation sim(3);	//default 3 disks to move from A to C
	sim.setupPegs();
	system("cls");
	sim.viewPegs();
	sim.moveDisks();
	cout <<"\n\n\n *** Total number of moves : "<<sim.numOfMoves()<<endl<<endl;


}