/**********************************************************************
* Author:			Alexander Ott
* Filename:			Lab08
* Date Created:		02/28/2016
**********************************************************************/
#include "String.h"

/**********************************************************************
* Purpose: This function is the default constructor for the String
*			class.
*
* Precondition:
*		Declaration of a String type object with out arguments.
*
* Postcondition:
*		Modifies the value m_str.
*
************************************************************************/
String::String() : m_str(nullptr)
{
	m_str = new char[1];
	m_str[0] = '\0';
}

/**********************************************************************
* Purpose: This function is the one char argument constructor for the
*			String class.
*
* Precondition:
*		Declaration of a String type object with a char passed.
*
* Postcondition:
*		Modifies the value m_str to the char being passed.
*
************************************************************************/
String::String(char ch) : m_str(nullptr)
{
	m_str = new char[1];
	m_str[0] = ch;
	m_str[1] = '\0';
}

/**********************************************************************
* Purpose: This function is the string literal argument constructor
*			for the String class.
*
* Precondition:
*		Declaration of a String type object with a string literal passed.
*
* Postcondition:
*		Modifies the value m_str to the string literal being passed.
*
************************************************************************/
String::String(char * str) : m_str(nullptr)
{
	if (str != nullptr)
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	else
	{
		m_str = new char;
		m_str = nullptr;
	}
}

/**********************************************************************
* Purpose: This function is the desctructor for the String class.
*
* Precondition:
*		String type object goes out of scope.
*
* Postcondition:
*		Deletes the memory for the m_str data member.
*
************************************************************************/
String::~String()
{
	delete[] m_str;
	m_str = nullptr;
}

/**********************************************************************
* Purpose: This function is the copy constructor for the String
*			class.
*
* Precondition:
*		String type object initialized with another object of
*		the same type.
*
* Postcondition:
*		Modifies the values of the invoked objects data members to that
*		of the object passed.
*
************************************************************************/
String::String(const String& copy) : m_str(nullptr)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function is the operator = manager for the String
*			class.
*
* Precondition:
*		Two String type objects that are already initialized
*		placed on both the right and left side of the statement.
*
* Postcondition:
*		Modifies the values of the invoked object data members to that
*		of the object passed. As well as deleting the current data member
*		values on the left hand side.
*
************************************************************************/
String & String::operator = (const String& rhs)
{
	if (this != &rhs)
	{
		delete[] m_str;

		m_str = new char[rhs.StrLen() + 1];
		strcpy(m_str, rhs.m_str);
	}

	return *this;
}

/**********************************************************************
*
**********************************************************************/
bool String::operator < (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check < 0)
		tf = true;

	return tf;
}

/**********************************************************************
*
**********************************************************************/
bool String::operator > (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check > 0)
		tf = true;

	return tf;
}

/**********************************************************************
*
**********************************************************************/
bool String::operator <= (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check <= 0)
		tf = true;

	return tf;
}

/**********************************************************************
* 
**********************************************************************/
bool String::operator >= (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check >= 0)
		tf = true;

	return tf;
}

/**********************************************************************
*
**********************************************************************/
bool String::operator == (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check == 0)
		tf = true;

	return tf;
}

/**********************************************************************
*																	  *
**********************************************************************/
bool String::operator != (const String & rhs)
{
	bool tf = false;
	int check = strcmp(this->m_str, rhs.m_str);

	if (check != 0)
		tf = true;

	return tf;
}

/**********************************************************************
*
**********************************************************************/
ostream & operator << (ostream & str, const String & rhs)
{
	return str << rhs.GetString();
}

/**********************************************************************
*
**********************************************************************/
istream & operator >> (istream & str, String & rhs)
{
	char temp[64];

	str.ignore(str.rdbuf()->in_avail());
	str.getline(temp, 64);
	str.clear();
	str.ignore(str.rdbuf()->in_avail());

	rhs.m_str = new char[strlen(temp) + 1];
	strcpy(rhs.m_str, temp);

	return str;
}

/**********************************************************************
*
**********************************************************************/
void String::Display() const
{
	cout << m_str << endl;
}

/**********************************************************************
*
**********************************************************************/
char* String::GetString() const
{
	return m_str;
}

/**********************************************************************
*
**********************************************************************/
void String::SetString(char * setter)
{
	strcpy(m_str, setter);
}

/**********************************************************************
*
**********************************************************************/
int String::StrLen() const
{
	int count = 0;

	while (m_str[count])
		++count;

	return count;
}

/**********************************************************************
*
**********************************************************************/
void String::ParseToIntArray(int(&temp_array)[3])
{
	int temp_num = 0;
	char * temp = m_str;

	temp = strtok(m_str, ".");

	for(int i = 0;  temp != nullptr; ++i)
	{
		temp_num = atoi(temp);
		temp = strtok(nullptr, ".");
		temp_array[i] = temp_num;
	}
}