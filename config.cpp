class CfgPatches
{
	class PresetCubesFramework
	{
		requiredAddons[] = 
		{
			"DZ_Data",
            "DZ_Gear",
			"JM_CF_Scripts"
		};
	};
};

class CfgMods
{
	class PresetCubesFramework
	{
		type = "mod";
		dependencies[]={"World"};
		class defs
		{
            class worldScriptModule
            {
                files[] = {"PresetCubesFramework/scripts/4_World"};
            };
		};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class BlobDefault_Cube : Inventory_Base
	{
		scope = 1;
		displayName = "Base Cube";
		descriptionShort = "Don't really know why you'd spawn this in...";
		model="\DZ\gear\containers\ChristmasBox1.p3d";
		itemSize[] = {2,2};
		itemBehaviour = 2;
		weight = 5000;
		heavyItem=1;
		varQuantityMax=1;
	};
	class BlobExample_Cube : BlobDefault_Cube 
	{
		scope = 1;
		displayName = "Example cube";
		descriptionShort = "Example cube for others.";
	};
};