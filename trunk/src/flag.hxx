//  $Id: flag.hxx,v 1.5 2003/05/18 21:15:06 grumbel Exp $
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

#ifndef FLAG_HH
#define FLAG_HH

#include <ClanLib/Display/sprite.h>
#include "game_obj.hxx"

class Flag : public GameObj
{
private:
  CL_Sprite sur;
  FloatVector2d pos;

public:
  Flag (FloatVector2d arg_pos);
  virtual ~Flag ();

  void draw (View* view);
  void update (float delta);

  int  get_z_pos () { return 50; }
  void set_pos (FloatVector2d arg_pos) { pos = arg_pos; }
};

#endif

/* EOF */
