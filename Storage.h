//---------------------------------------------------------------------------

#ifndef StorageH
#define StorageH

//---------------------------------------------------------------------------

#include <Vcl.h>

//---------------------------------------------------------------------------

class TStorage
{
private:
protected:
	TStorage();
	TStorage(const TStorage& Rhs);
	TStorage& operator = (const TStorage&);
public:
	static TStorage* Instance();
	~TStorage();

	int GetValue(const AnsiString Key, const int DefaultValue);
	void PutValue(const AnsiString Key, const int Value);
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------

