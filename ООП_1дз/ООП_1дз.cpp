#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

#define TASK 2  // поменяйте значение TASK что бы разблоуировать задание 

#if TASK == 1
class Counter
{
	int Start;
	int End;

public:

	Counter(){//конструктор по умолчанию

		Start = 0;
		End = 0;
	}

	Counter(int start,int end){//конструктор с параметрами 
	
		Start = start;
		End = end;
	}

	void setStart(int start) {

		Start = start;
	}
	void setEnd(int end) {

		End = end;
	}


	void Run(chrono::milliseconds delay) {

		for (int i = Start; i <= End; i++)
		{
			system("cls");

			cout << "Counter: " << i;
			this_thread::sleep_for(delay);

			if (i == End) {
				i = Start - 1; 
			}
		}		
	}
};

#elif TASK == 2
class Elevator
{
	int FirstFloor;
	int LastFloor;
	int CurrentFloor;

public:
	Elevator() {//конструктор по умолчанию
		FirstFloor = 1;
		LastFloor = 1;
		CurrentFloor = 1;

	}

	Elevator(int firstFloor, int lastFloor, int currentFloor) {//конструкор с параметрами 

		FirstFloor = firstFloor;
		LastFloor = lastFloor;
		CurrentFloor = currentFloor;

	}

	void SetFirstFloot(int firstFloor) {//Приневаем значение 


		FirstFloor = firstFloor;
	}

	void SetLastFloot(int lastFloor) {//Принимаем значение 

		LastFloor = lastFloor;
	}

	void SetCurrentFloor(int currentFloor) {//Принимаем значение текущего этажа 

		CurrentFloor = currentFloor;
	}

	void moveElevator(int floor) {//Метод передвижения лифта 

		if (floor >= FirstFloor && floor <= LastFloor)
		{
			cout << "Moving to floor " << floor << endl;
			CurrentFloor = floor;
		}
		else {
			cout << "Error. Try again" << endl;
		}
	}

	int GetCurrentFloor() {//Возвращаем значение текущего этажа, что бы оповестить пользователя 
		
		return CurrentFloor;
	}

};

#endif

int main()
{
#if TASK == 1

	Counter range;
	range.setStart(1);
	range.setEnd(10);
	range.Run(chrono::milliseconds(500));


#elif TASK == 2
	Elevator elevator;
	elevator.SetFirstFloot(1);//устонавливаем 1 этаж(устонавливаем его ведь могут быть и минусовые этажи)
	elevator.SetLastFloot(20);//устонавливаем последний этаж
	elevator.SetCurrentFloor(2);//устонавливаем текущий этаж


	int floor;

	floor = elevator.GetCurrentFloor();

	cout << "Current Floor:" << floor << endl;
	cout << "Enter floor: ";
	cin >> floor;

	elevator.moveElevator(floor);//передаем этаж на который хотим переместиться 


#endif
	
	return 0;
}







