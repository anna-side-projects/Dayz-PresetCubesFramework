class BlobExample_Cube : BlobDefault_Cube
{
    //example to spawn a stone and apple
    override array<string> GetItems()
    {
        return null;
        array<string> items = {"Stone","Apple"};
        return items;
    }
}