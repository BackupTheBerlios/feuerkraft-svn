//  $Id: explosion.hxx,v 1.4 2003/05/11 11:20:44 grumbel Exp $
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

#include <ClanLib/Display/sprite.h>
#include <ClanLib/Core/Math/cl_vector.h>

#include "game_obj.hxx"
#include "resource_manager.hxx"

class Explosion : public GameObj
{
private:
  bool is_drawn;
  float lifetime;
  CL_Sprite explo;
  CL_Vector pos;
  float new_particle_time;
  float size;
public:
  enum Size { SMALL, MEDIUM, LARGE } en_size;
  
  Explosion (const CL_Vector& arg_pos, Size arg_size = SMALL);
  void init ();

  void draw (View* view);
  void update (float);
  bool removable ();
  int get_z_pos ();
};

#endif

/* EOF */
