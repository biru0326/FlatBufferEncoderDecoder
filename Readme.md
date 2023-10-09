1. Build FlatBufferEncoder and FlatBufferDecoder in any order and in any mode Debug/Release of x64.
2. Further steps are given to run the command in Release mode.
3. After build is completed execute Encoder first by giving a path where to dump the file like below:
   "C:\FlatBufferAssignment\FlatBufferEncoder\x64\Release\FlatBufferEncoder.exe" "C:\FlatBufferAssignment\FlatBufferEncoder\BinaryFile\Data.bin"
4. After this, Data.bin will be dumped in the given folder.
5. To Decode, execute the decoder as below: 
   "C:\FlatBufferAssignment\FlatBufferEncoder\FlatBufferDecoder\bin\Release\net6.0\FlatBufferDecoder.exe" "C:\FlatBufferAssignment\FlatBufferEncoder\BinaryFile\Data.bin"
6. The Decoded information will be displayed in the console.
