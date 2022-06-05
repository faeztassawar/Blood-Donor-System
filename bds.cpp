#include<iostream>
#include<string>
#include<fstream>

using namespace std;

const int size = 150;

struct donor
{
	string name;
	string id;
	string blood_group;
	string phone_no;
	string date_of_donation;
	int donation_count;
};

void input();
void search_by_name( string );
void search_by_blood_group( string );
void update_data( string );
void remove_data( string );

int main()
{
	cout << "      |BLOOD DONATING SYSTEM|" << endl << endl;
	int choice;
	
	while ( choice != 6 )
	{
		cout << "Press 1 to enter the donor's record." << endl;
		cout << "Press 2 to search the donor's record by name." << endl;
		cout << "Press 3 to search the list of donors by blood group." << endl;
		cout << "Press 4 to update the donor's record." << endl;
		cout << "Press 5 to delete the donor's record due to any medical reason." << endl;
		cout << "Press 6 to exit the program." << endl;
		cout << "Now enter the choice : ";
		cin >> choice;
		cout << endl;
		switch ( choice )
		{
			case 1 :
			{
				input();
				cout << endl;
	            cout << "      |Donor's Record Added Successfully.|" << endl << endl;
				break;
			}
			case 2 :
			{
				string name_input;
				cout << "Enter the name whose record you want : ";
				cin.ignore();
				getline(cin,name_input);
				cout << endl;
				search_by_name( name_input );
				cout << endl;
				break;
			}
			case 3 :
			{
				string blood_group;
				cout << "Enter the blood group whose list you want : ";
				cin.ignore();
				getline(cin,blood_group);
				cout << endl;
				search_by_blood_group( blood_group );
			    cout << endl;
				break;
			}
			case 4 :
			{
				string input_id;
				cout << "Enter the donor's id of donor whose record you want to update : ";
				cin.ignore();
				getline(cin,input_id);
				cout << endl;
				update_data( input_id );
				cout << endl;
				cout << "The record is updated." << endl << endl;
				break;
			}
			case 5 :
			{
				string input;
				cout << "Enter the id of donor whose data you want to delete : ";
				cin.ignore();
				getline(cin,input);
				remove_data( input );
				cout << endl;
	            cout << "The record is successfully deleted from file due to some medical reasons." << endl << endl; 
				break;
			}
			case 6 :
			{
				break;
			}
			default :
			{
				cout << "   |WRONG INPUT|   " << endl << endl;
			}	
		}
	}

	return 0;
}

// Function for Input of record.
void input()
{
	donor d1[size];
	static int i = 0;
	cin.ignore();
	cout << "Enter donor's name : ";
	getline(cin,d1[i].name);
	cout << "Enter donor's id : ";
	getline(cin,d1[i].id);
	cout << "Enter donor's blood group : ";
	getline(cin,d1[i].blood_group);
	cout << "Enter donor's phone number : ";
	getline(cin,d1[i].phone_no);
	cout << "Enter donor's date of donation : ";
	getline(cin,d1[i].date_of_donation);
	cout << "Enter donor's donation count : ";
	cin >> d1[i].donation_count;
	fstream file;
	file.open("bds_donor_data.txt",ios::app);
	file << d1[i].name << endl;
	file << d1[i].id << endl;
	file << d1[i].blood_group << endl;
	file << d1[i].phone_no << endl;
	file << d1[i].date_of_donation << endl;
	file << d1[i].donation_count << endl;
	file.close();
	i++;
}

// Function for searching donor by name.
void search_by_name( string a )
{
	donor d2[size];
	ifstream file;
	file.open("bds_donor_data.txt");
    for ( int i = 0; i < size; i++ )
    {
	    getline(file,d2[i].name);
	    getline(file,d2[i].id);
	    getline(file,d2[i].blood_group);
	    getline(file,d2[i].phone_no);
	    getline(file,d2[i].date_of_donation);
		file >> d2[i].donation_count;
		file.ignore();
	}
	file.close();
	int x = 0;
	for ( int j = 0; j < size; j++ )
	{
		if ( a == d2[j].name )
		{
			cout << "Name : " << d2[j].name << endl;
			cout << "Id : " << d2[j].id << endl;
			cout << "Blood group : " << d2[j].blood_group << endl;
			cout << "Phone number : " << d2[j].phone_no << endl;
			cout << "Date of donation : " << d2[j].date_of_donation << endl;						
			cout << "Donation count : " << d2[j].donation_count << endl << endl;
			x++;	
		}
    }
    if ( x == 0 )
    {
    	cout << "No record found !" << endl << endl;
	}
}

