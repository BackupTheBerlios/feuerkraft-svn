//  $Id$
// 
//  Pingus - A free Lemmings clone
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

#ifndef HEADER_FEUERKRAFT_ERROR_HXX
#define HEADER_FEUERKRAFT_ERROR_HXX

#include <string>

/** Exception class for all Feuerkraft errors */
class FeuerkraftError
{
private:
  std::string message;
public:
  FeuerkraftError(const std::string& message) 
    : message(message) {}

  const char* what() const throw() { return message.c_str(); }
};

#endif

/* EOF */
