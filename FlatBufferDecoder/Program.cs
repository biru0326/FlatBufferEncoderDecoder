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

        if (root.ClientType == Client.Person) 
        {
            Person person = root.ClientAsPerson();
            Console.WriteLine($"Name: {person.Name}, Age: {person.Age}, Weight: {person.Weight}, Gender: {person.Gender}");
        } 
        else if (root.ClientType == Client.Group)
         {
            Group group = root.ClientAsGroup();

            Console.WriteLine($"Group Name: {group.Groupname}, Average Age: {group.AverageAge}, Average Weight: {group.AverageWeight}");
            Console.Write("Names: ");
            for (int i = 0; i < group.NamesLength; ++i)
            {
                Console.Write($"{group.Names(i)}, ");
            }
        } 

        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
    }
}
