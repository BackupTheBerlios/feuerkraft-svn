//  $Id: vehicle.cxx,v 1.8 2003/06/06 09:49:00 grumbel Exp $
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

#include <iostream>
#include "vehicle.hxx"

Vehicle::Vehicle ()
  : ammo (1.0f), 
    fuel (1.0f)
{
  acceleration = 0;
  steering = 0;
  firing = false;
}

float 
Vehicle::get_ammo ()
{
  return ammo;
}

float 
Vehicle::get_fuel ()
{
  return fuel;
}

void 
Vehicle::refuel (float delta)
{
  fuel += 0.003 * delta;

  if (fuel > 1.0f)
    fuel = 1.0f;
}

void 
Vehicle::reload_ammo (float delta)
{
  ammo += 0.003 * delta;

  if (ammo > 1.0f)
    ammo = 1.0f;
}

void
Vehicle::update_controlls(const InputEventLst& events)
{
  for (InputEventLst::const_iterator i = events.begin(); i != events.end(); ++i)
    {
      switch (i->type)
        {
        case AXIS_EVENT:
          switch (i->axis.name)
            {
            case ACCELERATE_AXIS:
              //std::cout << "Accelerate: " << i->axis.pos << std::endl;
              acceleration = i->axis.pos;
              break;
            case ORIENTATION_AXIS:
              //std::cout << "Steering: " << i->axis.pos << std::endl;
              steering = i->axis.pos;
              break;
            default:
              std::cout << "Unknown axis: " << i->axis.name << std::endl;
            }
          break;
        case BUTTON_EVENT:
          switch(i->button.name)
            {
            case PRIMARY_FIRE_BUTTON:
              firing = i->button.down;
              break;
            default:
              std::cout << "Unknown button: " << i->button.name << std::endl;
            }
          break;
        default:
          std::cout << "Unknown event type: " << i->type << std::endl;
        }
    }
}

/* EOF */
