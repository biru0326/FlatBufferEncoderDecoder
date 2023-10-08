#pragma
#include<string>
#include<vector>

using namespace std;

class Person
{
public:
	Person(const string& i_name, const int& i_age, const float& i_weight, const bool& i_isMale) :
		name(i_name), age(i_age), weight(i_weight), isMale(i_isMale)
	{

	}
	void GetPersonDetail(string& o_name, int& o_age, float& o_weight, bool& o_isMale)const
	{
		o_name = name;
		o_age = age;
		o_weight = weight;
		o_isMale = isMale;
	}

private:
	string name;
	int age;
	float weight;
	bool isMale;
};

class Persons
{
public:
	void AddPerson(const string& i_name, const int& i_age, const float& i_weight, const bool& i_isMale)
	{
		total_age += i_age;
		total_weight += i_weight;
		vtPersons.push_back(Person(i_name, i_age, i_weight, i_isMale));
	}

	size_t GetNumberOfPersons()const
	{
		return vtPersons.size();
	}

	void GetPersonDetail(size_t i_index, string& o_name, int& o_age, float& o_weight, bool& o_isMale)const
	{
		if(i_index < 0 || i_index >= vtPersons.size())
			throw std::out_of_range("Index out of bounds");
		vtPersons[i_index].GetPersonDetail(o_name, o_age, o_weight, o_isMale);
	}

	float GetAverageAge()const
	{
		if (vtPersons.size() == 0)
			return 0.0f;

		return total_age/(1.0f*vtPersons.size());
	}

	float GetAverageWeight()const
	{
		if (vtPersons.size() == 0)
			return 0.0f;

		return total_weight / (1.0f*vtPersons.size());
	}

private:
	vector<Person> vtPersons;
	int total_age = 0;
	float total_weight = 0.0;
};