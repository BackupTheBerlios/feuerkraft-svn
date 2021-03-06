//  $Id: Field.hxx,v 1.1 2001/12/12 00:00:32 grumbel Exp $
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

#ifndef FIELD_HXX
#define FIELD_HXX

#include <vector>

template<class T>
class Field
{
private:
  int width;
  int height;
  std::vector<T> data;
public:
  Field (int arg_width, int arg_height)
    : width (arg_width), height (arg_width)
  {
    data.resize (width * height);
  }

  void resize (int arg_width, int arg_height) 
  {
    width  = arg_width;
    height = arg_width;
    data.resize (width * height);
  }

  T& operator () (int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height)
      {
	std::cout << "Field: out of region: " << x << " " << y << std::endl;
      }

    return data[width * y + x];
  }
};

#endif

/* EOF */
