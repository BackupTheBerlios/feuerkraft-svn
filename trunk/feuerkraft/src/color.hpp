//  $Id: color.hpp,v 1.2 2003/06/03 14:11:22 grumbel Exp $
// 
//  Feuerkraft - A Tank Battle Game
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_COLOR_HXX
#define HEADER_COLOR_HXX

#include <ClanLib/Display/color.h>

/** */
class Color
{
private:
public:
  float red;
  float green;
  float blue;
  float alpha;

  /** Init the color to white */
  Color();
  
  /** Set color to the given RGB value */
  Color(float red_, float green_, float blue_, float alpha_ = 1.0f);

  /** @return the CL_Color version of the same color */
  CL_Color get_cl_color() const;
};

#endif

/* EOF */
