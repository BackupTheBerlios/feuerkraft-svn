//  $Id: TowerData.cxx,v 1.5 2002/03/24 23:26:40 grumbel Exp $
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
#include "Tower.hxx"
#include "TowerData.hxx"

TowerData::TowerData (SCM desc)
{
  // Default values
  start_energie = 100.0f;

  while (!gh_null_p (desc))
    {
      SCM symbol = gh_caar(desc);
      SCM data   = gh_cdar(desc);

      if (gh_equal_p (gh_symbol2scm ("angle"), symbol))
	{
	  angle = gh_scm2double(gh_car (data));
	}
      else if (gh_equal_p (gh_symbol2scm ("pos"), symbol))
	{
	  x_pos = gh_scm2int(gh_car (data));
	  y_pos = gh_scm2int(gh_cadr (data));
	}
      else if (gh_equal_p (gh_symbol2scm ("energie"), symbol))
	{
	  start_energie = gh_scm2double (gh_car (data));
	}
      else
	{
	  std::cout << "TowerData: Error: " << std::flush;
	  gh_display(symbol);
	  std::cout << std::endl;
	}

      desc = gh_cdr (desc);
    }
}

Building* 
TowerData::create (boost::dummy_ptr<GameWorld> world)
{
  return new Tower (world, *this); // FIXME: Bug!
}

/* EOF */
