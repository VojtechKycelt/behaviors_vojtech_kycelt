#include "\vbs2\basic_defines.hpp"
#define __CurrentDir__ \vbs2\customer\plugins\behaviors_sample

//Class necessary for VBS to load the new addon correctly
class CfgPatches
{
	class vbs2_vbs_plugins_behaviors_sample
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.10;
		requiredAddons[] = {
			vbs2_editor, 
			vbs2_people,
			vbs2_vbs_plugins_standard_behaviors,
		};
		modules[] =
		{
			vbs_core_content_module
		};
	};
};

// Adds btset to list of btsets which are loaded automatically
class CfgBehaviorTrees
{
	class behaviors_sample //this is an arbitrary className, it needs to be unique though
	{
		path = "\vbs2\customer\plugins\behaviors_sample\data\behaviors_sample\behaviors_sample.btset"; //This is the relative path to the BT-set file to load
		name = "behaviors_sample"; // This is the btset name duplicated in the configuration
	};
};

class vbs_functions_base;
class CfgFunctions
{
	// Macro to build a function in sripts top folder
	#define MAKE_CORE_FUNCTION(functionName)                                 \
	class fn_vbs_behaviors_sample_##functionName : vbs_functions_base                     \
	{                                                                       \
		path = __CurrentDir__\data\scripts\fn_vbs_behaviors_sample__##functionName##.sqf;  \
	}

};

// Defines the new order as available from the Control AI - Military
class CfgAvailableBehaviors
{
	class behaviors_sample
	{
		icon = "\vbs2\customer\plugins\behaviors_sample\data\behaviors_sample.paa";
		allowRotate = true;


		displayname = "behaviors_sample";
		description = "behaviors_sample";				

		//displayCondition = "\core\addons\plugins\generic_behaviors_public\data\scripts\waypointDisplayCondition.sqf";

		orderName = "behaviors_sample";
		prepareActionMessage = "vbs2\vbs_plugins\ai\standard_behaviors\data\scripts\PrepareBTParameters.sqf";
		
		class RootBehaviors
		{
		  group[] = {"standard_behaviors", "GroupRoot"};
		  entity[] = {"standard_behaviors", "EntityRoot"};
		  vehicle[] = {"standard_behaviors", "VehicleRoot"};
		};
		
		class Parameters
		{
			class orderParameters
			{
				displayName = "orderParameters";
				value = "";
				type = "table";
			};
			class reportCompletedToExternal
			{
				displayName = "reportCompletedToExternal";
				value = "false";
				type = "boolean";
			};
			class debugEnabled
			{
				displayName = "debugEnabled";
				value = "true";
				type = "boolean";
			};
		};
	};
};
