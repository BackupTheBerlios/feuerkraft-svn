//  $Id: player_view.hxx,v 1.1 2003/05/19 10:55:05 grumbel Exp $
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

#ifndef HEADER_PLAYER_VIEW_HXX
#define HEADER_PLAYER_VIEW_HXX

#include "vehicle_view.hxx"

class Player;

/** */
class PlayerView 
  : public VehicleView
{
private:
  Player* player;
public:
  PlayerView(int x1, int y1, int x2, int y2, 
             Player* arg_player);

  void update(float delta);
private:
  PlayerView (const PlayerView&);
  PlayerView& operator= (const PlayerView&);
};

#endif

/* EOF */
