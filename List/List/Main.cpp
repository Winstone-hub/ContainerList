// ** ContainerList v0.2

#include <iostream>

using namespace std;


struct List
{
	List* Front;
	int Value;
	List* Back;
};


void push_back(List* _Next, const int& _Value);
void insert(List* _Next, const int _Where, const int& _Value);
void erase(List* _Next, const int _Where);

void Output(const List* _Next);


int main(void)
{
	List* NumberList = new List;

	NumberList->Value = 0;
	NumberList->Back = nullptr;


	for (int i = 0; i < 10; ++i)
		push_back(NumberList, i * 10 + 10 );


	insert(NumberList, 2, 15);
	Output(NumberList);


	erase(NumberList, 2);
	Output(NumberList);


	return 0;
}

void push_back(List* _Next, const int& _Value)
{
	if (_Next->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Next->Back = Temp;
	}
	else
		push_back(_Next->Back, _Value);
}

void insert(List* _Next, const int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Value = _Value;

		Temp->Back = _Next->Back;
		_Next->Back = Temp;
	}
	else
		insert(_Next->Back, _Where - 1, _Value);
}


List* Front = nullptr;

void erase(List* _Next, const int _Where)
{
	if (_Where == 0)
	{
		/*
		List* Temp = _Next->Back;
		_Next->Back = _Next->Back->Back;
		*/

		Front->Back = _Next->Back;

		delete _Next;
		_Next = nullptr;
	}
	else
	{
		Front = _Next;
		erase(_Next->Back, _Where - 1);
	}
}

void Output(const List* _Next)
{
	cout << _Next->Value << endl;

	if (_Next->Back != nullptr)
		Output(_Next->Back);
}

