#include <string.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>

using namespace std;
class SHOWROOM
{
	char name[50];
	char modno[60];
	long price;
	int quantity;

public:
	void getdata();
	void showdata();
	int check1(char nm[]);
	int check2(char mn[]);
	int check3(long pr);
	int check4(int qn);
	void edit();
};


// ** TO  INPUT AN OBJECT **


void SHOWROOM::getdata()
{
	cout << "\nEnter name:\n";
	gets(name);
	cout << "\nEnter model no.:\n";
	gets(modno);
	cout << "\nEnter price(in Rs.):\n";
	cin >> price;
	cout << "\nEnter quantity:\n";
	cin >> quantity;
}


// ** TO  DISPLAY AN OBJECT **

void SHOWROOM::showdata()
{

	cout << "\nName    : " << name << endl;
	cout << "Model no. : " << modno << endl;
	cout << "Price     : " << price << endl;
	cout << "Quantity  : " << quantity << endl << endl;

}

// ** CHECK NAME **

int SHOWROOM::check1(char nm[])
{
	if (strcmp(nm, name) == 0)
		return 1;
	else
		return 0;
}



// ** CHECK MODEL NUMBER **

int SHOWROOM::check2(char mn[])
{
	if (strcmp(mn, modno) == 0)
		return 1;
	else
		return 0;
}


// ** CHECK PRICE **

int SHOWROOM::check3(long pr)
{
	if (pr == price)
		return 1;
	else
		return 0;
}


// ** CHECK QUANTITY **

int  SHOWROOM::check4(int qn)
{
	if (qn == quantity)
		return 1;
	else
		return 0;

}

// *** EDIT/ MODIFY A RECORD ****

void SHOWROOM::edit()
{
	char op;
	do {
		cout << "detail of the record : \n\n";
		showdata();
		cout << "\n Press 1 if you want to change the name  \n";
		cout << "\n Press 2 if you want to change the model number  \n";
		cout << "\n Press 3 if you want to change the price  \n";
		cout << "\n Press 4 if you want to change the quantity  \n";
		cout << "\n Press 5 if you dont want to change anything  \n";

		cout << "Enter your option";
		cin >> op;

		switch (op)
		{
		case '1':
			cout << "\n Enter new name";
			gets(name);
			break;
		case '2':
			cout << "\n Enter new model number";
			gets(modno);
			break;
		case '3':
			cout << "\n Enter new price";
			cin >> price;
			break;
		case '4':
			cout << "\n Enter new quantity";
			cin >> quantity;
			break;

		case '5':
			break;


		default:     cout << "\n WRONG OPTION....TRY AGAIN \n";
		}
	} while (op != '5');
}




//    **** APPEND / ADD A NEW RECORD *****


void append()
{
	SHOWROOM S;

	cout << "\n Enter the details to add / append";
	S.getdata();

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::app);

	f1.write((char*)&S, sizeof(S));

	f1.close();
}


//    ***** DISPLAY ALL RECORDS ****

void displayAll()
{
	SHOWROOM S;

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::in);

	while (f1.read((char*)&S, sizeof(S)))
	{
		S.showdata();
	}

	f1.close();
}


//    *** SEARCH A RECORD BY NAME ***


void searchName()
{
	char sn[50];
	SHOWROOM S;
	int found = 0;

	cout << "\n\n Enter the name to be searched : ";
	gets(sn);

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::in);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check1(sn) == 1)
		{
			found++;
			S.showdata();
		}
	}

	f1.close();

	if (found == 0)
		cout << "\n SORRY, NAME NOT FOUND !";
	else
		cout << "\n TOTAL " << found << " NAME(S) FOUND !";

}


//    *** SEARCH RECORD BY MODEL NUMBER ***

void searchModel()
{
	char mn[60];
	SHOWROOM S;
	int found = 0;

	cout << "\n\n Enter the model number to be searched : ";
	gets(mn);

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::in);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check2(mn) == 1)
		{
			found++;
			S.showdata();
		}
	}

	f1.close();

	if (found == 0)
		cout << "\n  MODEL NUMBER NOT FOUND !!";
	else
		cout << "\n TOTAL " << found << " RECORD(S) FOUND ";
}


