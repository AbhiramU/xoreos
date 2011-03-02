/* eos - A reimplementation of BioWare's Aurora engine
 * Copyright (c) 2010-2011 Sven Hesse (DrMcCoy), Matthew Hoops (clone2727)
 *
 * The Infinity, Aurora, Odyssey and Eclipse engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 *
 * This file is part of eos and is distributed under the terms of
 * the GNU General Public Licence. See COPYING for more informations.
 */

/** @file engines/nwn/menu/charpremade.h
 *  The premade character chooser.
 */

#ifndef ENGINES_NWN_MENU_CHARPREMADE_H
#define ENGINES_NWN_MENU_CHARPREMADE_H

#include "engines/nwn/menu/gui.h"

namespace Aurora {
	class GFFStruct;
}

namespace Engines {

namespace NWN {

struct Character {
	Common::UString file;
	Common::UString fullName;
	Common::UString classes;
	uint n;

	Character();
	Character(const Common::UString &f);

	bool empty() const;
};

class WidgetListItemCharacter : public WidgetListItem {
public:
	WidgetListItemCharacter(::Engines::GUI &gui, const Common::UString &font,
	                        const Character &c, float spacing = 0.0);
	~WidgetListItemCharacter();

	void show();
	void hide();

	void setPosition(float x, float y, float z);

	float getWidth () const;
	float getHeight() const;

	void setTag(const Common::UString &tag);

protected:
	bool activate();
	bool deactivate();

private:
	Graphics::Aurora::Model *_button;
	Graphics::Aurora::Text  *_textName;
	Graphics::Aurora::Text  *_textClass;

	float _spacing;
};

/** The NWN character creator. */
class CharPremadeMenu : public GUI {
public:
	CharPremadeMenu();
	~CharPremadeMenu();

	void show();

protected:
	void fixWidgetType(const Common::UString &tag, WidgetType &type);

	void callbackActive(Widget &widget);

private:
	GUI *_charNew;

	std::vector<Character> _characters;

	Common::UString getSelectedCharacter();

	void initCharacterList();
	void playCharacter();
};

} // End of namespace NWN

} // End of namespace Engines

#endif // ENGINES_NWN_MENU_CHARPREMADE_H
