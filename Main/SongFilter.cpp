#include "stdafx.h"
#include "SongFilter.hpp"

Map<int32, MapIndex*> LevelFilter::GetFiltered(const Map<int32, MapIndex*>& source)
{
	Map<int32, MapIndex*> filtered;
	for (auto kvp : source)
	{
		for (auto diff : kvp.second->difficulties)
		{
			if (diff->settings.level == m_level)
				filtered.Add(kvp.first, kvp.second);
		}
	}
	return filtered;
}

String LevelFilter::GetName()
{
	return Utility::Sprintf("Level: %d", m_level);
}

bool LevelFilter::IsAll()
{
	return false;
}

Map<int32, MapIndex*> FolderFilter::GetFiltered(const Map<int32, MapIndex*>& source)
{
	return m_mapDatabase->FindMapsByFolder(m_folder);
}

String FolderFilter::GetName()
{
	return "Folder: " + m_folder;
}

bool FolderFilter::IsAll()
{
	return false;
}
