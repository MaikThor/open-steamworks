//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ISTEAMAPPS004_H
#define ISTEAMAPPS004_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
class ISteamApps004
{
public:
	virtual bool IsSubscribed() = 0;
	virtual bool IsLowViolence() = 0;
	virtual bool IsCybercafe() = 0;
	virtual bool IsVACBanned() = 0;
	virtual const char *GetCurrentGameLanguage() = 0;
	virtual const char *GetAvailableGameLanguages() = 0;

	// only use this member if you need to check ownership of another game related to yours, a demo for example
	virtual bool IsSubscribedApp( AppId_t appID ) = 0;

	// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
	virtual bool IsDlcInstalled( AppId_t appID ) = 0;

	virtual uint32 GetEarliestPurchaseUnixTime( AppId_t appID ) = 0;
	virtual bool IsSubscribedFromFreeWeekend() = 0;

	virtual int GetDLCCount() = 0;
	virtual bool GetDLCDataByIndex(int iIndex, AppId_t* pAppID, bool *, char *, int) = 0;

	virtual void InstallDLC( AppId_t appID ) = 0;
	virtual void UninstallDLC( AppId_t appID ) = 0;
};


#endif // ISTEAMAPPS004_H
