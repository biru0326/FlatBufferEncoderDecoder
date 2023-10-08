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
        ByteBuffer byteBuffer = new ByteBuffer(buffer);

        Group group = Group.GetRootAsGroup(byteBuffer);

        string groupName = group.Groupname;
        float averageAge = group.AverageAge;
        float averageWeight = group.AverageWeight;

        Console.WriteLine($"Group Name: {groupName}");
        Console.WriteLine($"Average Age: {averageAge}");
        Console.WriteLine($"Average Weight: {averageWeight}");

        var persons = new Person[group.PersonsLength];
        for (int i = 0; i < group.PersonsLength; i++)
        {
            persons[i] = group.Persons(i).Value;
            string personName = persons[i].Name;
            int age = persons[i].Age;
            float weight = persons[i].Weight;
            string gender = ConvertSByteToGender(persons[i].Gender);

            Console.WriteLine($"Person {i + 1} - Name: {personName}, Age: {age}, Weight: {weight}, Gender: {gender}");
        }

        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
    }

    static string ConvertSByteToGender(sbyte value)
    {
        if (value == 1)
        {
            return "Male";
        }
        else if (value == 0)
        {
            return "Female";
        }
        else
        {
            return "Unknown";
        }
    }
}
