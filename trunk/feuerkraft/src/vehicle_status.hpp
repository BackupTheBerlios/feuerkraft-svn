//  $Id: vehicle_status.hpp,v 1.7 2003/06/06 09:49:00 grumbel Exp $
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

#ifndef VEHICLESTATUS_HH
#define VEHICLESTATUS_HH

#include "gui_obj.hpp"

class VehicleStatus : public GuiObj
{
private:
  CL_Sprite ammo;
  CL_Sprite fuel;

public:
  VehicleStatus ();
  virtual ~VehicleStatus ();
  void update (float delta);
  void draw (CL_GraphicContext& gc);
  void draw_rect (int x_pos, int y_pos, float fill);
};

#endif

/* EOF */
