class BlobExample_Cube : BlobDefault_Cube
{
    //example to spawn a stone and apple
    override array<string> GetItems()
    {
        array<string> items = {"Stone","Apple", "Stone","Stone","Stone","Stone","Stone","Stone","Stone","Stone"};
        return items;
    }
}