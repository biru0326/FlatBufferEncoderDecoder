// FlatBufferEncoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma
#include <fstream>
#include "flatbuffers/flatbuffers.h"
#include "person_group_generated.h"
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

    if (std::filesystem::exists(binFilePath)) {
        std::filesystem::remove(binFilePath);
    }

    flatbuffers::FlatBufferBuilder builder;

    //Create person
    auto person = PersonGroup::CreatePerson(builder, builder.CreateString("Ram"), 21, 76.5, PersonGroup::Gender::Gender_Male);

    //create group
    flatbuffers::Offset<flatbuffers::String> ram = builder.CreateString("Ram");
    flatbuffers::Offset<flatbuffers::String> shayam = builder.CreateString("Shayam");
    flatbuffers::Offset<flatbuffers::String> raghuveer = builder.CreateString("Raghuveer");
    auto names_vector = builder.CreateVector({ ram, shayam, raghuveer });
    auto group = PersonGroup::CreateGroup(builder, builder.CreateString("FightClub"), 24.5, 66, names_vector);

    //create root
    auto root = PersonGroup::CreateRoot(builder, PersonGroup::Client_Group, group.Union());

    //finish
    builder.Finish(root);

    //write to file
    std::ofstream outfile(binFilePath, std::ofstream::binary);
    outfile.write(reinterpret_cast<const char*>(builder.GetBufferPointer()), builder.GetSize());

    return 0;
}
