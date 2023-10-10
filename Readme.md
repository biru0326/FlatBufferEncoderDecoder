1. Build FlatBufferEncoder and FlatBufferDecoder in any order and in any mode Debug/Release of x64.
2. Further steps are given to run the command in Release mode.
3. After build is completed execute Encoder first by giving a path where to dump the file like below:
   "%SourceCodeFolder%\FlatBufferEncoder\x64\Release\FlatBufferEncoder.exe" "%SourceCodeFolder%\FlatBufferEncoder\BinaryFile\Data.bin"
   Note : This is just example. You can give your own path where you want to dump the bin file
5. After this, Data.bin will be dumped in the given folder.
6. To Decode, execute the decoder as below: 
   "%SourceCodeFolder%\FlatBufferDecoder\bin\Release\net6.0\FlatBufferDecoder.exe" "%SourceCodeFolder%\FlatBufferEncoder\BinaryFile\Data.bin"
   Note : This is just example. You can give your own path where bin file is located.
8. The Decoded information will be displayed in the console.
