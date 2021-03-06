#include <iostream>
#include "Projectile.hxx"
#include "Tank.hxx"
#include "Turret.hxx"
#include "generic/ofstreamext.hxx"

extern CL_ResourceManager* resources;
extern SpriteProviderStorage* storage;

const float circle = 6.2831854f;

Turret::Turret (boost::dummy_ptr<GameWorld>  w, 
		Tank* arg_tank, int r_speed, std::string surface, std::string fire) 
  : GameObj (w),
    fire_sur (storage->get (fire.c_str ())),
    sur (storage->get (surface.c_str ())),
    shadow (storage->get ("feuerkraft/turret2_shadow")),
    angle (0),
    fireing (false),
    reloading (0),
    reloading_speed (r_speed)
{
  tank = arg_tank;
}

Turret::~Turret ()
{
}

void 
Turret::draw (View* view)
{
  float absolute_angle = tank->get_angle () + angle;

#ifdef UGLY_SHADOWS_ENABLED  
  view->draw(shadow, tank->get_pos () + CL_Vector (10,10), absolute_angle);
  view->draw(shadow, tank->get_pos () + CL_Vector (15,15), absolute_angle);
  view->draw(shadow, tank->get_pos () + CL_Vector (20,20), absolute_angle);
  view->draw(shadow, tank->get_pos () + CL_Vector (25,25), absolute_angle);
#endif 

  view->draw (sur, tank->get_pos (), absolute_angle);

  if (fireing && reloading == 0 && tank->ammo > 0.0)
    {
      view->draw (fire_sur, tank->get_pos (), absolute_angle);
      fireing = false;
      reloading = reloading_speed;
    }
}

void
Turret::update (float delta)
{

  static bool floppy;

  if (reloading)
    reloading--;

  if (fireing && reloading == 0 && tank->ammo > 0.0)
    {
      tank->ammo -=  0.003 * delta;

      //std::cout << "Fireing..." << std::endl;
      float rot_angle = tank->get_angle () + angle + 3.1415927; //- fmod(angle, circle/16.0)
      
      CL_Vector dir = CL_Vector (10.0 + tank->get_velocity (), 0.0).rotate (rot_angle, CL_Vector (0.0, 0.0, 1.0));

      if (floppy)
	{
	  world->add (new Projectile (world, boost::dummy_ptr<GameObj>(tank.get()), 
				      tank->get_pos ()
				      + CL_Vector (0.0, -5.0, 0.0).rotate (rot_angle, CL_Vector (0.0, 0.0, 1.0)),
				      dir));
	}
      else
	{
	  world->add (new Projectile (world, tank.get(), tank->get_pos ()
				      + CL_Vector (0.0, 5.0, 0.0).rotate (rot_angle, CL_Vector (0.0, 0.0, 1.0)),
				      dir));
	}
      floppy = !floppy;
    }
}

void 
Turret::increase_angle (float delta)
{
  angle += tank->get_increment () * delta;
  //angle = fmod (angle + circle, circle);
}

void
Turret::decrease_angle (float delta)
{
  angle -= tank->get_increment ();
  //angle = fmod (angle + circle, circle);
}

void
Turret::start_fire ()
{
  fireing = true;
}

void
Turret::stop_fire ()
{
  fireing = false;
}

void 
Turret::set_angle (float arg_angle)
{
  angle = arg_angle;
}

// EOF 
