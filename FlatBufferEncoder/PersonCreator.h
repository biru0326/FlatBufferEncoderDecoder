#pragma
#include<string>
#include<vector>
#include "flatbuffers/flatbuffers.h"
#include "person_group_generated.h"
#include "Persons.h"

using namespace std;

class PersonCreator
{
public:
	void Create(flatbuffers::FlatBufferBuilder& builder, 
        std::vector<flatbuffers::Offset<PersonGroup::Person>>& o_persons_vector, 
        float& o_averageAge,
        float& o_averageWeight)
	{
        Persons persons;
        persons.AddPerson("Ram", 25, 70.5f, true);
        persons.AddPerson("Shita", 30, 55.5f, false);
        persons.AddPerson("Raghuveer", 40, 85.5f, true);        

        string name;
        int age;
        float weight;
        bool isMale;
        size_t numberOfPersons = persons.GetNumberOfPersons();
        for (size_t i = 0; i < numberOfPersons; ++i)
        {
            persons.GetPersonDetail(i, name, age, weight, isMale);

            o_persons_vector.push_back(
                PersonGroup::CreatePerson(builder,
                    builder.CreateString(name), age, weight, isMale ? 1 : 0));
        }

        o_averageAge = persons.GetAverageAge();
        o_averageWeight = persons.GetAverageWeight();
	}
};