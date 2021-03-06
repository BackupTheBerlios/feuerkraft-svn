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

#include <ClanLib/Display/display.h>
#include <ClanLib/Core/System/system.h>
#include "fonts.hpp"
#include "unit.hpp"
#include "view.hpp"
#include "resource_manager.hpp"
#include "game_obj_manager.hpp"
#include "communication_dialog.hpp"

CommunicationDialog* CommunicationDialog::current_ = 0;

CommunicationDialog::CommunicationDialog()
{
  current_ = this;
  spike = resources->get_sprite("feuerkraft/dialogspike");
}

CommunicationDialog::~CommunicationDialog()
{
}

void
CommunicationDialog::draw (CL_GraphicContext& gc)
{
  for(Messages::iterator i = messages.begin(); i != messages.end(); ++i)
    {
      Unit* unit = dynamic_cast<Unit*>(GameObjManager::current()->get_object_by_id(i->first));
      if (unit)
        {
          CL_Font font = Fonts::font;
          CL_Rect bbox = font.bounding_rect(0, 0, i->second.text);

          FloatVector2d unit_pos   = View::current()->world_to_screen(unit->get_pos());
          FloatVector2d dialog_pos = unit_pos + FloatVector2d(0, -60 - bbox.get_height());

          spike.draw((int)unit_pos.x-15, (int)unit_pos.y-40);

          CL_Display::fill_rect(CL_Rect(CL_Point(int(dialog_pos.x - bbox.get_width()/2 - 10),
                                                 int(dialog_pos.y - 10)),
                                        CL_Size(bbox.get_width()  + 20, 
                                                bbox.get_height() + 20)),
                                CL_Color(0,0,0, 100));

          font.set_alignment(origin_top_center);
          font.draw(int(dialog_pos.x), int(dialog_pos.y), i->second.text);
        }
    }
}

void
CommunicationDialog::send(int unit_id, const std::string& text)
{
  Message message;

  message.time = CL_System::get_time();
  message.text = text;

  messages[unit_id] = message;
}

void
CommunicationDialog::update (float delta)
{
  // Remove old messages from the display
  for (Messages::iterator i = messages.begin(); i != messages.end(); ++i)
    {
      if (i->second.time + 2000 < CL_System::get_time())
        {
          messages.erase(i);
        }
    }
}

/* EOF */
