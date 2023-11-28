# struct
In Python, we don't need to consider about the length of variables.

If we want to send data out by network, we should need to check the length by struct.

`import struct` is necessary for the operations.

## pack (variable -> binary)
* convert integer into binary
```py
# big endian
struct.pack(">I", 1234321)
# little endian
struct.pack("<I", 1234321)
```

## unpack (binary -> variable)
* convert binary into variable
```py
struct.unpack("<I", b'\x01\x00\x00\x00') # 1
struct.unpack(">I", b'\x00\x00\x00\x01') # 1
```

## multiple parsing
* multiple variable
```py
struct.pack('>HHI', 2, 2, 1)
# b'\x00\x02\x00\x02\x00\x00\x00\x01'
struct.unpack('>HHI', b'\x00\x02\x00\x02\x00\x00\x00\x01')
# 2, 2, 1
struct.calcsize(">HHI")
# 8
```
* multiple variable with string
```py
struct.pack('<5sI', b'test1', 1)
struct.unpack('<5sI', b'test1\x01\x00\x00\x00')
```

## format
Refer to [here](https://docs.python.org/3/library/struct.html#format-characters).

| format | C type | Python type | size |
| --- | --- | --- | --- |
| x | pad byte | no value | - |
| c | char | 1 byte | 1 |
| B | unsigned char | 1 byte | 1 |
| h | short | integer | 2 |
| H | unsigned short | integer | 2 |
| i | int | integer | 4 |
| I | unsigned int | integer | 4 |
| s | char[] | bytes | - | - |
