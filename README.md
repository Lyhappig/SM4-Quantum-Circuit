# SM4-Quantum-Circuit

## Sbox

quantum_circ1 ~ quantum_circ7 表示本文提出的7种S盒量子电路，测试时只需要替换 `~/sbox/main.cpp` 中的命名空间及执行函数名的数字

## sm4

sm4_qt_circ1 表示使用260个量子比特的SM4量子电路

sm4_qt_circ6 表示使用632个量子比特的SM4量子电路，代码使用多线程模拟8个S盒的并行，注意在Linux下编译时需要带上 `-pthread`