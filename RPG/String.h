#pragma once

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ostream;
using std::istream;
using std::ios;

/**********************************************************************
* Class: String
*
* Purpose: This class replaces the string class with very basic
*			functionality.
*
* Manager functions:
*		String()
*				Default constructor.
*
*		String(char ch)
*				Constructor that is called a class object is
*				initialized to a single character.
*
*		String(char* str)
*				Constructor that is called when a class object is
*				initialized with a string than contains more than one
*				character.
*
*		~String()
*				Deletes the memory allocated for a given string when
*				the object goes out of scope.
*
*		String(const String& copy)
*				Copy constructor for the String class. Will be called
*				when on object is passed by value, returned by value
*				or when another object of the same type is initialized
*				with an already existing object.
*
*		String& operator =(const String& rhs)
*				Assignment operator overload for the
*				String class. Will assign the values of
*				an object to another object that has already been
*				instantiated.
*
* Methods:
*		void Display()
*				Member function that will display the
*				contents of a String object.
*
*		char* Getm_str()
*				Returns the value of a String objects 'm_str'
*				data member. Used to access the private data member.
*
*		void Setm_str(char* setter)
*				Sets the value of m_str.
*
*		void ParseToIntArray(String temp_tok, int(&temp_array)[4])
*				Breaks m_str into an array of ints. Uses '.' as a
*				delimeter.
*
*		char* StringUpper(const String& to_upper)
*				Replaces all characters of a string with uppercase
*				values.
*
*		char* StringLower(const String& to_lower)
*				Replaces all characters of a string with lower case
*				values.
************************************************************************/

class String
{
	public:
		String();
		String(char ch);
		String(char * str);
		~String();
		String(const String & copy);
		String & operator =(const String & rhs);
		bool operator < (const String & rhs);
		bool operator > (const String & rhs);
		bool operator <= (const String & rhs);
		bool operator >= (const String & rhs);
		bool operator == (const String & rhs);
		bool operator != (const String & rhs);
		friend ostream & operator << (ostream & str, const String & rhs);
		friend istream & operator >> (istream & str, String & rhs);
		void Display() const;
		char * GetString() const;
		void SetString(char * setter);
		int StrLen() const;
		void ParseToIntArray(int(&temp_array)[3]);

	private:
		char * m_str;
};


