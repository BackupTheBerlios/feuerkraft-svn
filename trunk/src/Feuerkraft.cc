/*
	Loads a single surface from a pcx file without using resource files.
*/

#include <ClanLib/jpeg.h>
#include <ClanLib/png.h>
#include <ClanLib/core.h>
#include <ClanLib/application.h>

#include "Feuerkraft.hh"
#include "GameWorld.hh"
#include "KeyboardController.hh"
#include "JoystickController.hh"
#include "Tank.hh"
#include "Jeep.hh"
#include "Tree.hh"
#include "Flag.hh"
#include "Helicopter.hh"
#include "Turret.hh"
#include "Tower.hh"
#include "Playfield.hh"
#include "Soldier.hh"
#include "VehicleView.hh"
#include "VehicleStatus.hh"
#include "Radar.hh"
#include "Screen.hh"
#include "Headquarter.hh"
#include "Basis.hh"
#include "Fuelstation.hh"
#include "Ammotent.hh"
#include "Background.hh"
#include "Stone.hh"
#include "System.hh"

CL_ResourceManager* resources;
Pathfinder datafiles;

/*CL_InputSourceProvider *
CL_ResourceManager::get_resource_provider(void) const 
{
  return 0;
}
*/
class Feuerkraft : public CL_ClanApplication
{
public:
  virtual char *get_title() { return "Surface application"; }
	
  virtual int main(int argc, char** argv)
  {
    try
      {
	srand (time (0));

	float sec_fraction = 20.0f;
	if (argc == 3)
	  {
	    if (strcmp (argv[1], "--speed") == 0
		&& sscanf (argv[2], "%f", &sec_fraction) == 1)
	      {

	      }
	    else
	      {
		std::cout << "Wrong args: " << argv[1] << " " << argv[2] << std::endl;
	      }
	  }

	datafiles.add_sig_files ("data/feuerkraft.scr");
	datafiles.add_back (".");
	datafiles.add_back ("..");
	datafiles.print ();

	try {
	  System::change_dir(datafiles.find_path ("data/feuerkraft.scr"));
	} catch (Pathfinder::FileNotFound e) {
	  std::cout << "Pathfinder:FileNotFound: " << e.filename << std::endl;
	}

	std::cout << "New Fraction Time: " << sec_fraction << std::endl;
		
	CL_SetupCore::init();
	CL_SetupDisplay::init();
	CL_SetupPNG::init ();
	CL_SetupJPEG::init ();

	// Set mode: 320x200 16 bpp
	CL_Display::set_videomode(800, 600, 16, false);
	CL_Display::clear_display ();
	CL_Display::flip_display ();
		
	resources =  new CL_ResourceManager (datafiles.find("data/feuerkraft.scr").c_str (),
					     false);

	GameWorld world;
	Screen    screen;

	Tank* tank1 = new Tank(&world, CL_Vector (400, 0), 5, "feuerkraft/tank", "feuerkraft/turret", "feuerkraft/fire");
	Tank* tank2 = new Tank(&world, CL_Vector (0, 0), 5, "feuerkraft/tank2", "feuerkraft/turret2", "feuerkraft/fire2");
	Helicopter* heli = new Helicopter (&world, CL_Vector (320, 200));
	//Helicopter* heli2 = new Helicopter (CL_Vector (320, 200));
	Jeep* jeep = new Jeep (&world, CL_Vector (250, 250));

	JoystickController controller(tank1);
	KeyboardController kcontroller (tank2);

	//Radar radar1 (CL_Vector(800-64, 64), 
		      //&world, tank1);

	//Radar radar2 (CL_Vector(64, 64), 
		      //&world, tank2);
	
	boost::shared_ptr<GuiObj> radar 
	  = boost::shared_ptr<GuiObj>(new Radar (CL_Vector(64, 64), 
						 &world, tank2));
	screen.add (radar);
	screen.add (boost::shared_ptr<GuiObj>(new VehicleStatus (tank2)));
	//View view (&world, 10, 10, 790, 590);

	world.add (jeep);
	world.add (heli);
	//world.add (heli2);
	world.add (tank1);
	world.add (tank2);
	world.add (new Background (&world, CL_Surface ("feuerkraft/sand", resources)));
	world.add (new Basis (&world, CL_Vector(0, 0)));
	world.add (new Basis (&world, CL_Vector(400, 0)));
	world.add (new Playfield (&world));
	world.add (new Flag (&world, CL_Vector(200.0f, 200.f)));
	world.add (new Fuelstation (&world, CL_Vector (-100.0f, 300.0f)));
	world.add (new Ammotent (&world, CL_Vector (-200.0f, 300.0f)));
	world.add (new Tower (&world, 400.0, 200.0));
	world.add (new Tower (&world, 600.0, 400.0));
	world.add (new Tower (&world, 600.0, 100.0));
	world.add (new Headquarter (&world, CL_Vector (-100.0, 0.0)));
	
	for (int i = 0; i < 20; ++i)
	  {
	    world.add (new Stone (&world, CL_Vector (rand () % 2048 - 1024,
						     rand () % 2048 - 1024)));
	  }

	world.add (new Tree (&world, CL_Vector (100, 400), "feuerkraft/tree"));
	world.add (new Tree (&world, CL_Vector (400, 440), "feuerkraft/tree"));
	world.add (new Tree (&world, CL_Vector (400, 440), "feuerkraft/tree"));

	world.add (new Soldier (&world, CL_Vector (200, 200)));
	world.add (new Soldier (&world, CL_Vector (300, 300)));
	world.add (new Soldier (&world, CL_Vector (150, 400)));
	world.add (new Soldier (&world, CL_Vector (550, 400)));
	world.add (new Soldier (&world, CL_Vector (550, 100)));

	/** 1/30sec = 1.0delta
	 */
	float delta;
	int last_time = CL_System::get_time ();

	int loops = 0;
	float deltas = 0.0;

	VehicleView view (&world, tank2, 0, 0, 800, 600);
	view.set_view (400, 300);
	
	//VehicleView view1 (&world, heli, 0, 0, 399, 600);
	//VehicleView view2 (&world, tank1, 400, 0, 800, 600);
	
	int start_time = CL_System::get_time ();
	int frames = 0;

	    CL_System::keep_alive();
	// Loop until the user hits escape:
	while (CL_Keyboard::get_keycode(CL_KEY_ESCAPE) == false)
	  {	
	    CL_System::sleep (50);
	    delta = (CL_System::get_time () - last_time) / sec_fraction;
	    last_time = CL_System::get_time ();
	    world.update (delta);
	    
	    deltas += delta;
	    ++loops;

	    view.draw ();
	    view.update (delta);

	    screen.update (delta);
	    screen.draw ();
	      
	    controller.update (delta);
	    kcontroller.update (delta);

	    // Flip front and backbuffer. This makes the changes visible:
	    CL_Display::flip_display();
	    ++frames;
	    
	    // Update keyboard input and handle system events:
	    // Exits the loop if ClanLib requests shutdown - for instance if
	    // someone closes the window.
	    CL_System::keep_alive();
	  }

	std::cout << "Avarage delta: " << deltas/loops << std::endl;
	std::cout << "Avarage fps:   " 
		  << float (frames) / (CL_System::get_time () - start_time) * 1000.0 << std::endl;

	CL_SetupJPEG::deinit ();
	CL_SetupPNG::deinit ();
	CL_SetupDisplay::deinit();
	CL_SetupCore::deinit();
      }
    catch (CL_Error err)
      {
	std::cout << "CL_Error: " << err.message.c_str() << std::endl;
      }

    return 0;
  }
} feuerkraft;

  // EOF 
