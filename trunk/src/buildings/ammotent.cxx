//  $Id: ammotent.cxx,v 1.12 2003/06/22 18:34:52 grumbel Exp $
//
//  Feuerkraft - A Tank Battle Game
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

#include <math.h>
#include "../color.hxx"
#include "../game_obj_manager.hxx"
#include "../radar.hxx"
#include "../resource_manager.hxx"
#include "../vehicles/vehicle.hxx"
#include "ammotent.hxx"

Ammotent::Ammotent (const AList& lst)
  : Building (lst),
    ammotent (resources->get_sprite("feuerkraft/ammotent")),
    pos (x_pos * 40 + 40, y_pos * 40 + 60), // FIXME: Hard coded tilesize again...
    reloading(false)
{
}

Ammotent::~Ammotent ()
{
}

void 
Ammotent::draw (View& view)
{
  view.draw (ammotent, pos);
  if (reloading)
    {
      view.draw_fillrect(int(pos.x - 32), int (pos.y + 25),
			  int(pos.x + 31), int (pos.y + 57),
			  Color(1.0f, 1.0f, 1.0f, 
                                sin(GameWorld::current()->get_time () * 10.0f) * .3f + .5f));
    }
}

void
Ammotent::draw_radar (Radar& radar)
{
  radar.draw_blip (pos, 4, 0, 0, 1.0f);
}

void 
Ammotent::update (float delta)
{
  delta *= 50;

  reloading = false;

  GameObjManager* objs = GameWorld::current()->get_game_obj_manager();
  for (GameObjManager::iterator i = objs->begin(); i != objs->end(); ++i)
    {
      Vehicle* vehicle = dynamic_cast<Vehicle*>(*i);

      if (vehicle && (vehicle->get_pos ().x > pos.x - 40
		      && vehicle->get_pos ().x < pos.x + 40
		      && vehicle->get_pos ().y > pos.y + 20
		      && vehicle->get_pos ().y < pos.y + 60))
	{
	  if (vehicle->get_velocity () == 0.0)
	    {
	      vehicle->reload_ammo (delta);
	      reloading = true;
	    }
	}
    }
}

/* EOF */
