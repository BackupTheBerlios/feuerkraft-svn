//  $Id: SpriteTile.cxx,v 1.4 2002/03/17 22:32:08 grumbel Exp $
// 
//  Feuerkraft
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef SPRITETILE_CXX
#define SPRITETILE_CXX

#include <ClanLib/display.h>
#include <SphriteLib/sphritelibGL.h>
#include "SpriteTile.hxx"
#include "../View.hxx"

extern SpriteProviderStorage* storage;
extern CL_ResourceManager* resources;

SpriteTile::SpriteTile (const SpriteTileData& data)
  : SpriteTileData (data),
    sprite (storage->get (sprite_location.c_str ()))
{
  sprite.setHotSpot (0,0);
}

void
SpriteTile::draw (View* view, float x, float y)
{
  //sprite->draw ((int) x, (int) y);
  view->draw(sprite, CL_Vector (x, y));
  //std::cout << "draw: " << sprite_location << std::endl;
}

/** FIXME: 'float delta' should be replaced with GameDelta */
void
SpriteTile::update (float delta)
{
  sprite.update (delta);
}

#endif

/* EOF */
