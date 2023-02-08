#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus {
	private:
		string b_no, b_name, d_name;
		int b_seats;
	public:
		void menu();
		void new_bus();
		void view_bus();
		void single_view_bus();
		void all_view_bus();

};
	void bus::menu()
	{
		p:
		int choice;
		system("cls");
		cout<<"\n\t\t______BUS MANAGEMENT SYSTEM_____";
		cout<<"\n\n 1. ADD BUS RECORD";
		cout<<"\n 2. VIEW BUS DETAIL";
		cout<<"\n 3. UPDATE BUS DETAIL";
		cout<<"\n 4. DELETE BUS DETAIL";
		cout<<"\n 5. BUS ROUTES";
		cout<<"\n 6. BOOKING RECORD";
		cout<<"\n 7. SEAT RENOVATION";
		cout<<"\n 8. SEARCH BOOKING RECORD";
		cout<<"\n 9. UPDATE BOOKING RECORD";
		cout<<"\n 10. DELETE BOOKING RECORD";
		cout<<"\n 11. SHOW ALL BOOKING RECORD";
		cout<<"\n 12. EXIT";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				new_bus();
				break;
			case 2:
				view_bus();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				exit(0);
			default:
				cout<<"\n\n Invalid Choice. Please try again";
		}
		_getch();
		goto p;
	}
	void bus::new_bus()
	{
		p:
		system("cls");
		fstream file;
		string t_no, tb_name, td_name;
		int t_seats,found=0;
		cout<<"\n\t\t______BUS MANAGEMENT SYSTEM_____";
		cout<<"\n\n Bus No : ";
		cin>>b_no;
		cout<< "\n\n Bus Name : ";
		cin>>b_name;
		cout<<"\n\n Total Seats : ";
		cin>>b_seats;
		cout<<"\n\n Driver Name : ";
		cin>>d_name;
		file.open("bus.txt", ios::in);
		if (!file)
		{
			file.open("bus.txt",ios::app|ios::out);
			file<<b_no<<" "<<b_name<<" "<< b_seats<<" "<<d_name<< "\n";
			file.close();
		}
		else {
			file>>t_no>>tb_name>>t_seats>>td_name;
			while(!file.eof())
			{
				if (b_no == t_no)
				{
					found++;
				}
				file >> t_no >> tb_name >> t_seats >> td_name;
			}
			file.close();
			if (found == 0)
			{
				file.open("bus.txt",ios::app|ios::out);
				file<<b_no<<" " <<b_name<<" "<<b_seats<<" "<<d_name<< "\n";
				file.close();
			}
			else {
				cout << "\n\n Duplicate Record Found...";
				_getch();
				goto p;
			}
		}
		cout<<"\n\n New Bus registered";
	}
	void bus::view_bus()
	{
		p:
		system("cls");
		int choice;
		cout<<"\n\t\t______BUS MANAGEMENT SYSTEM_____";
		cout<<"\n\n 1. Single Bus View";
		cout<<"\n\n 2. All Bus View";
		cout<<"\n\n 3. Go back";
		cout<<"\n\n 1. Enter your choice";
		cin>>choice;
		switch (choice)
		{
			case 1:
				single_view_bus();
				break;
			case 2:
				all_view_bus();
				break;
			case 3:
				menu();
			default:
				cout<<"\n\n Invalid choice. Please Try Again.";
		}
		_getch();
		goto p;
	}
	void bus::single_view_bus()
	{
		system("cls");
		string t_no;
		fstream file;
		int found = 0;
		cout<<"\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		file.open("bus.txt", ios::in);
		if(!file)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{ 
			cout<<"\n\n Bus No. : ";
			cin>>t_no;
			file>>b_no>>b_name>>b_seats>>d_name;
			while(!file.eof())
			{
				if(t_no == b_no)
				{
					system("cls");
					cout<<"\n\t\t_______BUS MANAGEMENT SYSTEM_______"; ;
					cout<<"\n\n BUS NO. \tBUS NAME\tNO. OF SEATS\tDRIVERS NAME";
					cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
					found++;
				}
				file >> b_no >> b_name >> b_seats >> d_name;
			}
			file.close();
			if(found==0)
			{ 
				cout<<"\n\n Invalid Bus #";
			}
		}
	}
	void bus::all_view_bus()
	{
		system("cls");
		fstream file;
		cout<<"\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		file.open("bus.txt", ios::in);
		if (!file)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			cout<<"\n\n BUS NO. \tBUS NAME\tNO. OF SEATS\tDRIVERS NAME";
			file>>b_no>>b_name>>b_seats>>d_name;
			while (!file.eof())
			{
				cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<< d_name;
				file>>b_no>>b_name>>b_seats>>d_name;
			}
			file.close();
		}
	}
int main() {
	bus b;
	p:
	system("cls");
	string email,pass;
	char ch;
	cout<<"\n\n\t\t\t****LOGIN SYSTEM****";
	cout<<"\n\n Email : ";
	cin>>email;
	cout<<"\n\n Password : ";
	cin>>pass;
	if (email == "suarezcjn@gmail.com" && pass == "jessi")
	{
		cout<<"\n\n\n\t\t\tLoading";
		for (int i=1; i<=5; i++)
		{
			Sleep(500);
			cout<<".";
		}
		b.menu();
	}
	else
	{
		cout<<"\n\n\t\tInvalid match. Please try again.";
		_getch();
		goto p;
	}
}