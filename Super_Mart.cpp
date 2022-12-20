#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout << "\t\t\t\t_____________________________________________________________\n";
	cout << "\t\t\t\t															  \n";
	cout << "\t\t\t\t												              \n";
	cout << "\t					 Supermarket Main Menu			     	  \n";
	cout << "\t\t\t\t													          \n";
	cout << "\t\t\t\t_____________________________________________________________\n";
	cout << "\t\t\t\t|	1)	Administrator \t|\n";
	cout << "\t\t\t\t| 					    |\n";
	cout << "\t\t\t\t|	2)	Buyer		  \t|\n";
	cout << "\t\t\t\t| 					    |\n";
	cout << "\t\t\t\t|	3)	Exit		  \t|\n";
	cout << "\t\t\t\t| 					    |\n";
	cout << "\t\t\t\t Please enter your choice : ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			cout << "\t\t\t Please Login \n";
			cout << "\t\t\t Enter Email 	\n";
			cin >> email;
			cout << "\t\t\t Password		\n";
			cin >> password;
			
			if(email == "sajalruhela@gmail.com" && password == "sajal@123")
			{
				administrator();
			}
			else
			{
				cout << "Invalid email/password";
			}
			break;
			
		case 2:
			{
				buyer();
			}
			
		case 3:
			{
				exit(0);
			}
			
		default:
			cout << "Please enter a valid choice from the given options.";
	}
	goto m;	
}

void shopping :: administrator()
{
	m:
	int choice;
	cout << "\n\n\n\t\t\t Administrator Menu";
	cout << "\n\t\t\t\t|_____1) Add the product_____|";
	cout << "\n\t\t\t\t|							|";
	cout << "\n\t\t\t\t|_____2) Modify the product__|";
	cout << "\n\t\t\t\t|							|";
	cout << "\n\t\t\t\t|_____3) Delete the product__|";
	cout << "\n\t\t\t\t|							|";
	cout << "\n\t\t\t\t|_____4) Back to Main Menu___|";
	
	cout << "\n\n\t Please enter your choice : ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
			
		case 3:
			rem();
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout << "INVALID CHOICE!" << endl;
	}
	goto m;
}

void shopping::buyer()
{
	m:
	int choice;
	cout << "\t\t\t  Buyer \n";
	cout << "\t\t\t_________________\n";
	cout << "						\n";
	cout << "\t\t\t 1) Buy product  \n";
	cout << "					  	  ";
	cout << "\t\t\t 2) Go Back		\n";
	cout << "					  	  ";
	cout << "\t\t\t Enter your choice : \n";
	
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default:
			cout << "INVALID CHOICE!" << endl;
	}
	goto m;
}

void shopping::add()
{
	m:
	fstream data;
	int c, token = 0;
	float p, d;
	string n;
	
	cout << "\n\n\t\t\t Add new product";
	cout << "\n\n\t Product code of the product ";
	cin >> pcode;
	cout << "\n\n\t Name of the product ";
	cin >> pname; 
	cout << "\n\n\t Proce of the product";
	cin >> price;
	cout << "\n\n\t Discount on product";
	cin >> dis;
	
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		data.open("databse.txt", ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
		data.close();
	} 
	else
	{
		data >> c >> n >> p >> d;
		while(!data.eof())
		{
			if(c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();
		if(token)
		{
			goto m;
		}
		else
		{
			data.open("database.txt", ios::app|ios::out);
			data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
			data.close();
		}
	}
	cout << "\n\n\t\t  Record inserted !";
}

void shopping::edit()
{
	fstream data, data1;
	int pkey, token = 0, c;
	float p, d;
	string n;
	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Product code : ";
	cin >> pkey;
	
	data.open("database.txt ", ios::in);
	if(!data)
	{
		cout << "\n\nFile doesn't exist! ";
	}
	else
	{
		data1.open("database1.txt" , ios::app|ios::out);
		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout << "\n\t\t Product new code :";
				cin >> c;
				cout << "\n\t\t Name of the product : ";
				cin >> n;
				cout << "\n\t\t Price : ";
				cin >> p;
				cout << "\n\t\t Discount : ";
				cin >> d;
				data << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record Edited! ";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; 
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt" , "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n Record not found. Sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data, data1;
	int pkey, token = 0;
	cout << "\n\n\t Delete Product ";
	cout << "\n\n\t Product Code : ";
	cin >> pkey;
	data.open("databse.txt", ios::in);
	if(!data)
	{
		cout << "File doesn't exist";
	}
	else
	{
		data1.open("databse1.txt" , ios::app|ios::out);
		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pcode == pkey)
			{
				cout << "\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt" , "database.txt");
		if(token == 0)
		{
			cout << "\n\n Record not found";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.text" , ios::in);
	cout << "\n\n_______________________________________________________________\n";
	cout << "ProNo\t\tName\t\tPrice\n";
	cout << "\n\n_______________________________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while(!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;
	int arrc[100], arrq[100];
	char choice;
	int c = 0;
	float amount = 0, dis = 0, total = 0;
	
	cout << "\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt" , ios::in);
	if(!data)
	{
		cout << "\n\n Empty Database "; 
	}
	else
	{
		data.close();
		list();
		cout << "\n_______________________________________________________\n";
		cout << "\n|													  \n";
		cout << "\n					Please place your order				  \n";
		cout << "\n|													  \n";
		cout << "\n_______________________________________________________\n";
		do
		{
			m:
			cout << "\n\nEnter Product code : ";
			cin >> arrc[c];
			cout << "\n\Enter the product quantity : ";
			cin >> arrq[c];
			for(int i = 0; i < c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;	
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? If yes, then press y else press no\n";
			cin >> choice;
		}while(choice == 'y');
		
		cout << "\n\n\t\t\t____________________RECEIPT___________________\n";
		cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with Discount\n";
		for(int i = 0; i < c; i++)
		{
			data.open("database.txt" , ios::in);
			data >> pcode >> pname >> price >> dis;
			while(!data.eof())
			{
				if(pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total += dis;
					cout << "\n" << pcode << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
		}
		data.close();
	} 
 	cout << "\n\n____________________________________________________________________";
 	cout << "\n Total Amount : " << total;
}

int main()
{
	shopping s;
	s.menu();
}
