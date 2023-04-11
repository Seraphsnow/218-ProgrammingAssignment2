import sys
import os
import random

original_stdout = sys.stdout

a = 1
b = 10000
for i in range(1000):
    with open('input.txt', 'w') as f:
        sys.stdout = f

        n = random.randint(1,100)
        m = random.randint(1,50)
        print(n)
        print(m)

        for i in range(n):
            for j in range(n):
                print(random.randint(a,b))
        
    sys.stdout = original_stdout

    os.system("./GraphGameDP.out < input.txt > out1.txt")
    os.system("./a.out < input.txt > out2.txt")
    os.system("diff out1.txt out2.txt")