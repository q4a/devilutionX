/**
 * @file pfile.h
 *
 * Interface of the save game encoding functionality.
 */
#pragma once

#include "player.h"
#include "DiabloUI/diabloui.h"

namespace devilution {

#define MAX_CHARACTERS 99

extern bool gbValidSaveFile;

class PFileScopedArchiveWriter {
public:
	// Opens the player save file for writing
	PFileScopedArchiveWriter(bool clearTables = !gbIsMultiplayer);

	// Finishes writing and closes the player save file.
	~PFileScopedArchiveWriter();

private:
	int save_num_;
	bool clear_tables_;
};

const char *pfile_get_password();
void pfile_write_hero(bool writeGameData = false, bool clearTables = !gbIsMultiplayer);
bool pfile_ui_set_hero_infos(bool (*uiAddHeroInfo)(_uiheroinfo *));
void pfile_ui_set_class_stats(unsigned int playerClass, _uidefaultstats *classStats);
bool pfile_ui_save_create(_uiheroinfo *heroinfo);
bool pfile_delete_save(_uiheroinfo *heroInfo);
void pfile_read_player_from_save(uint32_t saveNum, int playerId);
bool LevelFileExists();
void GetTempLevelNames(char *szTemp);
void GetPermLevelNames(char *szPerm);
void pfile_remove_temp_files();
std::unique_ptr<byte[]> pfile_read(const char *pszName, size_t *pdwLen);
void pfile_update(bool forceSave);

} // namespace devilution
