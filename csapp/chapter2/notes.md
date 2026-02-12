# 1. Addressing and Byte Ordering

### Addressing
- int는 4bytes, 0x100 | 0x101 | 0x102 | 0x103 의 주소가 있다면 int x인 경우 &x = 0x100을 가리킨다. 
### Byte Ordering
0x01234567를 기준으로 하면
- Little Endian (INTEL)
    0x100|0x101|0x102|0x103
    ---|---|---|---
    67|45|23|01

- Big Endian (IBM, Oracle)
    0x100|0x101|0x102|0x103
    ---|---|---|---
    01|23|45|67

### Byte Ordering이 쓸모 있어지는 3가지
1. 서로 다른 machine이 network를 통해 통신할 때, 한 machine은 big endian을 쓰고, 다른 machine은 little endian을 사용하면, big endian으로 된 bit 덩어리를 little endian으로 
해석하게 되면 의미가 달라진다. 
2. machine-level program에서 byte sequence를 해석할 때 필요하다. disassembler로 machine code를 사람이 읽을 수 있는 instruction코드로 변환해준다. 이 instruction에서 int data를 표현하는 byte sequence가 존재하는 경우, little인지 아니면 big인지에 따라 해석이 달라진다. 
3. 일반적인 type system을 우회하는 프로그램이 있는 경우, little인지 big인지에 따라 사람한테 보여지는 byte order가 달라진다. /system_study/csapp/experiments/print_bytes.c 참고. print_bytes.c에서 unsigned char * 타입을 이용하여 1byte씩 데이터를 읽어서 화면에 출력해주는 프로그램이다. 현재 나의 노트북은 INTEL processor를 사용하고 있기 때문에 little endian으로 출력이 된다. 일반적인 type system을 우회한다는 의미는 int, float, int *등 다양한 type들이 존재하지만 print_bytes함수를 호출할 때, 먼저 void *로 변환하고 unsigned char *로 변환해서 1byte씩 읽어오는데 casting을 이용해서 일반적인 type system을 우회하고 있다. 

# 2. Representing Strings
### string에서의 byte ordering과 '\0'문자
- 