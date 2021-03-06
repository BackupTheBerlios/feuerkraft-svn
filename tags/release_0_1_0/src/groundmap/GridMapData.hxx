//  $Id: GridMapData.hxx,v 1.3 2002/03/27 23:59:07 grumbel Exp $
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

#ifndef GRIDMAPDATA_HXX
#define GRIDMAPDATA_HXX

#include <vector>
#include <guile/gh.h>
#include "GroundType.hxx"
#include "GroundMapData.hxx"

class CL_SurfaceProvider;

class GridMapData : public GroundMapData
{
protected:
  int grid_width;
  int grid_height;

  /** The data of the grid */
  std::vector<GroundType> grid_data;
  
  CL_SurfaceProvider* provider;
  
public:
  GridMapData (SCM desc);
  virtual ~GridMapData ();

  GroundMap* create ();
private:
  void parse_from_file (SCM desc);
};

#endif

/* EOF */
