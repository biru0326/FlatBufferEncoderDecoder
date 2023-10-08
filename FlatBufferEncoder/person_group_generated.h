// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PERSONGROUP_PERSONGROUP_H_
#define FLATBUFFERS_GENERATED_PERSONGROUP_PERSONGROUP_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

namespace PersonGroup {

struct Person;
struct PersonBuilder;

struct Group;
struct GroupBuilder;

struct Client;
struct ClientBuilder;

struct Root;
struct RootBuilder;

enum Gender : int8_t {
  Gender_Male = 0,
  Gender_Female = 1,
  Gender_MIN = Gender_Male,
  Gender_MAX = Gender_Female
};

inline const Gender (&EnumValuesGender())[2] {
  static const Gender values[] = {
    Gender_Male,
    Gender_Female
  };
  return values;
}

inline const char * const *EnumNamesGender() {
  static const char * const names[3] = {
    "Male",
    "Female",
    nullptr
  };
  return names;
}

inline const char *EnumNameGender(Gender e) {
  if (::flatbuffers::IsOutRange(e, Gender_Male, Gender_Female)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesGender()[index];
}

struct Person FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6,
    VT_WEIGHT = 8,
    VT_GENDER = 10
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  int32_t age() const {
    return GetField<int32_t>(VT_AGE, 0);
  }
  float weight() const {
    return GetField<float>(VT_WEIGHT, 0.0f);
  }
  PersonGroup::Gender gender() const {
    return static_cast<PersonGroup::Gender>(GetField<int8_t>(VT_GENDER, 0));
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_AGE, 4) &&
           VerifyField<float>(verifier, VT_WEIGHT, 4) &&
           VerifyField<int8_t>(verifier, VT_GENDER, 1) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(int32_t age) {
    fbb_.AddElement<int32_t>(Person::VT_AGE, age, 0);
  }
  void add_weight(float weight) {
    fbb_.AddElement<float>(Person::VT_WEIGHT, weight, 0.0f);
  }
  void add_gender(PersonGroup::Gender gender) {
    fbb_.AddElement<int8_t>(Person::VT_GENDER, static_cast<int8_t>(gender), 0);
  }
  explicit PersonBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Person> CreatePerson(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    int32_t age = 0,
    float weight = 0.0f,
    PersonGroup::Gender gender = PersonGroup::Gender_Male) {
  PersonBuilder builder_(_fbb);
  builder_.add_weight(weight);
  builder_.add_age(age);
  builder_.add_name(name);
  builder_.add_gender(gender);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Person> CreatePersonDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t age = 0,
    float weight = 0.0f,
    PersonGroup::Gender gender = PersonGroup::Gender_Male) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return PersonGroup::CreatePerson(
      _fbb,
      name__,
      age,
      weight,
      gender);
}

struct Group FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef GroupBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GROUPNAME = 4,
    VT_AVERAGE_AGE = 6,
    VT_AVERAGE_WEIGHT = 8,
    VT_NAMES = 10
  };
  const ::flatbuffers::String *groupname() const {
    return GetPointer<const ::flatbuffers::String *>(VT_GROUPNAME);
  }
  float average_age() const {
    return GetField<float>(VT_AVERAGE_AGE, 0.0f);
  }
  float average_weight() const {
    return GetField<float>(VT_AVERAGE_WEIGHT, 0.0f);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *names() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_NAMES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GROUPNAME) &&
           verifier.VerifyString(groupname()) &&
           VerifyField<float>(verifier, VT_AVERAGE_AGE, 4) &&
           VerifyField<float>(verifier, VT_AVERAGE_WEIGHT, 4) &&
           VerifyOffset(verifier, VT_NAMES) &&
           verifier.VerifyVector(names()) &&
           verifier.VerifyVectorOfStrings(names()) &&
           verifier.EndTable();
  }
};

