#include <iostream>
using namespace std;

struct student
{
	int studentId;
	string studentName;
	string studentCourse;
	int studentYear;
	student *next;
};



student *front = NULL;
student *rear = NULL;
student *tmp;

void search()
{
	int dataId;
	string dataName;
	string dataCourse;
	int dataYear;
	int search_id(0);
	
	tmp = front;
	cout << "Enter Student ID: ";
	cin >> dataId;
	
	while (tmp != NULL)
	{
		if(tmp->studentId == dataId)
		{
			search_id = 1;
			
			break;
		}
		tmp = tmp->next;

	
	};
	
	if (search_id==1)
	{
		cout << "Student ID: " << tmp->studentId << endl
		     << "Student Name: " << tmp->studentName << endl
		     << "Student Course: " << tmp->studentCourse << endl
		     << "Student Year: " << tmp->studentYear;
		tmp->next = tmp;
		system("pause>0");
	}
	else{
			cout << "Student not Found";
			system("pause>0");
			
		}
	search_id = 0;
	tmp = front;

}

void insert()
{
	int dataId;
	string dataName;
	string dataCourse;
	int dataYear;
	
	//data gathering
	cout << "Enter Student ID: " << endl;
	cin >> dataId;
	cout << "Enter Student Name: " << endl;
	cin >> dataName;
	cout << "Enter Student Course: " << endl;
	cin >> dataCourse;
	cout << "Enter Student Year: " << endl;
	cin >> dataYear;

	
	//
	if(rear == NULL)//1st data
	{
		rear = new student;
		
		rear->studentId = dataId;
		rear->studentName = dataName;
		rear->studentCourse = dataCourse;
		rear->studentYear = dataYear;
		
		rear->next = NULL;
		front= rear;
	}
	else
	{
		tmp = new student;
		rear->next = tmp;
		
		tmp->studentId = dataId;
		tmp->studentName = dataName;
		tmp->studentCourse = dataCourse;
		tmp->studentYear = dataYear;
		
		tmp->next = NULL;
		
		rear = tmp;//mapunta sa rear yung value
	}
	
}

void deleted()
{
	tmp = front;
	if(front != NULL)
	{
		if(tmp->next != NULL)
		{
			tmp = tmp->next;
			cout << "Student ID will be delete: " << front->studentId << endl
			     << "Student Name: " << front->studentName << endl
			     << "Student Course: " << front->studentCourse << endl
			     << "Student Year: " << front->studentYear << endl;
			delete front;
			front = tmp; //frinont na yung susunod na value
		}
		else //pang last na value
		{
			cout << "Student ID will be delete: " << front->studentId << endl
			     << "Student Name: " << front->studentName << endl
			     << "Student Course: " << front->studentCourse << endl
			     << "Student Year: " << front->studentYear << endl;
			delete front;
			//empty na yung queue
			front = NULL;
			rear = NULL;
		}
	}
	else
	{
		cout << "The Queue is Empty" << endl;
		return;
	}
}


void display()
{
	tmp = front;
	if((front == NULL) && (rear == NULL))
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Students: " << endl;
	while(tmp != NULL)
	{
		cout << tmp->studentId  << " "
		     << tmp->studentName << " "
		     << tmp->studentCourse << " "
		     << tmp->studentYear << " " << endl;
		tmp = tmp->next;
	}
}

int main()
{
		int n;
	do{
	

	system("CLS");
	cout << "|Student System| Queue Implementation" << endl;
	cout << "[1] Insert" << endl
	     << "[2] Delete" << endl
	     << "[3] Display" << endl
	     << "[4] Exit" << endl
		 << "[5] Search" << endl;

		cout << "Choice: ";
		cin >> n;
		switch(n)
		{
			case 1:
			system("CLS");
			insert();
			break;
			case 2: 
			system("CLS");
			deleted();
			system("pause");
			break;
			case 3: 
			system("CLS");
			display();
			system("pause");
			break;
			case 4: cout << "Exit" << endl;
			break;
			case 5: 
			system("CLS");
			search();
			break;
			default: cout << "Invalid" << endl;
		}
	}
	while(n != 4);
	return 0;
}
 

