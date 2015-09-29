//---------------------------------------------------------------------------

#ifndef MiniUniverseH
#define MiniUniverseH

//---------------------------------------------------------------------------

#include <Vcl.h>
#include <vector>

#include "Region.h"
#include "Track.h"

//---------------------------------------------------------------------------

class TMiniUniverse
{
private:
	std::auto_ptr <TImage> FRenderBuffer;
	std::auto_ptr <TImage> FDeselectedRenderBuffer;

	// Remember Canvas to which we will copy.

	TCanvas* FDestinationCanvas;

	// Remember width and height of Canvas.

	int FWidth, FHeight;
	TRect FRect;

    // Remember session start and stop frames.
    
	int FSessionStartFrame, FSessionStopFrame;

	// Remember selection start and end frames.

	int FSelectionStart, FSelectionStop;

	void Display();

public:
	TMiniUniverse(TCanvas* DestinationCanvas, const int Width, const int Height);
	void RedrawUniverse
	(
		std::vector <TRegion> Regions,
		std::vector <TTrack> Tracks,
		const int SessionStart,
		const int SessionStop
	);
	void SetSelectionStart(const int Frame);
	void SetSelectionStop(const int Frame);
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------
