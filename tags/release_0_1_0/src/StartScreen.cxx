//  $Id: StartScreen.cxx,v 1.1 2002/03/28 23:53:32 grumbel Exp $
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

#include <ClanLib/core.h>
#include "StartScreen.hxx"

extern SpriteProviderStorage* storage;

StartScreen::StartScreen ()
  : logo (storage->get ("feuerkraft/logo")),
    endlogo (storage->get ("feuerkraft/endlogo")),
    display_time (0),
    logo_mode (S_STARTLOGO)
{
}

StartScreen::~StartScreen ()
{
}

void 
StartScreen::draw ()
{
  if (logo_mode == S_STARTLOGO)
    {
      if (display_time <= 2.0f)
	logo.setAlpha ((display_time/2.0f));
      else
	logo.setAlpha (1.0f);
  
      CL_Display::clear_display ();    
      logo.draw (CL_Display::get_width ()/2,
		 CL_Display::get_height ()/2);
    }
  else if (logo_mode == S_FADETOGAME)
    {
      if (display_time <= 1.5f)
	{
	  logo.setAlpha (1.0f - (display_time/1.5f));
	  logo.draw (CL_Display::get_width ()/2,
		     CL_Display::get_height ()/2);
	}
      else
	logo_mode = S_GAME;
    }
  else if (logo_mode == S_GAME)
    {
      // do nothing
    }
  else if (logo_mode == S_ENDLOGO)
    {
      if (display_time <= 1.5f)
	  endlogo.setAlpha ((display_time/1.5f));
      else
	  endlogo.setAlpha (1.0f);

      endlogo.draw (CL_Display::get_width ()/2,
		    CL_Display::get_height ()/2);
    }
  else if (logo_mode == S_FADETOBLACK)
    {
      endlogo.setAlpha (1.0f);
      endlogo.draw (CL_Display::get_width ()/2,
		    CL_Display::get_height ()/2);

      CL_Display::fill_rect (0, 0,
			     CL_Display::get_width (),
			     CL_Display::get_height (),
			     0, 0, 0,
			     display_time/2.0f);
      if (display_time >= 2.0f)
	logo_mode = S_QUIT;
    }
}

void 
StartScreen::update (float delta)
{
  display_time += delta;

  if (logo_mode == S_STARTLOGO && (CL_Keyboard::get_keycode (CL_KEY_ESCAPE)
				   || CL_Keyboard::get_keycode (CL_KEY_SPACE)
				   || CL_Keyboard::get_keycode (CL_KEY_ENTER)))
    {
      while (CL_Keyboard::get_keycode (CL_KEY_ENTER)
	     || CL_Keyboard::get_keycode (CL_KEY_ESCAPE)
	     || CL_Keyboard::get_keycode (CL_KEY_SPACE))
	CL_System::keep_alive ();

      logo_mode = S_FADETOGAME;
      display_time = 0;
    }
  else if (logo_mode == S_GAME  && (CL_Keyboard::get_keycode (CL_KEY_ESCAPE)))
    {
      while (CL_Keyboard::get_keycode (CL_KEY_ESCAPE))
	CL_System::keep_alive ();

      display_time = 0;
      logo_mode = S_ENDLOGO;
    }
  else if (logo_mode == S_ENDLOGO && (CL_Keyboard::get_keycode (CL_KEY_ESCAPE)
				      || CL_Keyboard::get_keycode (CL_KEY_SPACE)
				      || CL_Keyboard::get_keycode (CL_KEY_ENTER)))
    {
      while (CL_Keyboard::get_keycode (CL_KEY_ENTER)
	     || CL_Keyboard::get_keycode (CL_KEY_ESCAPE)
	     || CL_Keyboard::get_keycode (CL_KEY_SPACE))
	CL_System::keep_alive ();


      logo_mode = S_FADETOBLACK;
      display_time = 0;
    }
  
}

bool 
StartScreen::done ()
{
  return logo_mode == S_FADETOGAME;
}

/* EOF */