//    *** SEARCH RECORD BY PRICE ***

void searchPrice()
{
	long pr;
	SHOWROOM S;
	int found = 0;

	cout << "\n\n Enter the price to be searched : ";
	cin >> pr;

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::in);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check3(pr) == 1)
		{
			found++;
			S.showdata();
		}
	}

	f1.close();

	if (found == 0)
		cout << "\n NO PRICE MATCH FOUND ";
	else
		cout << "\n TOTAL " << found << " RECORD(S) FOUND ";

}


//    *** SEARCH RECORD BY QUANTITY ***

void searchQuant()
{
	int qty;
	SHOWROOM S;
	int found = 0;

	cout << "\n\n Enter the quantity to be searched : ";
	cin >> qty;

	fstream f1;
	f1.open("DATABASE.DAT", ios::binary | ios::in);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check4(qty) == 1)
		{
			found++;
			S.showdata();
		}
	}

	f1.close();

	if (found == 0)
		cout << "\n NO MATCH FOUND ";
	else
		cout << "\n TOTAL " << found << " RECORD(S) FOUND ";

}


//    *** EDIT OR MODIFY ***

void modify()
{
	char nm[50];
	SHOWROOM S;
	int modified = 0;

	cout << "Enter the name to be modified \n";
	gets(nm);

	fstream f1, f2;
	f1.open("DATABASE.DAT", ios::binary | ios::in);
	f2.open("TEMP.DAT", ios::binary | ios::out);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check1(nm) == 1)
		{
			modified++;
			S.edit();
		}
		f2.write((char*)&S, sizeof(S));
	}

	f1.close();
	f2.close();

	if (modified == 0)
		cout << "\n\n NAME MIS-MATCH !! NOT FOUND";
	else
	{
		remove("DATABASE.DAT");
		rename("TEMP.DAT", "DATABASE.DAT");
	}

}



// *** DELETE A RECORD ***


void Delete()
{
	char nm[50];
	SHOWROOM S;
	int deleted = 0;

	cout << "\n\n Enter the name to be deleted ";
	gets(nm);

	fstream f1, f2;

	f1.open("DATABASE.DAT", ios::binary | ios::in);
	f2.open("TEMP.DAT", ios::binary | ios::out);

	while (f1.read((char*)&S, sizeof(S)))
	{
		if (S.check1(nm) == 1)
			deleted++;
		else
			f2.write((char*)&S, sizeof(S));
	}

	f1.close();
	f2.close();


	if (deleted == 0)
		cout << "\n\n NAME NOT FOUND \n\n";
	else
	{
		remove("DATABASE.DAT");
		rename("TEMP.DAT", "DATABASE.DAT");
	}
}




int main()
{

	char choice;

	do {
    
		cout << "\n          MENU\n";
		cout << "\n          **\n";
		cout << "\nPRESS 1 TO ADD A RECORD";
		cout << "\nPRESS 2 TO DISPLAY THE INVENTORY";
		cout << "\n\nPRESS 3 TO SEARCH BY NAME";
		cout << "\nPRESS 4 TO SEARCH BY MODEL NUMBER";
		cout << "\nPRESS 5 TO SEARCH BY PRICE";
		cout << "\nPRESS 6 TO SEARCH BY QUANTITY";
		cout << "\n\nPRESS 7 TO MODIFY A RECORD";
		cout << "\nPRESS 8 TO DELETE A RECORD";
		cout << "\n\nPRESS 9 TO QUIT";
		cout << "\n\n PLEASE ENTER YOUR CHOICE";
		choice = getch();

		switch (choice)
		{
		case '1':    ; append();
			break;

		case '2':    ; displayAll();
			break;

		case '3':    ; searchName();
			break;

		case '4':    ; searchModel();
			break;

		case '5':    ; searchPrice();
			break;

		case '6':    ;searchQuant();
			break;

		case '7':    ; modify();
			break;

		case '8':    ; Delete();
			break;

		case '9':       ;
			cout << "\n\n\n Thank you for using this program !\n\n" << "\n Have a great day ahead!";
			break;

		default:     cout << "\n WRONG CHOICE! PLEASE TRY AGAIN. \n\n";

		}

		getch();

	} while (choice != '9');
return 0;
}