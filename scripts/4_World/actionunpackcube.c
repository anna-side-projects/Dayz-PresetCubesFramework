class ActionUnpackCubeCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.UNPACK);
	}
};

class ActionUnpackCube : ActionContinuousBase
{
    void ActionUnpackCube()
	{
		m_CallbackClass = ActionUnpackCubeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		//m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_Text = "OpenCube";
        Print("Created cube action");
	}
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()	
	{
		return false;
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}
	
	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		return true;
	}
    override void OnFinishProgressServer( ActionData action_data )
    {
        PlayerBase player = action_data.m_Player;
		ItemBase item = action_data.m_MainItem;
		DoOpen(item);
		
    }
	override void OnFinishProgress( ActionData action_data )
	{	
		PlayerBase player = action_data.m_Player;
		ItemBase item = action_data.m_MainItem;
		DoOpen(item);
	}
	void DoOpen(ItemBase item)
	{
		if(BlobDefault_Cube.Cast(item))
		{
			BlobDefault_Cube cube = BlobDefault_Cube.Cast(item);
			cube.Open()
			cube.DeleteSafe();
		}
	}
};