//  $Id: GroundType.hxx,v 1.3 2002/03/25 09:57:11 grumbel Exp $
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

#ifndef GROUNDTYPE_HXX
#define GROUNDTYPE_HXX

/** The GroundType defines the type of the ground, it has influence on
    the speed and acceleration of vehicles. It has also influence on
    the detonation type of shells and rocket (splash instead of a big
    explosion and such). */
enum GroundType 
{ 
  /** This GroundType is used to mark empty tiles, vehicles should not
      react and it and the Worlds groundmap must not return it,
      instead it should fallback to the default value for the current
      map. */
  GT_EMPTY,
  
  /** Wheel driven vehicles will be slower on this ground type, chain
      driven vehicles won't be much influenced by this */
  GT_SAND,

  /** FIXME: description */
  GT_GRASS,

  /** FIXME: description */
  GT_MUD,

  /** All vehicles can drive in flatwater, but some will seriously
      slow down */
  GT_FLATWATER,

  /** Land vehicle can't drive here, only ships and hovercrafts */
  GT_DEEPWATER,

  /** Street and parking places have the GroundType GT_ASPHALT, wheel
      vehicles will be fast on here. */
  GT_ASPHALT 
};

#endif

/* EOF */
