//---------------------------------------------------------------------------

#include "Generic.h"
#pragma hdrstop

//---------------------------------------------------------------------------

TTrack::TTrack(const AnsiString TrackName, const bool IsMono) :
FTrackName(TrackName),
FIsMono(IsMono),
FState(false)
{
	
}

//---------------------------------------------------------------------------

// Copy constructor implemented in terms of = operator.

TTrack::TTrack(const TTrack& Rhs)
{
	operator = (Rhs);
}

//---------------------------------------------------------------------------

TTrack::~TTrack()
{
    // MessageBeep(0xFFFFFFFF);
}

//---------------------------------------------------------------------------

// Assignment operator, used by copy constructor as well.

TTrack& TTrack::operator = (const TTrack& Rhs)
{
	if(&Rhs != this)
	{
		FTrackName = Rhs.FTrackName;
		FIsMono = Rhs.FIsMono;
		FState = Rhs.FState;
	}

	return *this;
}

//---------------------------------------------------------------------------

bool TTrack::operator != (const TTrack& Rhs)
{
	return (FTrackName != Rhs.FTrackName);
}

//---------------------------------------------------------------------------

