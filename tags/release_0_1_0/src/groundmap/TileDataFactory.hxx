//  $Id: TileDataFactory.hxx,v 1.3 2002/03/18 22:23:56 sphair Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef TILEFACTORY_HXX
#define TILEFACTORY_HXX

#include <guile/gh.h>

class TileData;
class SpriteTileData;

/** The tile factory is used to create a Tile out of an SCM
    description
    
    FIXME: This could also be placed in the constructor or does this
    FIXME: have any big advantages?
    FIXME: Disadvantages: SpriteTileData need public member variables
*/
class TileDataFactory
{
private:

public:
  static TileData* create (SCM desc);
  static SpriteTileData* create_SpriteTileData (SCM desc);
};

#endif

/* EOF */