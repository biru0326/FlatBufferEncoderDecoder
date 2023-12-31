// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace PersonGroup
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct Group : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static Group GetRootAsGroup(ByteBuffer _bb) { return GetRootAsGroup(_bb, new Group()); }
  public static Group GetRootAsGroup(ByteBuffer _bb, Group obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public Group __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string Groupname { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetGroupnameBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetGroupnameBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetGroupnameArray() { return __p.__vector_as_array<byte>(4); }
  public float AverageAge { get { int o = __p.__offset(6); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)0.0f; } }
  public float AverageWeight { get { int o = __p.__offset(8); return o != 0 ? __p.bb.GetFloat(o + __p.bb_pos) : (float)0.0f; } }
  public string Names(int j) { int o = __p.__offset(10); return o != 0 ? __p.__string(__p.__vector(o) + j * 4) : null; }
  public int NamesLength { get { int o = __p.__offset(10); return o != 0 ? __p.__vector_len(o) : 0; } }

  public static Offset<PersonGroup.Group> CreateGroup(FlatBufferBuilder builder,
      StringOffset groupnameOffset = default(StringOffset),
      float average_age = 0.0f,
      float average_weight = 0.0f,
      VectorOffset namesOffset = default(VectorOffset)) {
    builder.StartTable(4);
    Group.AddNames(builder, namesOffset);
    Group.AddAverageWeight(builder, average_weight);
    Group.AddAverageAge(builder, average_age);
    Group.AddGroupname(builder, groupnameOffset);
    return Group.EndGroup(builder);
  }

  public static void StartGroup(FlatBufferBuilder builder) { builder.StartTable(4); }
  public static void AddGroupname(FlatBufferBuilder builder, StringOffset groupnameOffset) { builder.AddOffset(0, groupnameOffset.Value, 0); }
  public static void AddAverageAge(FlatBufferBuilder builder, float averageAge) { builder.AddFloat(1, averageAge, 0.0f); }
  public static void AddAverageWeight(FlatBufferBuilder builder, float averageWeight) { builder.AddFloat(2, averageWeight, 0.0f); }
  public static void AddNames(FlatBufferBuilder builder, VectorOffset namesOffset) { builder.AddOffset(3, namesOffset.Value, 0); }
  public static VectorOffset CreateNamesVector(FlatBufferBuilder builder, StringOffset[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static VectorOffset CreateNamesVectorBlock(FlatBufferBuilder builder, StringOffset[] data) { builder.StartVector(4, data.Length, 4); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateNamesVectorBlock(FlatBufferBuilder builder, ArraySegment<StringOffset> data) { builder.StartVector(4, data.Count, 4); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateNamesVectorBlock(FlatBufferBuilder builder, IntPtr dataPtr, int sizeInBytes) { builder.StartVector(1, sizeInBytes, 1); builder.Add<StringOffset>(dataPtr, sizeInBytes); return builder.EndVector(); }
  public static void StartNamesVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static Offset<PersonGroup.Group> EndGroup(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<PersonGroup.Group>(o);
  }
}


static public class GroupVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*Groupname*/, false)
      && verifier.VerifyField(tablePos, 6 /*AverageAge*/, 4 /*float*/, 4, false)
      && verifier.VerifyField(tablePos, 8 /*AverageWeight*/, 4 /*float*/, 4, false)
      && verifier.VerifyVectorOfStrings(tablePos, 10 /*Names*/, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