struct GroupBuilder {
  typedef Group Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_groupname(::flatbuffers::Offset<::flatbuffers::String> groupname) {
    fbb_.AddOffset(Group::VT_GROUPNAME, groupname);
  }
  void add_average_age(float average_age) {
    fbb_.AddElement<float>(Group::VT_AVERAGE_AGE, average_age, 0.0f);
  }
  void add_average_weight(float average_weight) {
    fbb_.AddElement<float>(Group::VT_AVERAGE_WEIGHT, average_weight, 0.0f);
  }
  void add_names(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names) {
    fbb_.AddOffset(Group::VT_NAMES, names);
  }
  explicit GroupBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Group> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Group>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Group> CreateGroup(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> groupname = 0,
    float average_age = 0.0f,
    float average_weight = 0.0f,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names = 0) {
  GroupBuilder builder_(_fbb);
  builder_.add_names(names);
  builder_.add_average_weight(average_weight);
  builder_.add_average_age(average_age);
  builder_.add_groupname(groupname);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Group> CreateGroupDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *groupname = nullptr,
    float average_age = 0.0f,
    float average_weight = 0.0f,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *names = nullptr) {
  auto groupname__ = groupname ? _fbb.CreateString(groupname) : 0;
  auto names__ = names ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*names) : 0;
  return PersonGroup::CreateGroup(
      _fbb,
      groupname__,
      average_age,
      average_weight,
      names__);
}

struct Client FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ClientBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT_TYPE = 4,
    VT_CLIENT = 6,
    VT_GROUP = 8
  };
  int8_t client_type() const {
    return GetField<int8_t>(VT_CLIENT_TYPE, 0);
  }
  const PersonGroup::Person *client() const {
    return GetPointer<const PersonGroup::Person *>(VT_CLIENT);
  }
  const PersonGroup::Group *group() const {
    return GetPointer<const PersonGroup::Group *>(VT_GROUP);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_CLIENT_TYPE, 1) &&
           VerifyOffset(verifier, VT_CLIENT) &&
           verifier.VerifyTable(client()) &&
           VerifyOffset(verifier, VT_GROUP) &&
           verifier.VerifyTable(group()) &&
           verifier.EndTable();
  }
};

struct ClientBuilder {
  typedef Client Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client_type(int8_t client_type) {
    fbb_.AddElement<int8_t>(Client::VT_CLIENT_TYPE, client_type, 0);
  }
  void add_client(::flatbuffers::Offset<PersonGroup::Person> client) {
    fbb_.AddOffset(Client::VT_CLIENT, client);
  }
  void add_group(::flatbuffers::Offset<PersonGroup::Group> group) {
    fbb_.AddOffset(Client::VT_GROUP, group);
  }
  explicit ClientBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Client> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Client>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Client> CreateClient(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int8_t client_type = 0,
    ::flatbuffers::Offset<PersonGroup::Person> client = 0,
    ::flatbuffers::Offset<PersonGroup::Group> group = 0) {
  ClientBuilder builder_(_fbb);
  builder_.add_group(group);
  builder_.add_client(client);
  builder_.add_client_type(client_type);
  return builder_.Finish();
}

struct Root FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef RootBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CLIENT = 4
  };
  const PersonGroup::Client *client() const {
    return GetPointer<const PersonGroup::Client *>(VT_CLIENT);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CLIENT) &&
           verifier.VerifyTable(client()) &&
           verifier.EndTable();
  }
};

struct RootBuilder {
  typedef Root Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_client(::flatbuffers::Offset<PersonGroup::Client> client) {
    fbb_.AddOffset(Root::VT_CLIENT, client);
  }
  explicit RootBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Root> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Root>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Root> CreateRoot(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<PersonGroup::Client> client = 0) {
  RootBuilder builder_(_fbb);
  builder_.add_client(client);
  return builder_.Finish();
}

inline const PersonGroup::Root *GetRoot(const void *buf) {
  return ::flatbuffers::GetRoot<PersonGroup::Root>(buf);
}

inline const PersonGroup::Root *GetSizePrefixedRoot(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<PersonGroup::Root>(buf);
}

inline bool VerifyRootBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<PersonGroup::Root>(nullptr);
}

inline bool VerifySizePrefixedRootBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<PersonGroup::Root>(nullptr);
}

inline void FinishRootBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<PersonGroup::Root> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedRootBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<PersonGroup::Root> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace PersonGroup

#endif  // FLATBUFFERS_GENERATED_PERSONGROUP_PERSONGROUP_H_
