//  $Id$
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include "ground_type.hpp"

std::string GroundType2string(const GroundType& a)
{
  switch (a)
    {
    case GT_EMPTY:
      return "empty";
    case GT_SAND:
      return "sand";
    case GT_GRASS:
      return "grass";
    case GT_MUD:
      return "mud";
    case GT_FLATWATER:
      return "flatwater";
    case GT_DEEPWATER:
      return "deepwater";
    case GT_ASPHALT: 
      return "asphalt";
    case GT_WETSAND:
      return "wetsand";
    default:
      return "unknown";
    }
}

/* EOF */
