/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LASTEXPRESS_DEBUG_H
#define LASTEXPRESS_DEBUG_H

#include "gui/debugger.h"

#include "lastexpress/data/snd.h"

#include "lastexpress/shared.h"

namespace LastExpress {

enum {
	kLastExpressDebugGraphics = 1,
	kLastExpressDebugResource,
	kLastExpressDebugCursor,
	kLastExpressDebugSound,
	kLastExpressDebugSubtitle,
	kLastExpressDebugSavegame,
	kLastExpressDebugLogic,
	kLastExpressDebugScenes,
	kLastExpressDebugUnknown,
};

class LastExpressEngine;

class Debugger : public GUI::Debugger {
public:
	Debugger(LastExpressEngine *engine);
	~Debugger() override;

	bool hasCommand() const;
	void callCommand();

private:
	LastExpressEngine *_engine;

	bool cmdHelp(int argc, const char **argv);

	bool cmdListFiles(int argc, const char **argv);
	bool cmdDumpFiles(int argc, const char **argv);

	bool cmdShowFrame(int argc, const char **argv);
	bool cmdShowBg(int argc, const char **argv);
	bool cmdPlaySeq(int argc, const char **argv);
	bool cmdPlaySnd(int argc, const char **argv);
	bool cmdPlaySbe(int argc, const char **argv);
	bool cmdPlayNis(int argc, const char **argv);

	bool cmdLoadScene(int argc, const char **argv);
	bool cmdFight(int argc, const char **argv);
	bool cmdBeetle(int argc, const char **argv);

	bool cmdTimeDelta(int argc, const char **argv);
	bool cmdTime(int argc, const char **argv);
	bool cmdShow(int argc, const char **argv);
	bool cmdEntity(int argc, const char **argv);

	bool cmdSwitchChapter(int argc, const char **argv);
	bool cmdClear(int argc, const char **argv);

	void resetCommand();
	void copyCommand(int argc, const char **argv);
	int getNumber(const char *arg) const;

	bool loadArchive(int index);
	void restoreArchive() const;

	Debuglet *_command;
	int _numParams;
	char **_commandParams;

	// Special sound stream for playing sounds
	StreamedSound *_soundStream;
};

} // End of namespace LastExpress

#endif // LASTEXPRESS_DEBUG_H
