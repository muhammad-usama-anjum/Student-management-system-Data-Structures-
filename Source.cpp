/*LINE '87' FOR SEARCH STUDENT FUNCTION
  LINE '182' FOR CREATING NEW LIST
  LINE '478' FOR DELETING STUDENTS
*/
#include <iostream>
#include <string>
using namespace std;
class Node
{
private:
	string Name;
	string RegNo;
	string ProgramName;
	float CGPA;
public:
	Node* next{};
	Node* prev{};
	Node* newNext{};
	Node* newPrev{};
	Node() : Name(), RegNo(), ProgramName(), CGPA(), next(NULL), prev(NULL), newNext(NULL), newPrev(NULL) {}
	string Get_Name()
	{
		return Name;
	}
	string Get_Reg()
	{
		return RegNo;
	}
	string Get_PName()
	{
		return ProgramName;
	}
	float Get_CGPA()
	{
		return CGPA;
	}
	void Input()
	{
		cout << "ENTER NAME: ";
		cin.ignore();
		getline(cin, Name);
		cout << "ENTER REG#: ";
		cin >> RegNo;
		cout << "ENTER PROGRAM NAME: ";
		cin.ignore();
		getline(cin, ProgramName);
		cout << "ENTER CGPA: ";
		cin >> CGPA;
	}
	void Output()
	{
		cout << "STUDENT NAME: " << Name << endl;
		cout << "STUDENT REG#: " << RegNo << endl;
		cout << "STUDENT CGPA: " << CGPA << endl;
		cout << "PROGRAM NAME: " << ProgramName << endl;
	}
};

// 1.
class Stack
{
public:
	Node* top;
	Stack() : top(NULL) {}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	bool GetNode(Node* S)
	{
		Node* temp = top;
		bool Get = false;
		while (temp != NULL)
		{
			if (temp->Get_Reg() == S->Get_Reg())
			{
				Get = true;
				break;
			}
			temp = temp->next;
		}
		return Get;
	}
	bool SearchStudent(string Name) // Not included in assignment
	{
		Node* temp = top;
		bool Search = false;
		while (temp != NULL)
		{
			if (temp->Get_Name() == Name)
				Search = true;
			temp = temp->next;
		}
		if (Search == true)
			return true;
		else
			return false;
	}
	void push(Node* S)
	{
		if (isEmpty())
		{
			top = S;
			cout << "STUDENT PUSHED\n";
		}
		else if (GetNode(S))
		{
			cout << "STUDENT ALREADY EXISTS WITH REG#: " << S->Get_Reg() << endl;
		}
		else
		{
			top->prev = S;
			S->next = top;
			S->prev = NULL;
			top = S;
			cout << "STUDENT PUSHED\n";
		}
	}
	Node* pop()
	{
		Node* temp = NULL;
		if (top->next == NULL)
		{
			temp = top;
			top = NULL;
		}
		else
		{
			temp = top;
			top = top->next;
			top->prev = NULL;
		}
		return temp;
	}
	void Print()
	{
		cout << "ALL STUDENTS IN THE STACK\n";
		Node* temp = top;
		int i = 1;
		while (temp != NULL)
		{
			cout << "------------\nSTUDENT NO." << i << "\n------------\n";
			temp->Output();
			temp = temp->next;
			i++;
		}
	}
};

