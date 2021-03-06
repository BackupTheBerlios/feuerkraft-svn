//  $Id: BuildingData.hxx,v 1.3 2002/03/17 16:42:24 grumbel Exp $
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

#ifndef BUILDINGDATA_HXX
#define BUILDINGDATA_HXX

#include "../boost/dummy_ptr.hpp"

class Building;
class GameWorld;

class BuildingData
{
protected:
public:
  virtual Building* create (boost::dummy_ptr<GameWorld> world) =0;
};

#endif

/* EOF */
