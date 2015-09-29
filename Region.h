//---------------------------------------------------------------------------

// Instance of TRegion are place in an stl vector, hence we meet the
// vector requirements.

//---------------------------------------------------------------------------

#ifndef RegionH
#define RegionH

//---------------------------------------------------------------------------

#include <Vcl.h>

//---------------------------------------------------------------------------

class TRegion
{
private:
	AnsiString FName;
	AnsiString FTrackName;
	int FStartFrame;
	int FStopFrame;
	int FLength;
	bool FIsMono;

public:
	TRegion
	(
		const AnsiString Name,
		const AnsiString TrackName,
		const int StartFrame,
		const int StopFrame,
		const int Length,
		const bool IsMono
	);

	TRegion(const TRegion& Rhs);
	TRegion& operator = (const TRegion& Rhs);
	bool operator != (const TRegion& Rhs);

	__property AnsiString Name = {read = FName};
	__property AnsiString TrackName = {read = FTrackName};
	__property int StartFrame = {read = FStartFrame};
	__property int StopFrame = {read = FStopFrame};
	__property int Length = {read = FLength};
	__property bool IsMono = {read = FIsMono};

};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