// Function for searching donor by blood group.
void search_by_blood_group( string b )
{
	donor d3[size];
	ifstream file;
	file.open("bds_donor_data.txt");
	for ( int i = 0; i < size; i++ )
	{
	    getline(file,d3[i].name);
	    getline(file,d3[i].id);
	    getline(file,d3[i].blood_group);
	    getline(file,d3[i].phone_no);
	    getline(file,d3[i].date_of_donation);
		file >> d3[i].donation_count;
		file.ignore();
	}
	file.close();
	int x = 0;
	for ( int j = 0; j < size; j++ )
	{
		if ( b == d3[j].blood_group )
	    {
		    cout << "Name : " << d3[j].name << endl;
		    cout << "Id : " << d3[j].id << endl;
		    cout << "Blood group : " << d3[j].blood_group << endl;
		    cout << "Phone number : " << d3[j].phone_no << endl;
		    cout << "Date of donation : " << d3[j].date_of_donation << endl;						
		    cout << "Donation count : " << d3[j].donation_count << endl << endl;
			x++;	
	    }
    }
    if ( x == 0)
    {
    	cout << "No record found !" << endl << endl;
	}
}

// Function to update the record.
void update_data( string c )
{
	donor d4[size];
	ifstream file;
	file.open("bds_donor_data.txt");
	fstream temp_file;
	temp_file.open("temp_donor_data.txt",ios::app);
	int k = 0;
    while ( !file.eof() )
    {
    	getline(file,d4[k].name);
	    getline(file,d4[k].id);
	    getline(file,d4[k].blood_group);
	    getline(file,d4[k].phone_no);
	    getline(file,d4[k].date_of_donation);
		file >> d4[k].donation_count;
		file.ignore();
		k++;
	}
	file.close();
	int x = k - 1;
	for ( int j = 0; j < x; j++ )
	{
		if ( c == d4[j].id )
		{
			cout << "      |Previous Data|" << endl << endl;
		    cout << "Name : " << d4[j].name << endl;
		    cout << "Id : " << d4[j].id << endl;
		    cout << "Blood group : " << d4[j].blood_group << endl;
		    cout << "Phone number : " << d4[j].phone_no << endl;
		    cout << "Date of donation : " << d4[j].date_of_donation << endl;						
		    cout << "Donation count : " << d4[j].donation_count << endl << endl;
		    
		    cout << "      |Enter New Data|" << endl << endl;
	        cout << "Enter donor's name : ";
	        getline(cin,d4[j].name);
	        cout << "Enter donor's id : ";
	        getline(cin,d4[j].id);
	        cout << "Enter donor's blood group : ";
	        getline(cin,d4[j].blood_group);
	        cout << "Enter donor's phone number : ";
	        getline(cin,d4[j].phone_no);
	        cout << "Enter donor's date of donation : ";
	        getline(cin,d4[j].date_of_donation);
	        cout << "Enter donor's donation count : ";
	        cin >> d4[j].donation_count;
	        
	        temp_file << d4[j].name << endl;
	        temp_file << d4[j].id << endl;
	        temp_file << d4[j].blood_group << endl;
	        temp_file << d4[j].phone_no << endl;
	        temp_file << d4[j].date_of_donation << endl;
	        temp_file << d4[j].donation_count << endl;
		}
		else
		{
			temp_file << d4[j].name << endl;
	        temp_file << d4[j].id << endl;
	        temp_file << d4[j].blood_group << endl;
	        temp_file << d4[j].phone_no << endl;
	        temp_file << d4[j].date_of_donation << endl;
	        temp_file << d4[j].donation_count << endl;
		}
	}
	temp_file.close();	
	remove("bds_donor_data.txt");
	rename("temp_donor_data.txt","bds_donor_data.txt");
}

// Function to delete any donor's record.
void remove_data( string d )
{
	donor d5[size];
	ifstream file;
	file.open("bds_donor_data.txt");
    int i = 0;
	while ( !file.eof() )
	{
		getline(file,d5[i].name);
	    getline(file,d5[i].id);
	    getline(file,d5[i].blood_group);
	    getline(file,d5[i].phone_no);
	    getline(file,d5[i].date_of_donation);
		file >> d5[i].donation_count;
		file.ignore();
		i++;
	}
	file.close();
	ofstream temp_file;
	temp_file.open("temp_donor_data.txt",ios::app);
	int x = i - 1;
	for ( int j = 0; j < x; j++ )
	{
		if ( d == d5[j].id )
		{
			// empty to delete the record.
		}
		else
		{
			temp_file << d5[j].name << endl;
			temp_file << d5[j].id << endl;
	        temp_file << d5[j].blood_group << endl;
	        temp_file << d5[j].phone_no << endl;
	        temp_file << d5[j].date_of_donation << endl;
	        temp_file << d5[j].donation_count << endl;
		}
	}
	temp_file.close();	
	remove("bds_donor_data.txt");
	rename("temp_donor_data.txt","bds_donor_data.txt");
}