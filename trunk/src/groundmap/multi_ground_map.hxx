//  $Id: multi_ground_map.hxx,v 1.2 2003/04/19 23:17:53 grumbel Exp $
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

#ifndef MULTIGROUNDMAP_HXX
#define MULTIGROUNDMAP_HXX

#include <vector>
#include "multi_ground_map_data.hxx"
#include "ground_map.hxx"

class MultiGroundMap : public GroundMap,
		       public MultiGroundMapData
{
private:
  std::vector<GroundMap*> maps;

public:
  MultiGroundMap (const MultiGroundMapData& data);
  ~MultiGroundMap ();

  /** Return the type of ground, x and y are in world coordinates */
  GroundType get_groundtype (float x, float y);
  
  void draw(View*);
  void draw_levelmap (LevelMap* levelmap);

  void add (GroundMap* groundmap);
};

#endif

/* EOF */