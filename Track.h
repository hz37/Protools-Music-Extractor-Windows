//---------------------------------------------------------------------------

// Holds the information of a single track from the Protools session.
// A Track object will be stored in an array to represent the entire
// Protools session.

//---------------------------------------------------------------------------

// Instance of TTrack are place in an stl vector, hence we meet the
// vector requirements.

//---------------------------------------------------------------------------

#ifndef TrackH
#define TrackH

//---------------------------------------------------------------------------

#include <Vcl.h>

//---------------------------------------------------------------------------

class TTrack
{
private:
	// The name of the track. D1, D2, M1 (Stereo), etc.

	AnsiString FTrackName;

	// The selection state of this track.

	bool FState;

	// Is this a mono track or a stereo track.

	bool FIsMono;

public:
	TTrack(const AnsiString TrackName, const bool IsMono);
	TTrack(const TTrack& Rhs);
	~TTrack();
	TTrack& operator = (const TTrack& Rhs);
	bool operator != (const TTrack& Rhs);

	__property AnsiString TrackName = {read = FTrackName};
	__property bool State = {read = FState, write = FState};
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------

