//  $Id: Wall.hxx,v 1.3 2002/04/02 09:52:57 grumbel Exp $
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

#ifndef WALL_HXX
#define WALL_HXX

#include <ClanLib/core.h>
#include <ClanLib/display2.h>
#include "WallData.hxx"
#include "Building.hxx"

class Wall : public Building,
	     public WallData
{
private:
  CL_Vector pos;
  CL_Sprite wall;
  CL_Sprite wall_damaged;
  CL_Sprite wall_destroyed;

public:
  Wall (boost::dummy_ptr<GameWorld> world, const WallData&);
  virtual ~Wall ();

  void draw (boost::dummy_ptr<View> view);
  void draw_radar (boost::dummy_ptr<Radar> radar);

  void update(float);
  void collide (Projectile*);

  int get_x_pos () { return x_pos; }
  int get_y_pos () { return y_pos; }

  int get_map_width ()  { return 1; }
  int get_map_height () { return 1; }

  bool alive ();
};

#endif

/* EOF */
