//  $Id: TileDataFactory.cxx,v 1.4 2002/03/24 23:26:40 grumbel Exp $
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

#include "TileData.hxx"
#include "SpriteTileData.hxx"
#include "SpriteTile.hxx"
#include "TileDataFactory.hxx"

TileData*
TileDataFactory::create (SCM desc)
{
  SCM symbol = gh_car (desc);
  SCM data   = gh_cdr (desc);
  
  if (gh_equal_p (gh_symbol2scm ("spritetile"), symbol))
    {
      return create_SpriteTileData (data);
    }
  else
    {
      std::cout << "TileDataFactory: Unknown tile type: '" << std::flush;
      gh_display (symbol);
      std::cout << "' with data: " << std::flush;
      gh_display (data);
      std::cout << std::endl;
      return 0;
    }
}

SpriteTileData*
TileDataFactory::create_SpriteTileData (SCM desc)
{
  SpriteTileData* sprite_data = new SpriteTileData ();

  //std::cout << "TileDataFactory:create_SpriteTileData:" << std::flush;
  //gh_display (desc);
  //std::cout << std::endl;

  while (!gh_null_p (desc))
    {
      SCM symbol = gh_caar(desc);
      SCM data   = gh_cdar(desc);

      if (gh_equal_p (gh_symbol2scm ("location"), symbol))
	{
	  char* str = gh_scm2newstr(gh_car (data), 0);
	  sprite_data->sprite_location = str;
#ifndef WIN32	// Freeing this crashed under VisualC++
	  free (str);
#endif	
	}
      else
	{
	  std::cout << "TileDataFactory: Unknown sprite tile type: '" << std::flush;
	  gh_display (symbol);
	  std::cout << "' with data: " << std::flush;
	  gh_display (data);
	  std::cout << std::endl;
	  return 0;
	}

      desc = gh_cdr (desc);
    }

  return sprite_data;
}

/* EOF */
