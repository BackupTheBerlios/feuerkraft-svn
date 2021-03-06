//  $Id: helicopter.hpp,v 1.13 2003/06/22 17:22:47 grumbel Exp $
// 
//  Feuerkraft - A Tank Battle Game
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HELICOPTER_HH
#define HELICOPTER_HH

#include <ClanLib/Display/sprite.h>
#include "../energie.hpp"
#include "vehicle.hpp"
#include "rotor.hpp"

class VehicleAI;
class AList;

/** @ingroup units */
class Helicopter : public Vehicle
{
private:
  enum { FLYING, STARTING, LANDING, LANDED } state;
  float height;

  typedef std::vector<Rotor> Rotors;
  Rotors rotors;

  CL_Sprite heli;
  CL_Sprite heli_shadow;
  CL_Sprite helidestroyed;

  float strafe;
  int   reloading;
  float secondary_reload;
  Energie energie;
  bool destroyed;
  VehicleAI* ai;

public:
  Helicopter(const AList& lst);
  ~Helicopter();

  void draw (View& view);
  void update (float);
  float get_z_pos () { return destroyed ? 0 : 150; }

  void land_or_start();

  // Controllable impl
  virtual float get_turn_speed () { return 1.0; }

  virtual void drop_mine () {}

  bool is_colliding (FloatVector2d);
  void collide (Projectile*);
  virtual float get_physical_size () { return 3.0; }

  void attach_ai();
  void dettach_ai();

private:
  Helicopter(const Helicopter&);
  Helicopter& operator=(const Helicopter&);
};

#endif

/* EOF */
