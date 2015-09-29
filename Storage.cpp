//---------------------------------------------------------------------------

#include "Generic.h"
#pragma hdrstop

//---------------------------------------------------------------------------

static const AnsiString CRegKey  = "Software\\Protools Music Extractor";
static const HKEY CRegRoot = HKEY_CURRENT_USER;

//---------------------------------------------------------------------------

TStorage::TStorage()
{

}

//---------------------------------------------------------------------------

// Copy constructor in terms of assignment operator.

TStorage::TStorage(const TStorage& Rhs)
{
	operator = (Rhs);
}

//---------------------------------------------------------------------------

TStorage& TStorage::operator = (const TStorage&)
{
	// Singleton class, there's only one instance, so:

	return *this;
}

//---------------------------------------------------------------------------

// Singleton's single point of access.

TStorage* TStorage::Instance()
{
	static TStorage Storage;

	return &Storage;
}

//---------------------------------------------------------------------------

TStorage::~TStorage()
{

}

//---------------------------------------------------------------------------

int TStorage::GetValue(const AnsiString Key, const int DefaultValue)
{
	int Value = DefaultValue;

	std::auto_ptr <TRegistry> Registry(new TRegistry);

	Registry->RootKey = CRegRoot;
	Registry->OpenKey(CRegKey, true);

	try
	{
		if(Registry->ValueExists(Key))
		{
			Value = Registry->ReadInteger(Key);
		}
	}
	catch(...)
	{
		// Ignore.
	}

	Registry->CloseKey();

	return Value;
}

//---------------------------------------------------------------------------

void TStorage::PutValue(const AnsiString Key, const int Value)
{
	std::auto_ptr <TRegistry> Registry(new TRegistry);

	Registry->RootKey = CRegRoot;
	Registry->OpenKey(CRegKey, true);

	try
	{
		Registry->WriteInteger(Key, Value);
	}
	catch(...)
	{
		// Ignore.
	}

	Registry->CloseKey();
}

//---------------------------------------------------------------------------

