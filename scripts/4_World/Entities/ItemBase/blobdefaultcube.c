class BlobDefault_Cube : Inventory_Base
{
    static string modname = "PresetCubesFramework";
    void BlobDefault_Cube() 
    {
        GetRPCManager().AddRPC(modname, "OpenCubeRPC",this, SingleplayerExecutionType.Both);
    }

    void OpenCubeRPC(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		Param1<string> data;
        PlayerBase player;
		
		if(!ctx.Read(data)) return;
		
		if(type == CallType.Server)
		{
			player = PlayerBase.Cast(sender.GetPlayer());
            SpawnItems(player);
		}
		else
		{
            player = GetGame().GetPlayer();
            SpawnItems(player);
		}
	}

    void Open()
    {
        GetRPCManager().SendRPC(modname, "OpenCubeRPC",new Param1<string>("idk"));
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionUnpackCube);
    }
    void SpawnItems(PlayerBase player)
    {
        array<string> items = sort(GetItems());

        //todo spawn items in inventory or on ground if they can't FindInventoryLocationType
		vector location = player.GetLocalPosition();
		HumanInventory inventory = player.GetHumanInventory();
		foreach(string item: items)
		{   
			SpawnInInventoryOrGroundPos(item, inventory, location);
		}
    }
    array<string> sort(array<string> items) 
	{
        //todo sort so weapons and clothing is equipped first and regular items are deposited into or at feet or don't idc at this point I'd rather just get it done
		return items;
                
    }
    array<string> GetItems()
    {
        return null;
    }
};