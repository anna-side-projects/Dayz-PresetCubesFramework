class BlobDefault_Cube : ItemBase
{
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
			//may need rpc
			SpawnInInventoryOrGroundPos(item, inventory, location);
		}
    }
    array<string> sort(array<string> items) 
	{
        //todo sort so weapons and clothing is equipped first and regular items are deposited into or at feet or don't idc at this point I'd rather just get it done
		return items;
                
    }
	//Todo make it return nothing for default after testing is done
    array<string> GetItems()
    {
        return null;
    }
};