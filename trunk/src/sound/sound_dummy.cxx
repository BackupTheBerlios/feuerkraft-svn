//  $Id: sound_dummy.cxx,v 1.1 2003/05/04 19:13:51 grumbel Exp $
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
#include "../globals.hxx"
#include "sound_dummy.hxx"

namespace Sound {

void
PingusSoundDummy::real_play_sound(const std::string & filename, float /*volume*/, float /*panning*/)
{
  std::cout << "PingusSoundDummy::real_play_sound: " << filename << std::endl;
}


void
PingusSoundDummy::real_play_music(const std::string & filename, float /*volume*/)
{
  std::cout << "PingusSoundDummy::real_play_music: " << filename << std::endl;
}

void
PingusSoundDummy::real_stop_music()
{
}

} // namespace Sound

/* EOF */
