//  $Id: building.cxx,v 1.1 2003/05/18 11:39:01 grumbel Exp $
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

#include "../property_set.hxx"
#include "building.hxx"

Building::Building (int x, int y)
  : x_pos(x), y_pos(y)
{
  register_properties();
}

Building::Building ()
{
  register_properties();
}

Building::~Building ()
{
  delete properties;
}

void
Building::register_properties()
{
  properties = new PropertySet();

  properties->register_int("x-pos", &x_pos);
  properties->register_int("y-pos", &y_pos);
}

/* EOF */