//fstream handle for books.txt, fstream stud for students.txt, handle2 for temporary txt for books and stud2 for temporary txt for students, admin for staff, admin2 for temp txt for staff
#include <iostream>
#include <fstream>
using namespace std;
class book
{
    int isbn;
    char name[20];
    char author[20];
    bool inStore = 1;  //is the book available and hasnt been issued
 public:
    void getData()
    {
		inStore=1;
        cin>>isbn;
        cin.ignore();
        cin.getline(name,20);
        cin.getline(author,20);
    }
    void putData()
    {
        cout<<isbn<<" "<<name<<" "<<author<<" "<<inStore<<"\n";
    }
    bool getstatus() {
		return inStore;
	}
	void beenIssued() {
		inStore = 0;
	}
	void beenReturned() {
		inStore = 1;
	}
    int getisbn()
    {
        return isbn;
    }
}temp;
class student
{
	int regno;
	int lfine = 0; //fine adds +20 per day starting from the seventh day
	int token = 0; //has student issued any book(can issue a max of 3)
	char name[20];
	public:
	void getStud() {
		token = 0;
		lfine = 0;
		cin>>regno;
		cin.ignore();
		cin.getline(name,20);
	}
	void putStud() {
		cout<<regno<<" "<<name<<" "<<lfine<<" "<<token<<"\n";
	}
	int getfine() {
		return lfine;
	}
	int getregno() {
		return regno;
	}
	void addtoken() {
		++token;
	}
	int gettoken() {
		return token;
	}
	void removetoken() {
		if(token>0) {
		--token;
	}
	}
	void addfine(int days) {
		if(days <=7 ) { return; }
		else if(days > 7) {
			days = days-7;
			lfine = lfine+(days*20);
			cout<<"Your fine is: "<<lfine<<endl;
		}			
	}
	void clearfine() {    //remove fine
		lfine=0;
	}
}person,bot;
class employee {
	int id;
	char name[20];
	public:
	void getData() {
		cin>>id;
		cin.ignore();
		cin.getline(name,20);
	}
	void putData() {
		cout<<id<<" "<<name<<endl;
	}
	int getid() {
		return id;
	}
}emp,emp2;
//related to editing or viewing book records
void addRecord(fstream &h);
void deleteRecord(fstream &h);
void viewRecords(fstream &h);
void editRecord(fstream  &h);
//related to editing or viewing student records
void addStud(fstream &h);
void removeStud(fstream &h);
void viewStuds(fstream &h);
void editStud(fstream &h);
//related to issuing or returning books
void issuebook(fstream &h,fstream &d);
void returnbook(fstream &h, fstream &d);
void clearfine(fstream &d);
//related to managing staff records/inventory
void addemp(fstream &h);
void deleteemp(fstream  &h);
void viewemp(fstream &h);
void editemp(fstream &h);
int main()
{
    fstream handle,stud,admin;
    admin.open("peeps.txt",ios::out|ios::app);
    stud.open("students.txt",ios::out|ios::app);
    handle.open("books.txt",ios::out|ios::app);
    stud.close();
    handle.close();
    admin.close();
mainstart:
    cout<<"1. Manage Book Records\n2. Student Interface \n3. Admin interface\n4. Exit\n";
    int pick;
    cin>>pick;
    if(pick ==1)
    {
startHere:
	handle.close();
    handle.open("books.txt",ios::in|ios::out|ios::ate);
    cout<<"1. Add records\n2. Delete record\n3. Edit Record\n4. View records\n";
    cout<<"5. Back to Main\n6. Exit\n";
    cin>>pick;
    switch(pick)
    {
        case 1:
            {
                addRecord(handle);
                goto startHere;
            }
        case 2:
            {
                deleteRecord(handle);
                goto startHere;
            }
        case 3:
            {
                editRecord(handle);
                goto startHere;
            }
        case 4:
            {
                viewRecords(handle);
                goto startHere;
            }
        case 6:
            {
                return 0;
            }
        case 5:
            {
                goto mainstart;

            }
    }
    } 
    else if(pick==2) {
		issueAndReturn:
		handle.close();
		stud.close();
		handle.open("books.txt",ios::in|ios::out|ios::ate);
		stud.open("students.txt",ios::in|ios::out|ios::ate);
		cout<<"1.Add Student Record\n2.Edit Student Record\n3.View Student Record\n4.Issue/Return book\n5.Back to Main\n6.Exit\n";
		int zxc;
		cin>>zxc;
		switch(zxc)
		{
			case 1: {
				addStud(stud);
				goto issueAndReturn;
			}
			case 2: {
				editStud(stud);
				goto issueAndReturn;
			}
			case 3: {
				viewStuds(stud);
				goto issueAndReturn;
			}
			case 4: {
				cout<<"1. Issue Book\n2. Return Book\n3. Clear fine\n4. Back to Student interface\n";
				int mypick;
				cin>>mypick;
				if(mypick == 1)
				{
					issuebook(handle,stud);
					goto issueAndReturn;
				} 
				else if(mypick == 2) {
					returnbook(handle,stud);
					goto issueAndReturn;
				}
				else if(mypick == 3)
				{
					clearfine(stud);
					goto issueAndReturn;
				}
				else 
				{
					goto issueAndReturn;
				}
			} 
			case 5: {
				goto mainstart;
			}
			case 6: {
				return 0;
			}
		}
	}
	else if(pick == 3) {
		adminmenu:
		admin.close();
		handle.close();
		stud.close();
		admin.open("peeps.txt",ios::in|ios::out|ios::ate);
		handle.open("books.txt",ios::in|ios::out|ios::ate);
		stud.open("students.txt",ios::in|ios::out|ios::ate);
		cout<<"1. Add employee record\n2. Delete Emp record\n3. Edit Emp Record\n4. View emp record\n5. Back to Main\n6. Exit\n";
		int adchoice;
		cin>>adchoice;
		switch(adchoice) {
			case 1: {
				addemp(admin);
				goto adminmenu;
			}
			case 2: {
				deleteemp(admin);
				goto adminmenu;
			}
			case 3: {
				editemp(admin);
				goto adminmenu;
			}
			case 4: {
				viewemp(admin);
				goto adminmenu;
			}
			case 5: {
				goto mainstart;
			}
			case 6: {
				return 0;
			}				
	}
}
}
void addRecord(fstream &handle)
{
	cout<<"Enter records\n";
				char choice='y';
				while(choice=='y') {
                    temp.getData();
                    handle.write((char*)&temp,sizeof(temp));
                    cout<<"Add more records(y/n)?\n";
                    cin>>choice;
                }
                handle.close();
}
void deleteRecord(fstream &handle)
{
	char choice;
	fstream handle2("temp.txt",ios::out|ios::trunc);
	do {
				int found = 0;
                cout<<"Enter isbn of book:\n";
                int isbn;
                cin>>isbn;
                handle.seekp(0);
                while(handle.read((char*)&temp,sizeof(temp)))
                {
                    if(temp.getisbn()==isbn)
                    {
                        cout<<"Book Found\n";
                        found = 1;
                    }
                    else
                    {
                        handle2.write((char*)&temp,sizeof(temp));
                    }
                }
                if(found == 0) {
					cout<<"Record not found\n";
				}
                remove("books.txt");
                rename("temp.txt","books.txt");
                handle.close();
                handle2.close();
                handle.open("books.txt",ios::in|ios::out|ios::ate);
                handle2.open("temp.txt",ios::out|ios::trunc);
                cout<<"Delete more records(y/n)?\n";
                cin>>choice;
			}while(choice == 'y');
			handle.close();
			handle2.close();
}
void viewRecords(fstream &handle)
{
	//handle.open("books.txt",ios::in|ios::out|ios::ate);
cout<<"The records are:\n";
                handle.seekg(0);
                while(handle.read((char*)&temp,sizeof(temp)))
                {
                    temp.putData();
                }
                handle.close();
}
void editRecord(fstream &handle)
{
	char choice;
     fstream handle2("temp.txt",ios::out|ios::trunc);
     do {
                cout<<"Enter isbn of book to be modified:\n";
                int isbn,found = 0 ;
                cin>>isbn;
                handle.seekp(0);
                while(handle.read((char*)&temp,sizeof(temp)))
                {
                    if(temp.getisbn()==isbn)
                    {
						found =1;
                        cout<<"Enter new records for this book:\n";
                        temp.getData();
                        handle2.write((char *)&temp,sizeof(temp));
                    }
                    else
                    {
                        handle2.write((char*)&temp,sizeof(temp));
                    }
                }
                if(found == 0) {
					cout<<"Isbn not in record\n";
				}
                remove("books.txt");
                rename("temp.txt","books.txt");
                handle.close();
                handle2.close();
                handle.open("books.txt",ios::in|ios::out|ios::ate);
                handle2.open("temp.txt",ios::out|ios::trunc);
                cout<<"Edit more records(y/n)?\n";
                cin>>choice;
			}while(choice == 'y');
			handle.close();
			handle2.close();
}
void addStud(fstream &stud) {
	char choice = 'y';
	do {
		cout<<"Enter student details:\n";
		person.getStud();
		stud.write((char *)&person,sizeof(person));
		cout<<"Enter more records(y/n)?\n";
		cin>>choice;
	}while(choice == 'y');
	stud.close();
}
void viewStuds(fstream &stud)
{
	stud.seekg(0);
	while(stud.read((char *)&person,sizeof(person))) {
		person.putStud();
	}
	stud.close();
}
void editStud(fstream &stud) {
	char choice = 'y';
	fstream stud2("temp2.txt",ios::out|ios::trunc);
	do {
		cout<<"Enter reg no of record to be edited:\n";
		int regno,found= 0;
		cin>>regno;
		stud.seekg(0);
		while(stud.read((char*)&person,sizeof(person))) {
			if(person.getregno() == regno) {
				found = 1;
				cout<<"Enter new details:\n";
				person.getStud();
				stud2.write((char*)&person,sizeof(person));
			}
			else
			{
				stud2.write((char*)&person,sizeof(person));
			}
		}
		if(found == 0) {
			cout<<"Record not found\n";
		}
		remove("students.txt");
		rename("temp2.txt","students.txt");
		stud.close();
		stud2.close();
		stud.open("students.txt",ios::in|ios::out|ios::ate);
		stud2.open("temp2.txt",ios::out|ios::trunc);
		cout<<"Edit more records(y/n)?\n";
		cin>>choice;
	}while(choice=='y');
	stud.close();
}
void issuebook(fstream &handle,fstream &stud)
{
	cout<<"Enter isbn of book:\n";
	int isbn;
	cin>>isbn;
	handle.seekg(0);
	int foundbook = 0,foundstud = 0;
	while(handle.read((char*)&temp,sizeof(temp))) {
		if((temp.getisbn() == isbn) && (temp.getstatus())) {
			foundbook = 1;
			break;
		}
	}
	if(foundbook == 0) {
		cout<<"Book not found or is out of stock currently. Returning....\n";
		return;
	}
	cout<<"Enter student registration number:\n";
	int regno;
	cin>>regno;
	stud.seekg(0);
	while(stud.read((char*)&bot,sizeof(bot))) {
		if(bot.getregno() == regno) {
			if(bot.gettoken()>=3) {
				cout<<"Maximum issuing capacity reached.\n";
				return;
			}
			bot.addtoken();
			foundstud =1;
			break;
		}
	}
	if(foundstud == 0) {
		cout<<"Student record not found.\n";
		return;
	}
	//remove book if its getting issued
	fstream handle2("temp.txt",ios::out|ios::trunc);
	handle.seekp(0);
	while(handle.read((char*)&temp,sizeof(temp)))
	{
		if(temp.getisbn()==isbn)
		{
			temp.beenIssued();
			handle2.write((char*)&temp,sizeof(temp));
			//cout<<"Book issued;";
		}
		else
		{
			handle2.write((char*)&temp,sizeof(temp));
		}
	}
	remove("books.txt");
	rename("temp.txt","books.txt");
	handle.close();
	handle2.close();
	//increase student token
	fstream stud2("temp2.txt",ios::out|ios::trunc);
	stud.seekg(0);
	while(stud.read((char*)&person,sizeof(person))) {
		if(person.getregno() == regno) {
			stud2.write((char*)&bot,sizeof(bot));
		}
		else {
			stud2.write((char*)&person,sizeof(person));
		}
	}
		remove("students.txt");
		rename("temp2.txt","students.txt");
		stud.close();
		stud2.close();	
		cout<<"Book issued.\n";				
}
void returnbook(fstream &handle,fstream &stud) {
	cout<<"Enter isbn of book:\n";
	int isbn;
	cin>>isbn;
	handle.seekg(0);
	int foundbook = 0,foundstud = 0;
	while(handle.read((char*)&temp,sizeof(temp))) {
		if((temp.getisbn() == isbn) && (!temp.getstatus())) {
			foundbook = 1;
			break;
		}
	}
	if(foundbook == 0) {
		cout<<"Book not found or has already been returned.\n";
		return;
	}
	cout<<"Enter student registration number:\n";
	int regno;
	cin>>regno;
	stud.seekg(0);
	while(stud.read((char*)&bot,sizeof(bot))) {
		if(bot.getregno() == regno) {
			bot.removetoken();
			foundstud =1;
			break;
		}
	}
	if(foundstud == 0) {
		cout<<"Student record not found.\n";
		return;
	}
	cout<<"Enter duration since issue date(in days):\n";
	int days;
	cin>>days;
	//set inStore to 1 since book is now available
	fstream handle2("temp.txt",ios::out|ios::trunc);
	handle.seekp(0);
	while(handle.read((char*)&temp,sizeof(temp)))
	{
		if(temp.getisbn()==isbn)
		{
			temp.beenReturned();
			handle2.write((char*)&temp,sizeof(temp));
			//cout<<"Book issued;";
		}
		else
		{
			handle2.write((char*)&temp,sizeof(temp));
		}
	}
	remove("books.txt");
	rename("temp.txt","books.txt");
	handle.close();
	handle2.close();
	//decrease student token
	fstream stud2("temp2.txt",ios::out|ios::trunc);
	stud.seekg(0);
	while(stud.read((char*)&person,sizeof(person))) {
		if(person.getregno() == regno) {
			if(days>7) {
				bot.addfine(days);
			}
			stud2.write((char*)&bot,sizeof(bot));
		}
		else {
			stud2.write((char*)&person,sizeof(person));
		}
	}
		remove("students.txt");
		rename("temp2.txt","students.txt");
		stud.close();
		stud2.close();	
		cout<<"Book Returned.\n";	
}
void clearfine(fstream &stud) {
	cout<<"Enter student reg no:\n";
	int regno;
	cin>>regno;
	stud.seekg(0);
	int found = 0;
	while(stud.read((char*)&person,sizeof(person))) {
		if(person.getregno() == regno) {
			found = 1;
			if(person.getfine() == 0) {
				cout<<"Fine already 0.\n";
				return;
			}
			person.clearfine();
			break;
		}
	}
	if(found == 0) {
		cout<<"No student with that reg no exits.\n";
		return;
	}
	fstream stud2("temp2.txt",ios::out|ios::trunc);
	stud.seekg(0);
	while(stud.read((char*)&bot,sizeof(bot))) {
		if(bot.getregno() == regno) {
			stud2.write((char*)&person,sizeof(person));
		}
		else {
			stud2.write((char*)&bot,sizeof(bot));
		}
	}
	remove("students.txt");
	rename("temp2.txt","students.txt");
	stud.close();
	stud2.close();
	cout<<"All fines cleared from this account.\n";
}
void addemp(fstream &admin) {
	cout<<"Enter employee details:\n";
	char choice;
	do {
		emp.getData();
		admin.write((char*)&emp,sizeof(emp));
		cout<<"Add more employee records(y/n)?\n";
		cin>>choice;
	}while(choice=='y');
	admin.close();
}
void deleteemp(fstream  &admin) {
	char choice;
	fstream admin2("temp3.txt",ios::out|ios::trunc);
	do {
			int found = 0;
			cout<<"Enter id of emp to be deleted:\n";
			int id;
			cin>>id;
			admin.seekp(0);
			while(admin.read((char*)&emp,sizeof(emp)))
			{
				if(emp.getid()==id)
				{
					cout<<"Emp record deleted\n";
					found = 1;
				}
				else
				{
					admin2.write((char*)&temp,sizeof(temp));
				}
			}
			if(found == 0) {
				cout<<"Emp record not found\n";
			}
			remove("peeps.txt");
			rename("temp3.txt","peeps.txt");
			admin.close();
			admin2.close();
			admin.open("peeps.txt",ios::in|ios::out|ios::ate);
			admin2.open("temp3.txt",ios::out|ios::trunc);
			cout<<"Delete more records(y/n)?\n";
			cin>>choice;
		}while(choice == 'y');
		admin.close();
		admin2.close();
}
void editemp(fstream &admin) {
	char choice;
     fstream admin2("temp3.txt",ios::out|ios::trunc);
     do {
                cout<<"Enter id of emp record to be modified:\n";
                int id,found = 0 ;
                cin>>id;
                admin.seekp(0);
                while(admin.read((char*)&emp,sizeof(emp)))
                {
                    if(emp.getid()==id)
                    {
						found =1;
                        cout<<"Enter new records for this emp:\n";
                        emp.getData();
                        admin2.write((char *)&emp,sizeof(emp));
                    }
                    else
                    {
                        admin2.write((char*)&emp,sizeof(emp));
                    }
                }
                if(found == 0) {
					cout<<"Emp not in record\n";
				}
                remove("peeps.txt");
                rename("temp3.txt","peeps.txt");
                admin.close();
                admin2.close();
                admin.open("books.txt",ios::in|ios::out|ios::ate);
                admin2.open("temp.txt",ios::out|ios::trunc);
                cout<<"Edit more records(y/n)?\n";
                cin>>choice;
			}while(choice == 'y');
			admin.close();
			admin2.close();
		}
void viewemp(fstream &admin) {
	admin.seekg(0);
	while(admin.read((char*)&emp,sizeof(emp))) {
		emp.putData();
	}
	admin.close();
}

		
	
