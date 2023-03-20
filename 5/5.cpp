#include <iostream>
#include "Table.h"
#include "Record.h"

int main()
{
	Table base;
	
	int inp = 10;
	while (inp != 0) {
		cout << "Menu: " << endl
			<< " 1. Add record " << endl
			<< " 2. Delete record " << endl
			<< " 3. Sort table " << endl
			<< " 4. Print " << endl
			<< " 5. Find record " << endl
			<< " 6. Menu " << endl
			<< " 0. Exit " << endl;
		cin >> inp;
		switch (inp) {
		case 1:
		{
			cin >> base;
			
			break;
		}
		case 2:
		{
			if (base.GetSize() == 0) {
				cout << "Empty table" << endl;
				break;
			}
			int index;
			cout << "Input index of record that you wanna delete: " << endl;
			cin >> index;
			base.remove(index-1);
			break;
		}
		case 3:
		{
			if (base.GetSize() == 0) {
				cout << "No records" << endl;
				break;
			}
			base.sort();
			cout << "The data was successfully sorted in descending order of date" << endl;
		}
		case 4:
		{
			if (base.GetSize() == 0) {
				cout << "No records" << endl;
				break;
			}
			cout.width(6);
			cout << "Name" << " | ";
			cout.width(15);
			cout << "Number group" << " | ";
			cout.width(15);
			cout << "Name of the exam" << " | ";
			cout.width(15);
			cout << "Address" << " | ";
			cout.width(10);
			cout << "Price" << " | ";
			cout.width(6);
			cout << "Mark" << " | ";
			cout << "Date of admission" << endl;
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			cout << base << endl;
			break;
		}
		
		case 5: {
			cout << "Enter Name: " << endl;
			String buf; 
			getchar();
			cin >> buf;
			Record Rec(buf, buf, buf, buf, 0, 0, { 0,0,0 });
			Obj& F = Rec;
			int index = base.find(&F);
			if (index >= 0)
				cout << "Index: " << index+1 << endl;
			else 
				cout << "Didn`t found any records with this name" << endl;
			break;
		}
		case 6:
		{
			break;
		}
		}
	}
	return 0;
}