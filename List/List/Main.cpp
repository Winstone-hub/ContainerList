// ** ContainerList v0.3

#include <iostream>

using namespace std;


struct List
{
	List* Front;
	int Value;
	List* Back;
};

List* CreateList(const int _Value);
void push_back(List* _Current, const int& _Value);
void pop_back(List* _Current);
void insert(List* _Current, const int _Where, const int& _Value);
void erase(List* _Current, const int _Where);

void OutputA(const List* _Current);
void OutputB(const List* _Current);

List* End = nullptr;

int main(void)
{
	List* NumberList = CreateList(0);

	for (int i = 0; i < 10; ++i)
		push_back(NumberList, i * 10 + 10 );

	insert(NumberList, 2, 15);
	OutputA(NumberList);

	erase(NumberList, 2);
	OutputA(NumberList);

	system("pause");
	system("cls");

	OutputB(End);

	pop_back(NumberList);
	OutputA(NumberList);

	return 0;
}

List* CreateList(const int _Value)
{
	List* pList = new List;

	pList->Front = nullptr;
	pList->Value = _Value;
	pList->Back = nullptr;

	return pList;
}

void push_back(List* _Current, const int& _Value)
{
	if (_Current->Back == nullptr)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = nullptr;

		_Current->Back = Temp;
		End = Temp;
	}
	else
		push_back(_Current->Back, _Value);
}

void pop_back(List* _Current)
{
	if (_Current->Back == nullptr)
	{
		End = _Current->Front;

		_Current->Front->Back = nullptr;

		delete _Current;
		_Current = nullptr;
	}
	else
		pop_back(_Current->Back);
}

void insert(List* _Current, const int _Where, const int& _Value)
{
	if (_Where == 1)
	{
		List* Temp = new List;

		Temp->Front = _Current;
		Temp->Value = _Value;
		Temp->Back = _Current->Back;

		_Current->Back = Temp;
	}
	else
		insert(_Current->Back, _Where - 1, _Value);
}

void erase(List* _Current, const int _Where)
{
	if (_Where == 0)
	{
		_Current->Back->Front = _Current->Front;
		_Current->Front->Back = _Current->Back;

		delete _Current;
		_Current = nullptr;
	}
	else
		erase(_Current->Back, _Where - 1);
}

void OutputA(const List* _Current)
{
	cout << _Current->Value << endl;

	if (_Current->Back != nullptr)
		OutputA(_Current->Back);
}

void OutputB(const List* _Current)
{
	cout << _Current->Value << endl;

	if (_Current->Front != nullptr)
		OutputB(_Current->Front);
}
