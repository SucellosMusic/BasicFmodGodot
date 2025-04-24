Godot v4.3
GDExtensions

This is a VERY basic integration of Fmod with Godot, and it's main purpose is to show some familiarity with the Fmod API without getting buried in the details of a full implementation.
In part because I don't need it for Godot anyway, but I needed an existing engine for this specific project.

That being said the following demo includes:
  1. setting software format
  2. creating and initiating an Fmod object
  3. testing that the Fmod object is valid
  4. loading Master, String, and TestEvent banks
  5. getting event description and creating event instance
  6. playing/stopping event instance
  7. releasing event instance
  8. unloading banks
  9. releasing the Fmod object

If looking at the src folder you'll see that the library files are in with all the .h/.cpp files. I know this isn't the ideal/proper way to organize files, but the Godot GDExtensions template came with a Sconstruct
file that I couldn't easily edit or add directories to so I eventually settled on just getting it to work. Afterall the goal here was to work with the Fmod API, not fumble around with a build system.
That's for another time.
