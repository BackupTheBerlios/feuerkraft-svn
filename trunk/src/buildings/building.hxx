//  $Id: building.hxx,v 1.5 2003/05/10 22:41:28 grumbel Exp $
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

#ifndef BUILDING_HXX
#define BUILDING_HXX

#include "../boost/dummy_ptr.hpp"
#include "building_data.hxx"

class View;
class GameWorld;
class Projectile;
class Radar;

class Building
{
private:
  boost::dummy_ptr<GameWorld> world;

  int id;
protected:
  int x_pos;
  int y_pos;
public:
  Building (boost::dummy_ptr<GameWorld> w, int x, int y)
    : world (w), x_pos(x), y_pos(y)
  {}

  Building ()
    : world(0)
  {}

  void set_id(int i) { id = i; }
  int  get_id() { return id; }

  virtual BuildingData* get_data () { return 0; }

  // Draw the object onto the screen
  virtual void draw (boost::dummy_ptr<View> view) =0;

  virtual void draw_energie (boost::dummy_ptr<View> view) {}
  
  virtual void draw_radar (boost::dummy_ptr<Radar> radar) {}

  // Update the object once a game loop
  virtual void update (float) =0;

  int get_x_pos () { return x_pos; }
  int get_y_pos () { return y_pos; }
  
  /** Returns the width which this building will take on the BuildingMap */
  virtual int get_map_width () =0;

  /** Returns the height which this building will take on the BuildingMap */
  virtual int get_map_height () =0;

  GameWorld* get_world () { return world.get(); }

  virtual void collide (Projectile*) {}

  /** is_at() can be overwritten to provide a more detailed building
      'resolution', so that buildings can be subgrid large 
      FIXME: Looks a bit hack like and doesn't work at polygon level  */
  virtual bool is_at (float x, float y) { return true; }

  /** If returns false the building is temporary inactive and will be
      'removed' from the collision map */
  virtual bool is_active() { return true; }

  /** If returns true the building will act normal, when returning
      false the building will 'disapear' from the collision map
   */
  virtual bool alive () { return true; }
};

#endif

/* EOF */
