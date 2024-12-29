class CfgPatches
{
	class PresetCubesFramework
	{
		requiredAddons[] = 
		{
			"DZ_Data",
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
		scope=1;
		displayName = "Base Cube";
		descriptionShort = "test";
		model="\DZ\gear\containers\ChristmasBox1.p3d";
		itemSize[] = {2,2};
		weight = 5000;
	};
	class BlobExample_Cube : BlobDefault_Cube 
	{
		scope=2;
		displayName = "Example cube";
		descriptionShort = "Example cube for others.";
	};
};