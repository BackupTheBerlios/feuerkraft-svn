//  $Id: radar.hpp,v 1.12 2003/06/23 10:01:41 grumbel Exp $
// 
//  Feuerkraft - A Tank Battle Game
//  Copyright(C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef RADAR_HH
#define RADAR_HH

#include "vector2d.hpp"
#include "game_world.hpp"
#include "gui_obj.hpp"
#include "resource_manager.hpp"

class Building;
class Player;
class Vehicle;
typedef Player* PlayerPtr;

class Radar : public GuiObj
{
private:
  PlayerPtr player;
  
  CL_Sprite background;

  /** Position of the radar on the screen */
  FloatVector2d pos;

  float angle;

public:
  Radar(const FloatVector2d& arg_pos, PlayerPtr v);
  ~Radar();

  void draw(CL_GraphicContext& gc);
  void update(float delta);

  /** Draw a blip to the radar, where 'pos' is in world coordinates
      and size is the size of the object(1: projectile, 2: vehicle,
      3: large vehicle, 4: building) */
  void draw_blip(const FloatVector2d& pos, int size, 
		  float red = 1.0f, float green = 0.0f, float blue = 0.0f);

private:
  Radar(const Radar&);
  Radar& operator=(const Radar&);
};

typedef Radar* RadarPtr;

#endif

/* EOF */
