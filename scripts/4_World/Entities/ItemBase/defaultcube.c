class Default_Cube : ItemBase
{
    override void SetActions()
    {
        Print("Setting cube actions");
        super.SetActions();
        AddAction(ActionUnpackCube);
    }
    void SpawnItems(PlayerBase player)
    {
        ItemBase items[] = sort(GetItems());

        //todo spawn items in inventory or on ground if they can't fit
    }
    String[] sort(String[] items) {
        //todo sort so weapons and clothing is equipped first and regular items are deposited into or at feet
        ItemBase[] sorted[items.length];


        if(!items)
            return null;
        
                
    }
    String[] GetItems()
    {
        //Todo make it return nothing for default
        // return null;
        ItemBase items[] = {
            "Stone",
            "Apple"
        };
        return items;
    }
    
};