//  $Id: GameWorldData.cxx,v 1.2 2002/03/23 10:16:16 grumbel Exp $
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
#include "generic/ofstreamext.hxx"
#include "GameWorld.hxx"
#include "buildings/BuildingMapData.hxx"
#include "groundmap/GroundMapData.hxx"
#include "GameObjData.hxx"
#include "groundmap/GroundMapDataFactory.hxx"
#include "GameWorldData.hxx"

GameWorldData::GameWorldData ()
{
}

GameWorldData::GameWorldData (SCM desc)
{
  while (gh_pair_p(desc))
    {
      if (gh_pair_p (gh_car (desc)))
	{
	  SCM symbol = gh_caar(desc);
	  SCM data   = gh_cdar(desc);   

	  if (gh_symbol_p (symbol))
	    {
	      if (gh_equal_p (gh_symbol2scm ("groundmap"), symbol))
		{
		  groundmap_data = GroundMapDataFactory::create (data);
		}
	      else if (gh_equal_p (gh_symbol2scm ("buildingmap"), symbol)) 
		{
		  buildingmap_data = new BuildingMapData (data);
		}
	      else
		{
		  std::cout << "GameWorldData: Error: " << symbol << " " << data << std::endl;;
		}
	    }
	  else
	    {
	      std::cout << "GameWorldData: Error not a symbol: ";// << symbol << " " << data << std::endl;;
	      gh_display (symbol); gh_newline ();
	    }
	}
      else
	{
	  std::cout << "GameWorldData: Error not a pair: " << gh_car(desc) << std::endl;;
	}

      desc = gh_cdr(desc);
    }
}

GameWorldData::~GameWorldData ()
{
}

GameWorld*
GameWorldData::create ()
{
  return new GameWorld (*this);
}

/* EOF */
