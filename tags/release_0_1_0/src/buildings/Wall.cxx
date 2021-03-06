//  $Id: Wall.cxx,v 1.2 2002/03/26 16:46:36 grumbel Exp $
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

#include "../Radar.hxx"
#include "../View.hxx"
#include "Wall.hxx"

extern SpriteProviderStorage* storage;
extern CL_ResourceManager* resources;

Wall::Wall (boost::dummy_ptr<GameWorld> world, const WallData& data)
  : Building (world),
    WallData (data),
    pos (x_pos * 40 + 20, y_pos * 40 + 20),
    wall (storage->get("feuerkraft/wall")),
    wall_damaged (storage->get ("feuerkraft/wall_damaged")),
    wall_destroyed (storage->get ("feuerkraft/wall_destroyed"))
{
}

Wall::~Wall ()
{
}

void 
Wall::draw (boost::dummy_ptr<View> view)
{
  if (energie > 60)
    view->draw (wall, pos);
  else if (energie > 0)
    view->draw (wall_damaged, pos);
  else
    view->draw (wall_destroyed, pos);
}

void
Wall::draw_radar (boost::dummy_ptr<Radar> radar)
{
  radar->draw_blip (pos, 2);
}

void
Wall::update(float)
{
}

void 
Wall::collide (Projectile*)
{
  energie -= 25;
}

bool
Wall::alive ()
{
  return energie > 0;
}

/* EOF */
