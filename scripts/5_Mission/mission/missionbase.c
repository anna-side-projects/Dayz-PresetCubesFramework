modded class MissionBase
{
	autoptr CF_InputBindings inputBindings;
	string modname;
	string boltInput;
	string itemClass;
	
	override void OnInit()
	{
		super.OnInit();
		boltInput = "UAGrabBolt";
		itemClass="Default_Cube";
		modname = "PresetCubesFramework";
		inputBindings = new CF_InputBindings(this);
		inputBindings.Bind("checkBoltInput", boltInput, true);
		GetRPCManager().AddRPC(modname, "spawnBoltRPC",this, SingleplayerExecutionType.Both);
		Print("Init done");
	}
	
	void checkBoltInput(UAInput uain)
	{
		if(uain.LocalHold() && PlayerBase.Cast(GetGame().GetPlayer()).GetHumanInventory().GetEntityInHands() == NULL && GetGame().GetUIManager().GetMenu() == NULL)
		{
            spawnBolt();
        }
	}
	void spawnBoltRPC(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		Param1<string> data;
		
		if(!ctx.Read(data)) return;
		
		if(type == CallType.Server)
		{
			PlayerBase.Cast(sender.GetPlayer()).GetHumanInventory().CreateInHands(itemClass);
		}
		else
		{
			Print("Bolts called on client not sure how we got here...");
			GetGame().GetPlayer().GetHumanInventory().CreateInHands(itemClass);
		}
	}

    void spawnBolt()
	{
		Print("SPawniung box");
		GetRPCManager().SendRPC(modname, "spawnBoltRPC",new Param1<string>(itemClass));
	}
}