// 2.
class Queue
{
public:
	Node* rear;
	Node* front;
	Queue() : rear(NULL), front(NULL) {}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
			return true;
		else
			return false;
	}
	bool GetNode(Node* S)
	{
		Node* ptr = front;
		bool Get = false;
		while (ptr != NULL)
		{
			if (ptr->Get_Reg() == S->Get_Reg())
			{
				Get = true;
				break;
			}
			ptr = ptr->next;
		}
		return Get;
	}
	void CreateNewList(string PName) // Not included in assignment
	{
		Node* newFront = NULL;
		Node* newRear = NULL;
		Node* temp = front;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->Get_PName() == PName)
			{
				check = true;
				if (newFront == NULL && newRear == NULL)
				{
					newRear = temp;
					newFront = temp;
				}
				else
				{
					newRear->newNext = temp;
					temp->newPrev = newRear;
					newRear = temp;
				}
			}
			temp = temp->next;
		}
		if (check == true)
		{
			cout << "--------------------\nNEW LIST OF STUDENTS\n--------------------\n";
			Node* temp = newFront;
			int i = 1;
			while (temp != NULL)
			{
				cout << "-------------\nSTUDENT NO." << i << "\n-------------\n";
				temp->Output();
				temp = temp->newNext;
				i++;
			}
		}
		else
			cout << "PROGRAM NOT MATCHED!\n";
	}
	void enQueue(Node* S)
	{
		if (isEmpty())
		{
			rear = S;
			front = S;
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
		else if (GetNode(S))
		{
			cout << "STUDENT ALREADY EXISTS WITH REG#: " << S->Get_Reg() << endl;
		}
		else
		{
			rear->next = S;
			S->prev = rear;
			rear = S;
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
	}
	Node* deQueue()
	{
		Node* temp = NULL;
		if (front == rear)
		{
			temp = front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			temp = front;
			front = front->next;
			front->prev = NULL;
		}
		return temp;
	}
	void Print()
	{
		cout << "ALL STUDENTS IN THE STACK\n";
		Node* temp = front;
		int i = 1;
		while (temp != NULL)
		{
			cout << "------------\nSTUDENT NO." << i << "\n------------\n";
			temp->Output();
			temp = temp->next;
			i++;
		}
	}
};

// 3.
class CQueue
{
public:
	Node* rear;
	Node* front;
	CQueue() : rear(NULL), front(NULL) {}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
			return true;
		else
			return false;
	}
	bool GetNode(Node* S)
	{
		Node* ptr = front;
		bool Get = false;
		do
		{
			if (ptr->Get_Reg() == S->Get_Reg())
			{
				Get = true;
				break;
			}
			ptr = ptr->next;

		} while (ptr != front);

		return Get;
	}
	void enQueue(Node* S)
	{
		if (isEmpty())
		{
			rear = S;
			front = S;
			S->next = front;
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
		else if (GetNode(S))
		{
			cout << "STUDENT ALREADY EXISTS WITH REG#: " << S->Get_Reg() << endl;
		}
		else
		{
			rear->next = S;
			S->prev = rear;
			rear = S;
			S->next = front;
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
	}
	Node* deQueue()
	{
		Node* temp = NULL;
		if (front == rear)
		{
			temp = front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			temp = front;
			front = front->next;
			front->prev = NULL;
			rear->next = front;
		}
		return temp;
	}
	void Print()
	{
		cout << "ALL STUDENTS IN THE QUEUE\n";
		Node* temp = front;
		int i = 1;
		do
		{
			cout << "------------\nSTUDENT NO." << i << "\n------------\n";
			temp->Output();
			temp = temp->next;
			i++;

		} while (temp != front);
	}
};

// 4.
class PQueue
{
public:
	Node* Front;
	PQueue() : Front(NULL) {}
	bool isEmpty()
	{
		if (Front == NULL)
			return true;
		else
			return false;
	}
	bool GetNode(Node* S)
	{
		Node* temp = Front;
		bool Get = false;
		while (temp != NULL)
		{
			if (temp->Get_Reg() == S->Get_Reg())
			{
				Get = true;
				break;
			}
			temp = temp->next;
		}
		return Get;
	}
	void enQueue(Node* S)
	{
		if (isEmpty())
		{
			Front = S;
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
		else if (GetNode(S))
		{
			cout << "STUDENT ALREADY EXISTS WITH REG#: " << S->Get_Reg() << endl;
		}
		else
		{
			Node* temp = Front;
			if (S->Get_CGPA() > temp->Get_CGPA())
			{
				S->next = Front;
				Front->prev = S;
				Front = S;
			}
			else
			{
				while (temp->next != NULL && temp->next->Get_CGPA() >= S->Get_CGPA())
				{
					temp = temp->next;
				}
				S->next = temp->next;
				if (S->next != NULL)
				{
					S->next->prev = S;
				}
				S->prev = temp;
				temp->next = S;
			}
			cout << "STUDENT ENQUEUED SUCCESSFULLY!\n";
		}
	}
	Node* deQueue()
	{
		Node* temp = NULL;
		temp = Front;
		Front = Front->next;
		if (Front != NULL)
		{
			Front->prev = NULL;
		}
		return temp;
	}
	void Print()
	{
		cout << "ALL STUDENTS IN THE QUEUE\n";
		Node* temp = Front;
		int i = 1;
		while (temp != NULL)
		{
			cout << "------------\nSTUDENT NO." << i << "\n------------\n";
			temp->Output();
			temp = temp->next;
			i++;
		}
	}
};

// 5.
class DoublyLinkedList
{
public:
	Node* head;
	DoublyLinkedList() : head(NULL) {}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	Node* GetNode(string Reg)
	{
		Node* temp = NULL;
		Node* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->Get_Reg() == Reg)
				temp = ptr;
			ptr = ptr->next;
		}
		return temp;
	}
	void deleteStudents(float CGPA)  // Not included in assignment
	{
		Node* curr = head;
		Node* index = NULL;
		Node* temp = NULL;
		int count = 0;
		cout << "-------------------------------------------------------\nSTUDENTS DELETED WHO HAS CGPA LESS THEN THE CGPA PASSED\n-------------------------------------------------------\n";
		if (head->Get_CGPA() < CGPA)
		{
			cout << "------------\nSTUDENT No." << count + 1 << "\n------------\n";
			head->Output();
			head = head->next;
			head->prev = NULL;
			count++;
		}
		else
		{
			while (curr != NULL)
			{
				temp = curr;
				index = curr->next;
				while (index != NULL)
				{
					if (curr->Get_CGPA() < CGPA || index->Get_CGPA() < CGPA)
					{
						cout << "-------------\nSTUDENT No." << count + 1 << "\n-------------\n";
						index->Output();
						if (index->next != NULL)
						{
							index->next->prev = temp;
						}
						temp->next = index->next;
						count++;
					}
					else
					{
						temp = index;
					}
					index = index->next;
				}
				curr = curr->next;
			}
		}
		if (count > 0)

			cout << "----------------\nTotal STUDENTS: " << count << "\n----------------\n";
		else
			cout << "NO STUDENTS WITH LESS THAN THE PASSED CGPA\n";
	}
	void appendNode(Node* S)
	{
		if (GetNode(S->Get_Reg()) != NULL)
		{
			cout << "STUDENT ALREADY EXISTS WITH REG#: " << S->Get_Reg() << endl;
			return;
		}
		else
		{
			if (isEmpty())
			{
				head = S;
				cout << "STUDENT APPENDED\n";
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = S;
				S->prev = ptr;
				cout << "STUDENT APPENDED\n";
			}
		}
	}
	void deleteNode(string Reg)
	{
		Node* ptr = GetNode(Reg);
		if (ptr == NULL)
		{
			cout << "NO STUDENT EXISTS WITH REG#: " << Reg << endl;
			return;
		}
		else
		{
			if (head->Get_Reg() == Reg)
			{
				head = head->next;
				cout << "STUDENT DELETED AT START\n";
			}
			else
			{
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->prev;
				if (nextNode == NULL)
				{
					prevNode->next = NULL;
					cout << "STUDENT DELETED AT END\n";
				}
				else
				{
					prevNode->next = nextNode;
					nextNode->prev = prevNode;
					cout << "STUDENT DELETED IN BETWEEN\n";
				}
			}
		}
	}
	void Print()
	{
		cout << "ALL STUDENTS IN THE LIST\n";
		Node* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			cout << "------------\nSTUDENT NO." << i << "\n------------\n";
			temp->Output();
			temp = temp->next;
			i++;
		}
	}
};
int main()
{
	Stack St;
	Queue Q;
	CQueue CQ;
	PQueue PQ;
	DoublyLinkedList DL;
	char ch;
	string Name;
	string Reg;
	float CGPA;
	do
	{
		system("cls");
		cout << "-----------------------------------\nENTER YOUR CHOICE OF DATA STRUCTURE\n-----------------------------------\n";
		cout << "1) Stack \n2) Queue \n3) List \ne) Exit\n";
		cin >> ch;
		switch (ch)
		{
		case 'e':
		case 'E':
			cout << "Exited!";
			break;
		case '1':
			do
			{
				system("cls");
				cout << "1) Push \n2) Pop \n3) Search \n4) Display \n0) Return\n";
				cin >> ch;
				Node* Student = new Node();
				if (ch == '1')
				{
					cout << "----------------------------\nENTER DETAILS OF THE STUDENT\n----------------------------\n";
					Student->Input();
					St.push(Student);
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '2')
				{
					if (!St.isEmpty())
					{
						Student = St.pop();
						cout << "---------------\nDELETED STUDENT\n---------------\n";
						Student->Output();
						delete Student;
					}
					else
						cout << "STACK IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '3')
				{
					if (!St.isEmpty())
					{
						cout << "ENTER NAME OF THE STUDENT TO SEARCH: ";
						cin.ignore();
						getline(cin, Name);
						if (St.SearchStudent(Name))
							cout << "STUDENT FOUND!\n";
						else
							cout << "STUDENT NOT FOUND!\n";
					}
					else
						cout << "STACK IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '4')
				{
					if (!St.isEmpty())
					{
						St.Print();
					}
					else
						cout << "STACK IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else
					cout << "INVALID OPTION\n";
			} while (ch != '0');
			break;
		case '2':
			do
			{
				system("cls");
				cout << "--------------------\nCHOOSE TYPE OF QUEUE\n--------------------\n";
				cout << "a. Classical Queue \nb. Circular Queue \nc. Priority Queue \n0. Return\n";
				cin >> ch;
				switch (ch)
				{
				case '0':
					break;
				case 'a':
				case 'A':
					do
					{
						system("cls");
						cout << "1) Enqueue \n2) Dequeue \n3) Create New List \n4) Display \n0) Return\n";
						cin >> ch;
						Node* Student = new Node();
						if (ch == '1')
						{
							cout << "----------------------------\nENTER DETAILS OF THE STUDENT\n----------------------------\n";
							Student->Input();
							Q.enQueue(Student);
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '2')
						{
							if (!Q.isEmpty())
							{
								Student = Q.deQueue();
								cout << "---------------\nDELETED STUDENT\n---------------\n";
								Student->Output();
								delete Student;
							}
							else
								cout << "QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '3')
						{
							if (!Q.isEmpty())
							{
								cout << "ENTER NAME OF THE DEPARTMENT TO CREATE NEW LIST: ";
								cin >> Name;
								Q.CreateNewList(Name);
							}
							else
								cout << "QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '4')
						{
							if (!Q.isEmpty())
							{
								Q.Print();
							}
							else
								cout << "QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else
							cout << "INVALID OPTION\n";
					} while (ch != '0');
					break;
				case 'b':
				case 'B':
					do
					{
						system("cls");
						cout << "1) Enqueue \n2) Dequeue \n3) Display \n0) Return\n";
						cin >> ch;
						Node* Student = new Node();
						if (ch == '1')
						{
							cout << "----------------------------\nENTER DETAILS OF THE STUDENT\n----------------------------\n";
							Student->Input();
							CQ.enQueue(Student);
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '2')
						{
							if (!CQ.isEmpty())
							{
								Student = CQ.deQueue();
								cout << "---------------\nDELETED STUDENT\n---------------\n";
								Student->Output();
								delete Student;
							}
							else
								cout << "CIRCULAR QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '3')
						{
							if (!CQ.isEmpty())
							{
								CQ.Print();
							}
							else
								cout << "CIRCULAR QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else
							cout << "INVALID OPTION\n";
					} while (ch != '0');
					break;
				case 'c':
				case 'C':
					do
					{
						system("cls");
						cout << "1) Enqueue \n2) Dequeue \n3) Display \n0) Return\n";
						cin >> ch;
						Node* Student = new Node();
						if (ch == '1')
						{
							cout << "----------------------------\nENTER DETAILS OF THE STUDENT\n----------------------------\n";
							Student->Input();
							PQ.enQueue(Student);
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '2')
						{
							if (!PQ.isEmpty())
							{
								Student = PQ.deQueue();
								cout << "---------------\nDELETED STUDENT\n---------------\n";
								Student->Output();
								delete Student;
							}
							else
								cout << "PRIORITY QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else if (ch == '3')
						{
							if (!PQ.isEmpty())
							{
								PQ.Print();
							}
							else
								cout << "PRIORITY QUEUE IS EMPTY\n";
							cout << "Press any key to continue...";
							cin.ignore();
							cin.get();
						}
						else
							cout << "INVALID OPTION\n";
					} while (ch != '0');
					break;
				default:
					cout << "Enter proper option number\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
			} while (ch != '0');
			break;
		case '3':
			do
			{
				system("cls");
				cout << "1) Append \n2) Delete \n3) Delete Students \n4) Display \n0) Return\n";
				cin >> ch;
				Node* Student = new Node();
				if (ch == '1')
				{
					cout << "----------------------------\nENTER DETAILS OF THE STUDENT\n----------------------------\n";
					Student->Input();
					DL.appendNode(Student);
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '2')
				{
					if (!DL.isEmpty())
					{
						cout << "ENTER REG# OF THE STUDENT TO DELETE: ";
						cin >> Reg;
						DL.deleteNode(Reg);
						delete Student;
					}
					else
						cout << "LIST IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '3')
				{
					if (!DL.isEmpty())
					{
						cout << "ENTER CGPA TO DELETE STUDENTS LESS THAN THE ENTERED CGPA: ";
						cin >> CGPA;
						DL.deleteStudents(CGPA);
					}
					else
						cout << "LIST IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else if (ch == '4')
				{
					if (!DL.isEmpty())
					{
						DL.Print();
					}
					else
						cout << "LIST IS EMPTY\n";
					cout << "Press any key to continue...";
					cin.ignore();
					cin.get();
				}
				else
					cout << "INVALID OPTION\n";
			} while (ch != '0');
			break;
		default:
			cout << "Enter proper option number\n";
			cout << "Press any key to continue...";
			cin.ignore();
			cin.get();
		}

	} while (ch != 'e' && ch != 'E');

	cout << "\nPROGRAM ENDED...";
	return 0;
}