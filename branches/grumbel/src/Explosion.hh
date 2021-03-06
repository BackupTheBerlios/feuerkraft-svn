//  $Id: Explosion.hh,v 1.1 2001/02/17 20:02:10 grumbel Exp $
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

#ifndef EXPLOSION_HH
#define EXPLOSION_HH

#include <ClanLib/core.h>
#include "GameObj.hh"

extern CL_ResourceManager* resources;

class Explosion : public GameObj
{
private:
  bool is_drawn;
  int lifetime;
  CL_Surface explo;
  CL_Vector pos;

public:
  enum Size { SMALL, MEDIUM, LARGE };
  
  Explosion (const CL_Vector& arg_pos, Size size = SMALL) : 
    is_drawn (false),
    pos (arg_pos)
  {
    switch (size)
      {
      case SMALL:
      case LARGE:
	explo = CL_Surface("feuerkraft/smallexplo", resources);
	lifetime = 1;
	break;
      case MEDIUM:
	explo = CL_Surface("feuerkraft/mediumexplo", resources);
	lifetime = 5;
	break;
      }
  };

  void draw () {
    explo.put_screen (int(pos.x) - explo.get_width ()/2,
		      int(pos.y) - explo.get_height ()/2);
    is_drawn = true;
  }
  
  void update () {
    --lifetime;
  }

  bool removable () {
    return is_drawn && lifetime <= 0;
  }
};

#endif

/* EOF */
