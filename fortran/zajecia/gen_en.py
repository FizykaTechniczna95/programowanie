#!/usr/bin/env python3

import random, sys

with open("{}".format(sys.argv[1]),'w') as file:
    for i in range(int(sys.argv[2])):
        file.write(str(random.uniform(0,0.01)))
        file.write('\n')



