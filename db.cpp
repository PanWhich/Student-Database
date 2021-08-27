Database::Database()
{
	
}
int Database::LoadFileData(string fileName)
{
	
	return 0;
}
int Database::CreateFile(string fileName)
{
	
	return 0;
}
int Database::DumpToFile(string fileName)
{
	
	return 0;
}
int Database::SearchRecord(int theID)
{
	int index = Hash(theID);
	if (Records[index].ID > -1)
	{
		cout << "ID: " << Records[index].ID << "\nName: " << Records[index].Name << "\nAge: " << Records[index].Age << endl;
		return 0;
	}
	return -1;
}
int Database::DeleteRecord(int theID)
{
	int index = Hash(theID);
	if (Records[index].ID > -1 && Records[index].ID == theID)
	{
		Records[index].Name = "";
		Records[index].Age = 0;
		Records[index].ID = -2;
		return 0;
	}
	return -1;
}
int Database::AddRecord(string theName, int theAge, int theID)
{
	int index = 0, startIndex = 0;
	bool findingOpen = true;
	startIndex = Hash(theID);
	index = startIndex;
	
	while (findingOpen)
	{
		if (Records[index].ID == -1)
		{
			findingOpen = false; 
			Records[index].ID = theID;
			Records[index].Name = theName;
			Records[index].Age = theAge;
			findingOpen = false;
			index = 0; // Return value
		}
		else
		{
			if (theID < IDLIMIT)
				theID++;
			else
				theID = 0;
			index = Hash(theID);
			if (index == startIndex)
			{
				findingOpen = false;
				index = -1; // Return value (No open slots found)
			}
		}
	}
	return index; // Reused as a return value
}
int Database::Hash(int theID)
{
	int address = theID % RECORDNUM;
	return address;
}
void Database::Display()
{
	cout << left << setw(10) << "Index" << setw(10) << "ID" << setw(10) << "Age" << setw(10) << "Name\n" << endl;
	for (int i = 0; i < RECORDNUM; i++)
	{
		cout << setw(10) << i << setw(10) << Records[i].ID << setw(10) << Records[i].Age << Records[i].Name << endl;
	}
	cout << endl;
}
int Database::GetIDLimit()
{
	return IDLIMIT;
}
Database::~Database()
{
	
}
