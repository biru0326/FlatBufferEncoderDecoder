using Google.FlatBuffers;
using PersonGroup;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length != 1)
        {
            Console.WriteLine("wrong input");
            return;
        }
        string binFilePath = args[0];
        if (!File.Exists(binFilePath))
        {
            Console.WriteLine("bin file do not exists");
            return;
        }
        if (!binFilePath.EndsWith(".bin", StringComparison.OrdinalIgnoreCase))
        {
            Console.WriteLine("it is not a bin file");
            return;
        }

        byte[] buffer = File.ReadAllBytes(binFilePath);
        var byteBuffer = new ByteBuffer(buffer);
        var root = Root.GetRootAsRoot(byteBuffer);
        var client = root.Client;

        if (client!.Value!.ClientType == 0) 
        {
            Person? person = client.Value.Client_;
            Console.WriteLine($"Name: {person.Value.Name}, Age: {person.Value.Age}, Weight: {person.Value.Weight}, Gender: {person.Value.Gender}");
        } 
        else if (client!.Value!.ClientType == 1) 
        {
            Group? group = client.Value.Group;

            Console.WriteLine($"Group Name: {group.Value.Groupname}, Average Age: {group.Value.AverageAge}, Average Weight: {group.Value.AverageWeight}");
            Console.Write("Names: ");
            for (int i = 0; i < group.Value.NamesLength;++i)
            {
                Console.Write($"{group.Value.Names(i)}, ");
            }
        } 

        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
    }
}
