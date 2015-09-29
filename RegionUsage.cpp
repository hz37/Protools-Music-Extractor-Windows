//---------------------------------------------------------------------------

#include "Generic.h"
#pragma hdrstop

//---------------------------------------------------------------------------

TRegionUsage::TRegionUsage
(
	const AnsiString Name,
	const int Length,
	std::vector <AnsiString> OriginalNames
):
FName(Name),
FLength(Length),
FOriginalNames(OriginalNames)
{

}

//---------------------------------------------------------------------------

// Copy constructor implemented in terms of = operator.

TRegionUsage::TRegionUsage(const TRegionUsage& Rhs)
{
	operator = (Rhs);
}

//---------------------------------------------------------------------------

// Assignment operator, used by copy constructor as well.

TRegionUsage& TRegionUsage::operator = (const TRegionUsage& Rhs)
{
	if(this != &Rhs)
	{
		FName = Rhs.FName;
		FLength = Rhs.FLength;
		FOriginalNames = Rhs.FOriginalNames;
	}

	return *this;
}

//---------------------------------------------------------------------------

bool TRegionUsage::operator != (const TRegionUsage& Rhs)
{
	return (FName != Rhs.FName);
}

//---------------------------------------------------------------------------

// Return reference to original names container.

void TRegionUsage::GetOriginalNames(std::vector <AnsiString>& OriginalNames)
{
	OriginalNames = FOriginalNames;
}

//---------------------------------------------------------------------------

