//  $Id: ai_vehicle.hxx,v 1.1 2003/04/28 21:20:37 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#ifndef HEADER_AI_VEHICLE_HXX
#define HEADER_AI_VEHICLE_HXX

#include <list>
#include <ClanLib/Core/Math/cl_vector.h>
#include "game_obj.hxx"

struct Position
{
  float x;
  float y;
};

enum AIVehicleOrderType { 
  AI_VO_NONE, 
  AI_VO_DRIVETO, 
  AI_VO_WAIT, 
  AI_VO_CONTINUE
}; 

struct AIVehicleOrderNone
{
};

struct AIVehicleOrderDriveTo
{
  AIVehicleOrderType type;
  Position pos;
};

struct AIVehicleOrderWait
{
  AIVehicleOrderType type;
  /** Number of seconds to wait, -1 means forever, until next order is
      given */
  float seconds;
};

struct AIVehicleOrderContinue
{
  AIVehicleOrderType type;
  // Continue with the next order
};

union AIVehicleOrder
{
  AIVehicleOrderType type;

  AIVehicleOrderDriveTo  drive_to;
  AIVehicleOrderWait     wait;
  AIVehicleOrderContinue cont;
  AIVehicleOrderNone     none;
};

/** */
class AIVehicle : public GameObj
{
private:
  CL_Vector pos;
  float orientation;
  float velocity;

  CL_Sprite sprite;
  std::list<AIVehicleOrder> orders;

  AIVehicleOrder current_order;
public:
  AIVehicle(boost::dummy_ptr<GameWorld>  w, const CL_Vector& arg_pos);

  void update(float delta);
  void draw (View* view);

  void drive_to(const CL_Vector& pos);
  void add_order(AIVehicleOrder);
  void clear_orders();
  void next_order();
private:
  AIVehicle (const AIVehicle&);
  AIVehicle& operator= (const AIVehicle&);
};

#endif

/* EOF */