// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace PersonGroup
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct Person : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static Person GetRootAsPerson(ByteBuffer _bb) { return GetRootAsPerson(_bb, new Person()); }
  public static Person GetRootAsPerson(ByteBuffer _bb, Person obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public Person __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Name { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetNameBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetNameBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetNameArray() { return __p.__vector_as_array<byte>(4); }
  public int Age { get { int o = __p.__offset(6); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }
  public float Weight { get { int o = __p.__offset(8); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)0.0f; } }
  public PersonGroup.Gender Gender { get { int o = __p.__offset(10); return o != 0 ? (PersonGroup.Gender)__p.bb.GetSbyte(o + __p.bb_pos) : PersonGroup.Gender.Male; } }

  public static Offset<PersonGroup.Person> CreatePerson(FlatBufferBuilder builder,
      StringOffset nameOffset = default(StringOffset),
      int age = 0,
      float weight = 0.0f,
      PersonGroup.Gender gender = PersonGroup.Gender.Male) {
    builder.StartTable(4);
    Person.AddWeight(builder, weight);
    Person.AddAge(builder, age);
    Person.AddName(builder, nameOffset);
    Person.AddGender(builder, gender);
    return Person.EndPerson(builder);
  }

  public static void StartPerson(FlatBufferBuilder builder) { builder.StartTable(4); }
  public static void AddName(FlatBufferBuilder builder, StringOffset nameOffset) { builder.AddOffset(0, nameOffset.Value, 0); }
  public static void AddAge(FlatBufferBuilder builder, int age) { builder.AddInt(1, age, 0); }
  public static void AddWeight(FlatBufferBuilder builder, float weight) { builder.AddFloat(2, weight, 0.0f); }
  public static void AddGender(FlatBufferBuilder builder, PersonGroup.Gender gender) { builder.AddSbyte(3, (sbyte)gender, 0); }
  public static Offset<PersonGroup.Person> EndPerson(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<PersonGroup.Person>(o);
  }
}


static public class PersonVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*Name*/, false)
      && verifier.VerifyField(tablePos, 6 /*Age*/, 4 /*int*/, 4, false)
      && verifier.VerifyField(tablePos, 8 /*Weight*/, 4 /*float*/, 4, false)
      && verifier.VerifyField(tablePos, 10 /*Gender*/, 1 /*PersonGroup.Gender*/, 1, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
