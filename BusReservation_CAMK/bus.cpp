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
		void update_bus();
		void del_bus();
		void rout_bus();
		void detail_bus();
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
		cout << "\n 6. BUS SEAT DETAILS";
		cout<<"\n 7. BOOKING RECORD";
		cout<<"\n 8. SEAT RENOVATION";
		cout<<"\n 9. SEARCH BOOKING RECORD";
		cout<<"\n 10. UPDATE BOOKING RECORD";
		cout<<"\n 11. DELETE BOOKING RECORD";
		cout<<"\n 12. SHOW ALL BOOKING RECORD";
		cout<<"\n 13. EXIT";
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
				update_bus();
				break;
			case 4:
				del_bus();
				break;
			case 5:
				rout_bus();
				break;
			case 6:
				detail_bus();
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
				break;
			case 13:
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
	void bus::update_bus()
	{
		system("cls");
		fstream file,file1;
		string t_no,no,t_name,td_name;
		int t_seats,found=0;
		cout<<"\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		file.open("bus.txt", ios::in);
		if (!file)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			cout<<"\n\n Bus No. ...";
			cin>>t_no;
			file1.open("bus1.txt", ios::app|ios::out);
			file>>b_no>>b_name>>b_seats>>d_name;
			while(!file.eof())
			{
				if (t_no == b_no)
				{
					cout<<"\n\n New Bus No. : ";
					cin>>no;
					cout<<"\n\n Bus Name: ";
					cin>>t_name;
					cout<<"\n\n No. of Seats: ";
					cin>>t_seats;
					cout<<"\n\n Driver Name: ";
					cin>>td_name;
					file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
					cout<<"\n\n\n Update Bus Record Successfully";
					found++;
				}
				else
				{
					file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
				}
				file>>b_no>>b_name>>b_seats>>d_name;
			}
			file.close();
			file1.close();
			remove("bus.txt");
			rename("bus1.txt","bus.txt");
			if (found==0)
			{
				cout<<"\n\n Bus number is invalid ...";
			}
		}
	}
	void bus::rout_bus()
	{
		p:
		system("cls");
		int choice;
		cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		cout << "\n\n 1. 1st ROUT DETAILS";
		cout << "\n\n 2. 2nd ROUT DETAILS";
		cout << "\n\n 3. 3rd ROUT DETAILS";
		cout << "\n\n 4. 4th ROUT DETAILS";
		cout << "\n\n 5. 5th ROUT DETAILS";
		cout << "\n\n Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				system("cls");
				cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
				cout << "\n\n   From Pietarsaari to Kalajoki";
				cout << "\n  9:00 am ...................  11:00 am";
				cout << "\n   From Kouvola to Rovaniemi";
				cout << "\n  12:00 pm ...................  2:30 pm";
				cout << "\n   From Seinajoki to Kaustinen";
				cout << "\n  4:00 am ....................  9:00 am";
				cout << "\n   From Kalajoki to Kokkola";
				cout << "\n  9:00 am ...................  2:00 pm";
				cout << "\n   From Oulu to Turku";
				cout << "\n  10:00 am ...................  11:30 am";
				cout << "\n   From Lahti to Seinajoki";
				cout << "\n  8:30 am ...................  10:00 am";
				break;
			case 2:
				system("cls");
				cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
				cout << "\n\n   From Pietarsaari To Tampere";
				cout << "\n  9:00 am ...................  10:00 am";
				cout << "\n   From Kalajoki To Kaustinen";
				cout << "\n  12:00 pm ...................  1:00 pm";
				cout << "\n   From Oulu To Turku";
				cout << "\n  10:00 pm ...................  11:00 pm";
				break;
			case 3:
				system("cls");
				cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
				cout << "\n\n   From Kouvola To Lahti";
				cout << "\n  8:30 am ...................  9:30 am";
				cout << "\n   From Kalajoki To Tampere";
				cout << "\n  1:00 pm ...................  2:30 pm";
				cout << "\n   From Lahti To Kouvola";
				cout << "\n  4:00 pm ....................  4:30 pm";
				cout << "\n   From Kaustinen To Kuopio";
				cout << "\n  7:00 am ...................  12:00 pm";
				cout << "\n   From Pietarsaari To Kruunupyy";
				cout << "\n  8:00 am ...................  10:00 am";
				break;
			case 4:
				system("cls");
				cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
				cout << "\n\n   From Turku To Lahti";
				cout << "\n  1:00 pm ...................  10:00 pm";
				cout << "\n   From Pietarsaari To Kalajoki";
				cout << "\n  8:00 pm ...................  10:30 pm";
				cout << "\n   From Tampere To Rovaniemi";
				cout << "\n  11:00 am ....................  1:30 pm";
				cout << "\n   From Pietarsaari To Oulu";
				cout << "\n  5:00 pm ...................  10:00 pm";
				cout << "\n   From Kalajoki To Kokkola";
				cout << "\n  6:00 pm ...................  11:00 am";
				cout << "\n   From Kuopio To Tampere";
				cout << "\n  7:30 am ...................  5:00 pm";
				cout << "\n   From Oulu To Kalajoki";
				cout << "\n  9:00 am ...................  5:00 pm";
				break;
			case 5:
				system("cls");
				cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
				cout << "\n\n   From Kokkola To Kalajoki";
				cout << "\n  8:00 pm ...................  12:00 am";
				cout << "\n   From Lahti To Rovaniemi";
				cout << "\n  11:00 pm ...................  3:30 am";
				cout << "\n   From Pietarsaari To Turku";
				cout << "\n  3:30 am ...................  5:00 am";
				cout << "\n   From Pietarsaari To Oulu";
				cout << "\n  7:30 am ...................  5:00 pm";
				break;
			default:
				cout << "\n\n Invalid Choice ... Please Try Again";
				_getch();
				goto p;
		}


	}
	void bus::del_bus()
	{
		system("cls");
		fstream file, file1;
		string t_no;
		int found = 0;
		cout<<"\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		file.open("bus.txt", ios::in);
		if (!file)
		{
			cout << "\n\n File Opening Error...";
		}
		else
		{
			cout << "\n\n Bus No. ...";
			cin >> t_no;
			file1.open("bus1.txt", ios::app | ios::out);
			file >> b_no >> b_name >> b_seats >> d_name;
			while (!file.eof())
			{
				if (t_no == b_no)
				{
					cout << "\n\n\n Delete Record Successfully";
					found++;
				}
				else
				{
					file1 << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
				}
				file >> b_no >> b_name >> b_seats >> d_name;
			}
			file.close();
			file1.close();
			remove("bus.txt");
			rename("bus1.txt", "bus.txt");
			if (found == 0)
			{
				cout << "\n\n Bus number is invalid ...";
			}
		}
	}
	void bus::detail_bus()
	{
		system("cls");
		fstream file, file1;
		string t_no,s_b_no,s_no;
		int count = 0, found=0;
		cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
		file1.open("seat.txt",ios::app|ios::out);
		file1 << "E-100" << " " << 5 << "\n";
		file1 << "E-300" << " " << 20 << "\n";
		file1 << "E-500" << " " << 14 << "\n";
		file1.close();
		file.open("bus.txt",ios::in);
		file1.open("seat.txt", ios::in);
		if(!file||!file1)
		{ 
			cout << "\n\n File Opening Error";
		}
		else
		{
			cout << "\n\n Bus No. : ";
			cin >> t_no;
			file1 >> s_b_no >> s_no;
			while (!file1.eof());
			{
				if (t_no == s_b_no)
				{
					count++;
				}
				file1 >> s_b_no >> s_no;
			}
			file1.close();
			file >> b_no >> b_name >> b_seats >> d_name;
			while (!file.eof())
			{
				if (t_no == b_no)
				{
					system("cls");
					cout << "\n\t\t_______BUS MANAGEMENT SYSTEM_______";
					cout << "\n\n Total No. Of Seats: "<<b_seats;
					cout << "\n\n Reserved No. Of Seats: " <<count;
					cout << "\n\n Empty No. Of Seats: " << b_seats-count;
					found++;
				}
				file >> b_no >> b_name >> b_seats >> d_name;
			}
			file.close();
			if (found == 0)
			{
				cout << "\n\n Bus No. Is Invalid... ";
			}
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