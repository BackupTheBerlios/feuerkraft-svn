//  $Id: BuildingMap.cxx,v 1.2 2002/03/17 12:50:40 grumbel Exp $
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

#include <iostream>
#include "../View.hxx"
#include "BuildingData.hxx"
#include "BuildingMap.hxx"
#include "Building.hxx"

BuildingMap::BuildingMap(const BuildingMapData& data)
  : BuildingMapData (data),
    GameObj (0) // FIXME: Bug
{
  for (std::vector<BuildingData*>::iterator i = buildings_data.begin ();
       i != buildings_data.end ();
       ++i)
    {
      // FIXME: we need probally to pass the GameWorld pointer all
      // FIXME: around
      buildings.push_back ((*i)->create ());
    }

  // FIXME: Where is the width and height?!
  //building_map.resize (width * height);
  int width  = 0;
  int height = 0;
  
  // Clear all pointers in the building map
  for (std::vector<Building*>::iterator i = building_map.begin ();
       i != building_map.end ();
       ++i)
    {
      *i = NULL;
    }

  // 'Draw' the buildings onto the building_map
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      Building* building = *i;
      
      for (int x = building->get_x_pos();
	   x < building->get_x_pos() + building->get_map_width();
	   ++x)
	{
	  for (int y = building->get_y_pos(); 
	       y < building->get_y_pos() + building->get_map_height();
	       ++y)
	    {
	      if (x >= 0 && x < width && y >= 0 && y < height)
		building_map[(y * width) + x] = building;
	      else
		std::cout << "BuildingMap: Error: building position out of range: " << x << ", " << y << std::endl;
	    }
	}
    }
}

// Draw the object onto the screen
void
BuildingMap::draw (View* view)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->draw (view);
    }
}
  
// Update the object once a game loop
void
BuildingMap::update (float delta)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->update (delta);
    }
}

/* EOF */
