//---------------------------------------------------------------------------

#ifndef ProtoolsDataH
#define ProtoolsDataH

//---------------------------------------------------------------------------

#include <Vcl.h>

#include <vector>

#include "Region.h"
#include "RegionUsage.h"
#include "Storage.h"
#include "Track.h"

//---------------------------------------------------------------------------

class TProtoolsData
{
private:
	// Collection of all regions from a Protools session.
	// This array is updated when a new file is read from disk.

	std::vector <TRegion> FRegions;

	// Collection of filtered region usage (names with times) based on
	// user choices. This is the extraction from the regions collection
	// and is changed all the time when a user works with the interface.

	std::vector <TRegionUsage> FRegionUsages;

	// Collection of tracks, read from a Protools session text file.
	// This array is also used to store user selections in terms of
	// which track to use in the output and which not.

	std::vector <TTrack> FTracks;

	// Framerate in frames per second (25 in almost all cases for PAL sessions).

	int FFrameRate;

	// Current session's samplerate in Hz.

	double FSampleRate;

	// While scanning the Protools text export, we try to find the earliest
	// and latest frame used by the session so the interface can scale itself.

	int FStartFrame;
	int FStopFrame;

	// Protools 10 upwards has the session start timecode.
	// We currently only check if the hour isn't very large
	// in which case the session goes over midnight which we don't accept.

	int FSessionStartHour;

	// We remember the filename because it can be queried for.

	AnsiString FSessionFileName;

	// We remember the directory of the file we got so we can
	// default to that dir when saving/loading.

	AnsiString FInitialDirectory;

	// User preferences that tell us what should be filtered in the output.

	bool FIgnoreFade;
	bool FIgnoreShorter;
	int FIgnoreShorterThan;
	bool FIgnoreStringDataAfterExtension;
	bool FIgnoreStringDataAfterNew;
	bool FCombineSimilar;
	int FSelectionStart;
	int FSelectionStop;

	// Output data can be sorted either on name or time.

	bool FSortOnName;

	// Connection to persistent storage.

	TStorage* FStorage;

	bool ExtractHMSF(const AnsiString InputString, int& Hours, int& Mins, int& Secs, int& Frames);
	AnsiString FindCommonName(const AnsiString S1, const AnsiString S2);
	void GetRegionUsages
	(
		TStringList* TextData,
		TStringList* MusicDirectorData,
		const bool IncludeFrames,
		bool& MusicDirectorFound,
		const bool IncludeMusicDirectorScan
	);
	bool ParseMusicDirector(AnsiString Input, AnsiString& Output);
	void Reset();

protected:
	TProtoolsData();
	TProtoolsData(const TProtoolsData& Rhs);
	TProtoolsData& operator = (const TProtoolsData&);

public:
	static TProtoolsData* Instance();
	~TProtoolsData();

	void CombineSelectedItems(std::vector <int>& Indices);
	void DeleteRegionUsage(const int Index);
	void GenerateListing();
	int GetFrameRate();
	AnsiString GetInitialDirectory();
	std::vector <TRegion> GetRegions();
	void GetSessionBoundaries(int& SessionStart, int& SessionEnd);
	int GetSampleRate();
	void GetRegionUsages
	(
		TStringList* TextData,
		const bool IncludeFrames
	);
	void GetRegionUsages
	(
		TStringList* TextData,
		TStringList* MusicDirectorData,
		const bool IncludeFrames,
		bool& MusicDirectorFound
	);
	AnsiString GetTitle();
	std::vector <TTrack> GetTracks();
	bool LoadFileWithName(const AnsiString Filename);
	int RegionUsageCount();
	AnsiString RegionUsageNameAtIndex(const int Index);
	int RegionUsageTimeAtIndex(const int Index);
	void RenameRegionUsage(const int Index, const AnsiString NewName);
	void SetSelectionStart(const int SelectionStart);
	void SetSelectionStop(const int SelectionStop);
	void SetTrackState(bool Value, int Index);
	int SmallestStartFrame(const int SuggestedFrame);
	bool SortOnName(const bool Value);
	int LargestStopFrame(const int SuggestedFrame);
	int TrackCount();
	AnsiString TrackNameAtIndex(const int Index);
	bool TrackStateAtIndex(const int Index);
};

//---------------------------------------------------------------------------

#endif

//---------------------------------------------------------------------------

