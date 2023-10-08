// FlatBufferAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma
#include <iostream>
#include <fstream>
#include <vector>
#include "PersonCreator.h"
#include <filesystem>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        return 1;
    }
    std::filesystem::path binFilePath(argv[1]);
    if (!std::filesystem::exists(binFilePath.parent_path())) {
        return 1;
    }

    flatbuffers::FlatBufferBuilder builder;
    std::vector<flatbuffers::Offset<PersonGroup::Person>> persons_vector;
    float averageWeight, averageAge;

    PersonCreator creator;
    creator.Create(builder, persons_vector, averageAge, averageWeight);
    auto group = CreateGroup(builder, builder.CreateString("GroupOfPersons"), averageAge, averageWeight, builder.CreateVector(persons_vector));
    builder.Finish(group);

    // Serialize to binary
    const uint8_t* buf = builder.GetBufferPointer();
    const size_t size = builder.GetSize();

    // Save to file
    std::ofstream outfile(binFilePath, std::ios::binary);
    outfile.write(reinterpret_cast<const char*>(buf), size);
    outfile.close();

    return 0;
}
