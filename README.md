# Description
A framework for creating boxes that spawn any items specified.

# Usage
To create a preset you must create a mod that uses this one as a dependency in the config.cpp
```cpp
class CfgPatches
{
  class MySubMod
  {
    requiredAddons[] =
    {
      "DZ_Data",
      "PresetCubesFramework"
    };
  };
};
```

Then, you must create the config for the new presets you create. There should be one created for each preset. You should set the displayName and descriptionShort in CfgVehicles
```cpp
class CfgVehicles
{
  class MyPreset_Cube : BlobDefault_Cube
  {
    displayName = "My item's display name";
    descriptionShort = "MY preset's description";
  };
};
```

Last, you must create the script to give your preset the items it should have. Create the script folder and "4_World" folder and set up the location in your CfgMods.
```cpp
class CfgMods
{
	class MyPresetCubeMod
	{
		type= "mod";
		dependencies[]={"World"};
		class defs
		{
			class worldScriptModule
			{
				files[] = {"MyPresetCubeMod/scripts/4_World"};
			};
		};
	};
};
```

Create the file you will put your preset in (`mydefaultcube.c`). For best organization use separate files for each preset and make sure each class name is unique. Once the file is created, you need to make a child class of `BlobDefault_Cube` and override
the GetItems() function to return your own array of items.
```cpp
class MyPresetCube : BlobDefault_Cube
{
  //Items must be the string that corresponds to the item
  override array<string> GetItems()
  {
    array<string> items = {"Stone", "Apple", "AnyItemYouWant"};
    return items;
	}
}
```
